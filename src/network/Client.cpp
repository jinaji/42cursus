#include "../../include/network/Client.hpp"

Client::Client(int fd)
{
    _fd = fd;
}

Client::~Client() {}

int Client::getSocket() { return _fd; }

void Client::setPass(std::string pass) { _pass = pass; }