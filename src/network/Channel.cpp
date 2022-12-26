#include "../../include/network/Channel.hpp"

Channel::Channel() : _name(""), _participants(0), _chnlPass("") { memset(_participantsFd, 0, sizeof(_participantsFd)); }

Channel::Channel(std::string name): _name(name), _participants(0), _chnlPass("") { memset(_participantsFd, 0, sizeof(_participantsFd)); }

Channel::~Channel() {}

void    Channel::setParticipants(size_t num, int fd) { _participantsFd[_participants] = fd; _participants += num;}

void	Channel::setPass(std::string pass) { _chnlPass = pass; }

size_t	Channel::getParticipants() { return _participants; }

std::string Channel::getName() { return _name; }

std::string Channel::getPass() { return _chnlPass; }