#include "../../include/command/Command.hpp"

// "<client> <symbol> <channel> :[prefix]<nick>{ [prefix]<nick>}"

void	Command::namesMessage(std::string name)
{
	std::string print;
	Channel tmp;
	for (std::list<Channel>::iterator it = _server.getChannel().begin(); it != _server.getChannel().end(); it++)
	{
		if (name == (*it).getName())
		{
			tmp = (*it);
			break ;
		}
	}
	std::map<int, std::string>::iterator it = tmp.getParticipantsFd().begin();
	for (size_t i = 0; i < tmp.getParticipantsSize(); i++, it++)
	{
		// 353
		//  "<client> <symbol> <channel> :[prefix]<nick>{ [prefix]<nick>}"
		print = _caller.getNick() + " " + "= " + name + " :" + tmp.getParticipantsValue(it) + "\r\n";
		std::cout << print;
		// print = ":127.0.0.1 " + std::to_string(353) + " " + _caller.getNick() + " ";
		// print += name + " :" + tmp.getParticipantsValue(it) + "\r\n";
		if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러");
		// 366
		print = ":127.0.0.1 " + std::to_string(366) + " " + _caller.getNick() + " ";
		print += _caller.getNick() + " " + name + " :End of /Names list" + "\r\n"; //"<client> <channel> :End of /NAMES list";
		if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러7");
	}
}

void Command::Names()
{
	std::string print;
	std::string chnlName = _parsingPara[0];
	size_t nameStart = 0;
	size_t namePos = chnlName.find(',');

	while (namePos != std::string::npos)
	{
		chnlName = _parsingPara[0].substr(nameStart, namePos - nameStart);
		nameStart = namePos + 1;
		namePos = _parsingPara[0].find(',', nameStart);

		if (_paraNum == 0)
			return ;
		else if (_paraNum == 1)
		{
			std::list<Channel> &chnl = _caller.getChannel();
			std::list<Channel>::iterator it = chnl.begin();

			for (; it != chnl.end(); it++)
			{
				if ((*it).getName() == chnlName)
				{
					namesMessage((*it).getName());
					break ;
				}
			}
			if (it == chnl.end())
				this->Numerics(401);
		}
	}
	chnlName = _parsingPara[0].substr(nameStart, namePos - nameStart);
	std::list<Channel> &chnl = _caller.getChannel();
	std::list<Channel>::iterator it = chnl.begin();

	if (_paraNum == 1)
	{
		for (; it != chnl.end(); it++)
		{
			if ((*it).getName() == chnlName)
			{
				namesMessage(chnlName);
				break ;
			}
		}
		if (it == chnl.end())
			this->Numerics(401); // no such
	}
	// if (it == chnl.end())
	// 	this->Numerics(442);
}