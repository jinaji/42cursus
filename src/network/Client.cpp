#include "../../include/network/Client.hpp"

Client::Client(int fd): _passState(false)
{
    _fd = fd;
}

Client::~Client() {}

void Client::addChannel(Channel chnl)
{
    chnl.setParticipants(1, _fd);
    _channelList.push_back(chnl);
}

int Client::getSocket() { return _fd; }
std::string Client::getNick() { return _nick; }
bool Client::getpassState() { return _passState; }

void Client::setpassState(bool state) { _passState = state; }
void Client::setNick(std::string nick) { _nick = nick; }
void Client::setUser(std::string user) { _user = user; }
void Client::setReal(std::string parsingPara[9], size_t paraNum) { _real = std::string(); for (size_t i = 3; i < paraNum; i++) _real.append(parsingPara[i]) += " "; }
std::string Client::getUser() { return (_user); }
std::string Client::getReal() { return (_real); }
std::list<Channel> &Client::getChannel() { return (_channelList);};