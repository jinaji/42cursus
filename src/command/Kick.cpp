#include "../../include/command/Command.hpp"

// :WiZ!jto@tolsun.oulu.fi KICK #Finnish John

// You have been kicked out of the channel <- 쫓겨난 사람 이거 받아야됨

// gyum has kicked jina () <- 다 받는 메세지 

void Command::kickMessage(std::string name, std::string user)
{

    Channel tmp;
    std::list<Channel>::iterator its = _server.getChannel().begin();
	for (; its != _server.getChannel().end(); its++)
	{
		if (name == (*its).getName())
		{
			tmp = (*its);
			break ;
		}
	}
	std::map<int, std::string>::iterator it = tmp.getParticipantsFd().begin();

	for (size_t i = 0; i < tmp.getParticipantsSize(); i++, it++)
	{
        std::string print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " KICK " + name + " " + user;
        // print += tmp.getParticipantsKey(it);
        print += "\r\n";
		std::cout << "print[" << print << "]";
		if (_caller.getSocket() == tmp.getParticipantsKey(it))
        {
            (*its).getParticipantsFd().erase(_caller.getSocket());
			continue ;
        }
		if (send(tmp.getParticipantsKey(it), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러");
		if (tmp.getParticipantsKey(it) == _server.getFdmax())
			this->Numerics(401);

	}


    // if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
        // throw std::runtime_error("send 에러1");
}

void Command::Kick() // <channel> <user> * [<comment>]
{
    std::string userName = _parsingPara[1];
	size_t nameStart = 0;
	size_t namePos = userName.find(',');

	while (namePos != std::string::npos)
	{
		userName = _parsingPara[1].substr(nameStart, namePos - nameStart);
		nameStart = namePos + 1;
		namePos = _parsingPara[1].find(',', nameStart);

        this->kickMessage(_parsingPara[0], userName);
        
    }
    userName = _parsingPara[1].substr(nameStart, namePos - nameStart);
    this->kickMessage(_parsingPara[0], userName);

}

// KICK #채널 유저