#include "../../include/command/Command.hpp"

//   :dan-!d@localhost PART #test    ; dan- is leaving the channel #test

void Command::Part() // <channel> [<reason>]
{
	std::string print;

	if (_paraNum == 0)
		this->Numerics(461);
	else if (_paraNum == 1)
	{
		std::list<Channel>::iterator it = _caller.getChannel().begin();

		for (; it != _caller.getChannel().end(); it++)
			if (_parsingPara[0] == (*it).getName())
				break ;
		_caller.getChannel().erase(it);
		print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " PART " + _parsingPara[0];
		print + "\r\n";
		send (_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0);
	}
}