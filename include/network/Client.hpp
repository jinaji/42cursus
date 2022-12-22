#ifndef CLIENT_HPP
# define CLIENT_HPP

# include <string>
# include <list>
# include "./Channel.hpp"

class Client
{
    private:
    int _fd;
    std::string _nick;
    std::string _user;
    std::string _real;
    std::string _pass;

    std::list<Channel>		_channelList;
    
    //PASS
    bool _passState;

    public:
        Client(int fd);
        ~Client();

        int getSocket();
        bool getpassState();

        void addChannel(Channel chnl);

        void setpassState(bool state);
        void setNick(std::string nick);
        void setUser(std::string user);
        void setReal(std::string _parsingPara[9], size_t _paraNum);
        std::string getUser();
        std::string getReal();
};

#endif