#include "../../include/command/Command.hpp"

void Command::Invite()
{
	std::string target = _parsingPara[0];
	std::string chnlName = _parsingPara[1];

	if (_paraNum != 2)
	{
		this->Numerics(461);
		return ;
	}
	if (checkChannel_server(chnlName) == false)
	{
		this->Numerics(403);
		return ;
	}
	if (checkChannel_caller(chnlName) == false)
	{
		this->Numerics(442);
		return ;
	}
	if (checkChannel_nick(target) == true)
	{
		this->Numerics(443);
		return ;
	}

	int fd = -1;
	int flag = 0;
	std::list<Client *>::iterator it = _server.getClient().begin();
	for (; it != _server.getClient().end(); it++)
	{
		if ((*it)->getNick() == target)
		{
			fd = (*it)->getSocket();
			flag = 1;
			break ;
		}
	}
	if (flag == 0 || fd == -1)
	{
		this->Numerics(403);
		return ;
	}
	else
	{
		std::string print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " INVITE " + target + " " + chnlName;
		print += "\r\n";
		if (send(fd, print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러");
		print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1 341 " + _caller.getNick() + " " + target + " " + chnlName;
		print += "\r\n";
		if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러");
	}
}