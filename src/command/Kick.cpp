#include "../../include/command/Command.hpp"

// :WiZ!jto@tolsun.oulu.fi KICK #Finnish John

// You have been kicked out of the channel <- 쫓겨난 사람 이거 받아야됨

// gyum has kicked jina () <- 다 받는 메세지 

void Command::kickMessage(std::string name, std::string user)
{
	std::string print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " KICK " + name + " " + user;
	print += "\r\n";
	if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
        throw std::runtime_error("send 에러1");

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
	// std::cout << "size: " << tmp.getParticipantsSize() << std::endl;
	for (; it != tmp.getParticipantsFd().end(); it++)
	{
		if (tmp.getParticipantsFd().end() != it && tmp.getParticipantsKey(it) != _caller.getSocket())
		{
			print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " KICK " + name + " " + user + "\r\n";
			if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       			throw std::runtime_error("send 에러2");
		}
	}
}

void Command::Kick() // <channel> <user> * [<comment>]
{
    std::string userName = _parsingPara[1];
	size_t nameStart = 0;
	size_t namePos = userName.find(',');

	if (this->checkChannel_server(_parsingPara[0]) == false)
	{
		this->Numerics(403, _parsingPara[0]);
		return ;
	}
	std::list<Channel>::iterator it = _server.getChannel().begin();
	for (; it != _server.getChannel().end(); it++)
	{
		if (checkChannel_caller(_parsingPara[0]) == true && _caller.getNick() == (*it).getOper())
		{
			userName = parseComma(_parsingPara[1], nameStart, namePos);
			this->kickMessage(_parsingPara[0], userName);			// server channel update
			break ;
		}
		else
		{
			this->Numerics(482, _parsingPara[0]);
			return ;
		}
	}

	// while (namePos != std::string::npos)
	// {
	// 	userName = parseComma(_parsingPara[1], nameStart, namePos);
    //     this->kickMessage(_parsingPara[0], userName);
    // }

}

// KICK #채널 유저