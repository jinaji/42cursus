#include "../../include/network/Channel.hpp"

Channel::Channel(std::string name): _name(name), _participants(0) {}

Channel::~Channel() {}

void    Channel::setParticipants(size_t num) { _participants += num; }

std::string Channel::getName() { return _name; }