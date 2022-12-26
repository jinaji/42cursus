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
    bool _nickState;
    bool _userState;
    bool _accessState;	// PASS, NICK, USER 완료 플래그

    public:
        Client(int fd);
        ~Client();

        int getSocket();
        std::string getNick();
        bool getpassState();
        bool getnickState();
        bool getuserState();
        bool getaccessState();

        void addChannel(Channel chnl);

        void setpassState(bool state);
        void setnickState(bool state);
        void setuserState(bool state);
        void setaccessState(bool state);
        void setNick(std::string nick);
        void setUser(std::string user);
        void setReal(std::string _parsingPara[9], size_t _paraNum);
        std::string getUser();
        std::string getReal();

        std::list<Channel> &getChannel();
};

#endif