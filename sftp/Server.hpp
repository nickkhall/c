#ifndef Server_hpp
#define Server_hpp

#include <iostream>

class Server
{
private:
    std::string host;
    int port;

public:
    Server();
    void SetHost();
    std::string GetHost();
};

#endif
