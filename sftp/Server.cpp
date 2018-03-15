#include <sys/socket.h>
// #include <netdb.h>
// #include <arpa/inet.h>

#include "Server.hpp"

void Server::SetHost()
{
    host = "127.0.0.0";
    return;
}

std::string Server::GetHost()
{
    return host;
}
