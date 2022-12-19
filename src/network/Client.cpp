#include "../../include/network/Client.hpp"

Client::Client(int fd)
{
    _fd = fd;
}

Client::~Client() {}
