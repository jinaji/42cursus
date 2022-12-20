#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>

class Client
{
    private:
    int _fd;
    std::string _nick;
    std::string _user;
    std::string _real;
    std::string _pass;

    public:
        Client(int fd);
        ~Client();

        int getSocket();
        
        void setPass(std::string pass);
};

#endif