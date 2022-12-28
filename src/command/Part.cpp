#include "../../include/command/Command.hpp"

//   :dan-!d@localhost PART #test    ; dan- is leaving the channel #test

void	Command::partMessage(std::string name)
{
	std::string print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " PART " + name;
	print += "\r\n";
	if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
        throw std::runtime_error("send 에러");

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
		if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       		throw std::runtime_error("send 에러");
		if (--tmp.getParticipantsFd().end() != it)
		{
			print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " PART " + name;
			print += "\r\n";
			if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       			throw std::runtime_error("send 에러");
		}
	}
}

void Command::Part() // <channel> [<reason>]
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
			this->Numerics(461);
		else if (_paraNum == 1)
		{
			// std::list<Channel>::iterator it = _caller.getChannel().begin();

			// for (; it != _caller.getChannel().end(); it++)
			// 	if (_parsingPara[0] == (*it).getName())
			// 		break ;
			
			// _caller.getChannel().erase(it);

			// std::list<Channel> &chnl = _server.getChannel();
			std::list<Channel> &chnl = _caller.getChannel();

			for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
			{
				
				if ((*it).getName() == chnlName)
				{
					this->partMessage(chnlName);
					(*it).getParticipantsFd().erase(_caller.getSocket());
					// _caller.getChannel().erase(it);
				}
				else
					this->Numerics(442);
			}	
			// print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " PART " + _parsingPara[0];
			// print + "\r\n";
			// send (_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0);
		}
	}
	chnlName = _parsingPara[0].substr(nameStart, namePos - nameStart);
	std::list<Channel> &chnl = _caller.getChannel();

	for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
	{
		if ((*it).getName() == chnlName)
		{
			this->partMessage(chnlName);
			(*it).getParticipantsFd().erase(_caller.getSocket());
			// _caller.getChannel().erase(it);
		}
		else
			this->Numerics(442);
	}

}