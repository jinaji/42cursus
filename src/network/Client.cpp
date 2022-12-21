#include "../../include/network/Client.hpp"

Client::Client(int fd): _passState(false)
{
    _fd = fd;
}

Client::~Client() {}

void Client::addChannel(Channel chnl)
{
    chnl.setParticipants(1);
    _channelList.push_back(chnl);
}

int Client::getSocket() { return _fd; }
bool Client::getpassState() { return _passState; }

void Client::setpassState(bool state) { _passState = state; }
void Client::setNick(std::string nick) { _nick = nick; }