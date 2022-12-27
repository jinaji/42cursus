#include "../../include/network/Client.hpp"

Client::Client(int fd): _fd(fd), _passState(false), _nickState(false), _userState(false), _accessState(false), _servOper(false)
{
    for (int i = 0; i < 7; i++)
        _userMode[i] = false;
}

Client::~Client() {}

void Client::addChannel(Channel chnl)
{
    chnl.setParticipants(1, _fd);
    _channelList.push_back(chnl);
}

int Client::getSocket() { return _fd; }
std::string Client::getNick() { return _nick; }
std::string Client::getUser() { return _user; }
std::string Client::getReal() { return _real; }
bool Client::getpassState() { return _passState; }
bool Client::getnickState() { return _nickState; }
bool Client::getuserState() { return _userState; }
bool Client::getaccessState() { return _accessState; }
bool Client::getservOper() { return _servOper; }

void Client::setpassState(bool state) { _passState = state; }
void Client::setnickState(bool state) { _nickState = state; }
void Client::setuserState(bool state) { _userState = state; }
void Client::setaccessState(bool state) { _accessState = state; }
void Client::setservOper(bool state) { _servOper = state; }
void Client::setNick(std::string nick) { _nick = nick; }
void Client::setUser(std::string user) { _user = user; }
void Client::setReal(std::string parsingPara[9], size_t paraNum) { _real = std::string(); for (size_t i = 3; i < paraNum; i++) _real.append(parsingPara[i]) += " "; }
std::list<Channel> &Client::getChannel() { return (_channelList);};