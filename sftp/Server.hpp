#ifndef Server_hpp
#define Server_hpp

#include <iostream>

class Server
{
private:
    // Host variable passed in from cli
    std::string host;
    // Port variable passed in from cli
    int port;


public:
    // Default constructor
    Server();

    // Getters
    std::string GetHost();
    int GetPort();
    
    // Setters
    void SetHost(std::string host);
    void SetPort(int port);
};

#endif
