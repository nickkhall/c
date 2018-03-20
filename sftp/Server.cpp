#include <sys/socket.h>
// #include <netdb.h>
// #include <arpa/inet.h>

#include "Server.hpp"

Server::Server()
{

}

void Server::SetHost(std::string hostParam)
{
	host = hostParam;
	return;
}

std::string Server::GetHost()
{
	return host;
}

void Server::SetPort(int portParam)
{
	port = portParam;
	return;
}

int Server::GetPort()
{
	return port;
}
