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
#define SERVER_PORT 5555

/*
FILE DESCRIPTOR:
  In Unix and related computer operating systems, a file descriptor (FD, less frequently fildes)
    is an abstract indicator (handle) used to access a file or other input/output resource, such as a pipe or network socket.
    File descriptors form part of the POSIX application programming interface.
*/

// Exit Client
void exit_client(int file_descriptor, fd_set *read_fd_set, char fd_array[], int *num_clients) {
  int i;
  close(file_descriptor);                 // Closes a file descriptor, so that it no longer refers to any file
  FD_CLR(file_descriptor, read_fd_set);   // Clears the leaving client from the set

  for (i = 0; i < (*num_clients) - 1; i++)
        if (fd_array[i] == file_descriptor)
        break;
  for (; i < (*num_clients) - 1; i++)
      (fd_array[i]) = (fd_array[i + 1]);
      (*num_clients)--;
}

int main(int argc, char *argv[]) {
  int i = 0;
  int count = 0;
  char pass[1];
  int port, result;
  int num_clients = 0;
  int server_socket_file_descriptor, client_socket_file_descriptor;
  struct sockaddr_in server_address;
  int addresslen = sizeof(struct sockaddr_in);
  int fd;
  char fd_array[MAX_CLIENTS];
  fd_set readfds, testfds, clientfds;
  char msg[MESSAGE_SIZE];
  char kb_msg[MESSAGE_SIZE + 10];

  // Server
  // Check passed in arguments for port
  if (argc == 1 || argc == 3) {
    if (argc == 3) {
        if (!strcmp("-p", argv[1])) {
          sscanf(argv[2], "%i", &port);
        }
        else {
          printf("Invalid parameter.\nUsage: chat [-p PORT] HOSTNAME\n");
          exit(0);
        }
    }
    else
        // If port not specified, set to declared port number (SERVER_PORT)
        port = SERVER_PORT;


  printf("\n\t******************** ABotC Server ********************\n");
  printf("\n\nWhat's the password pussy: ");

	// Grab user password from input and check if it's a string
  scanf("%s", &pass);

	// Compare user entered password
  if (strcmp(pass, "temppassword") != 0) {
      printf("\n\nAuthentication failure.\n\n " );
      exit(0);
  }

	// After password is authenticated
  printf("\n*** Server waiting (enter \"quit\" to stop): *** \n");

	// Clear (or flush) the output buffer and move the buffered data to console
  fflush(stdout);

  // Create and name a socket for the server
	// Create socket obj
  server_socket_file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
	// Set socket obj family
  server_address.sin_family = AF_INET;
	// htonl - converts the unsigned integer hostlong from host byte order to network byte order.
  server_address.sin_addr.s_addr = htonl(INADDR_ANY);
  server_address.sin_port = htons(port);
  bind(server_socket_file_descriptor, (struct sockaddr *)&server_address, addresslen);

  // Create a connection queue and initialize a file descriptor set
  listen(server_socket_file_descriptor, 1);

	// Initializes the file descriptor set fdset to have zero bits for all file descriptors.
  FD_ZERO(&readfds);
	// Sets the bit for the file descriptor fd in the file descriptor set fdset.
  FD_SET(server_socket_file_descriptor, &readfds);
	// Add keyboard to file descriptor set
  FD_SET(0, &readfds);

  // Now wait for clients and requests
  while (1) {
      testfds = readfds;
      select(FD_SETSIZE, &testfds, NULL, NULL, NULL);

      // If there is activity, find which descriptor it's on using FD_ISSET
      for (fd = 0; fd < FD_SETSIZE; fd++) {
          if (FD_ISSET(fd, &testfds)) {
              if (fd == server_socket_file_descriptor) {
									// Accept a new connection request
                  client_socket_file_descriptor = accept(server_socket_file_descriptor, NULL, NULL);

                  if (num_clients < MAX_CLIENTS) {
                      FD_SET(client_socket_file_descriptor, &readfds);
                      fd_array[num_clients] = client_socket_file_descriptor;

                      /*Client ID*/

                      printf("\n -> Bot No. %d standby for orders\n", ++num_clients);
                      printf("\n>> ");
                      fflush(stdout);
                      send(client_socket_file_descriptor,msg,strlen(msg),0);
                  }
                  else{
                      sprintf(msg, "Sorry, too many clients.  Try again later.\n");
                      write(client_socket_file_descriptor, msg, strlen(msg));
                      close(client_socket_file_descriptor);
                  }
              }
              else
                  if (fd == 0) {
                      printf(" >> ");
											// Process keyboard activity
                      fgets(kb_msg, MESSAGE_SIZE + 1, stdin);
                      if (strcmp(kb_msg, "quit\n") == 0) {
                          sprintf(msg, "Shutting down ABotC Server...\n");
                          for (i = 0; i < num_clients; i++) {
                              write(fd_array[i], msg, strlen(msg));
                              close(fd_array[i]);
                          }
                          close(server_socket_file_descriptor);
                          exit(0);
                      }
                      else{
                          sprintf(msg, "%s", kb_msg);
                          for (i = 0; i < num_clients; i++)
                              write(fd_array[i], msg, strlen(msg));
                      }
                  }
                  else
                      if (fd) {
                          result = read(fd, msg, MESSAGE_SIZE);
													// Read data from open socket
                          if (result == -1)
                              perror("read()");
                          else
                              if (result > 0) {
                                  sprintf(kb_msg,"MClient CID %2d",fd);
																	// Read 2 bytes client id
                                  msg[result] = '\0';

															// Concatinate the client id with the client's message
                              strcat(kb_msg," ");
                              strcat(kb_msg,msg+1);

															// Print to other clients
                              for(i = 0; i < num_clients; i++) {
                                  if (fd_array[i] != fd)
																		// Do not write msg to same client
                                    write(fd_array[i],kb_msg,strlen(kb_msg));
                              }

															// Print to server
                              printf("%s",kb_msg+1);

															// Exit Client
                              if (msg[0] == 'X') {
                                  exit_client(fd,&readfds, fd_array,&num_clients);
                              }
                          }
                      }
                      else{
												// A client is leaving
                        exit_client(fd,&readfds, fd_array,&num_clients);
                      }
          }
      }
  }}
}
