#include "../../include/command/Command.hpp"
#include <stdio.h>

void Command::Quit() // <reason>
{
	std::string print = ":127.0.0.1 QUIT :Bye for now!\r\n";
    send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0);


    print = ":" + _caller.getNick() + " QUIT :" + _parsingPara[0] + "\r\n";
    _server.disconnectClient(_caller.getSocket());





    for (std::list<Client *>::iterator it = _server.getClient().begin(); it != _server.getClient().end(); ++it)
    {
        send((*it)->getSocket(), print.c_str(), strlen(print.c_str()), 0);
    }
}

