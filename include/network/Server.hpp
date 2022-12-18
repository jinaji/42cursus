#ifndef SERVER_HPP
# define SERVER_HPP

# include <string>

// 임시
#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <poll.h>
#include <vector>
//

class Server
{
    private:
        // int         _socket;
        std::string _port;
        std::string _pass;
        
    public:
        Server(const std::string port, const std::string pass);
        ~Server();
        
        void    test();
        void    loop();
        std::string    getPort();
        std::string    getPass();
};

#endif