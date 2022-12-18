#ifndef SERVER_HPP
# define SERVER_HPP

# include <string>

// 임시
#include <iostream>
#include <algorithm>
#include <sys/poll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <vector>
#include <map>
#include <poll.h>
#include <unistd.h>
#include <sys/time.h>
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