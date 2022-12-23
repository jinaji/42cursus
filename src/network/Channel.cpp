#include "../../include/network/Channel.hpp"

Channel::Channel(std::string name): _name(name), _participants(0) { memset(_participantsFd, 0, sizeof(_participantsFd)); }

Channel::~Channel() {}

void    Channel::setParticipants(size_t num, int fd) { _participantsFd[_participants] = fd; _participants += num;}

std::string Channel::getName() { return _name; }