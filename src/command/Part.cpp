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
	// std::cout << "size: " << tmp.getParticipantsSize() << std::endl;
	for (; it != tmp.getParticipantsFd().end(); it++)
	{
		// std::cout << "count: " << i << std::endl;
		// name == chanel(name) => remove
		// if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       	// 	throw std::runtime_error("send 에러");
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
		{
			this->Numerics(461);
			break;
		}
		else if (_paraNum == 1)
		{
			std::list<Channel> &chnl = _server.getChannel();
			std::list<Channel>::iterator it = chnl.begin();

			if (checkChannel_caller(chnlName) == false)
			{
				this->Numerics(401);
				break ;
			}
			for (; it != chnl.end(); it++)
			{
				if ((*it).getName() == chnlName)
				{
					this->partMessage(chnlName);
					(*it).getParticipantsFd().erase(_caller.getSocket());
					_caller.removeChannel(it);
					break;
				}
			}
			if (it == chnl.end())
			{
				this->Numerics(401, chnlName);
				break;
			}
		}
	}
	chnlName = _parsingPara[0].substr(nameStart, namePos - nameStart);
	std::list<Channel>::iterator it = _server.getChannel().begin();

	std::cout << "fd: " << _caller.getSocket() << std::endl;
	// std::cout << "size: " << _caller.getChannel().size() << std::endl;
	if (checkChannel_caller(chnlName) == false && it != _caller.getChannel().end())
	{
		this->Numerics(401, chnlName);
		return ;
	}
	// if (call)
	if (checkChannel_caller(chnlName) == true)
	{
		for (; it != _server.getChannel().end(); it++)
		{
			if (checkChannel_caller(chnlName) == true)
			{
				this->partMessage(chnlName);
				(*it).getParticipantsFd().erase(_caller.getSocket());
				_caller.removeChannel(it);
				// server channel update
				break ;
			}
			else
			{
				this->Numerics(401, chnlName);
				return ;
			}
		}
	}
	if (it == _server.getChannel().end())
	{
		this->partMessage(chnlName);
		(*it).getParticipantsFd().erase(_caller.getSocket());
		_caller.removeChannel(it);
		// server channel update
		return ;
	}
}
