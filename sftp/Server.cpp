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
