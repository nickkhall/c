#include <iostream>
#include <string>
#include "Server.hpp"

int main(int argc, const char *argv[]) {
    Server server;

    if (!argv[1] || !argv[2])
    {
        std::cout << "------------------------------------" << std::endl;
        std::cout << "Please enter a host and port number" << std::endl;
        std::cout << "------------------------------------" << std::endl;
        std::cout << "USAGE: ./Server 127.0.0.1 1234" << std::endl;
        return 0;
    }

    server.SetHost(argv[1]);
    server.SetPort(atoi(argv[2]));

    return 0;
}
