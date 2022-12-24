#include "../../include/command/Command.hpp"
#include <stdio.h>

void Command::Quit() // <reason>
{
	std::string print = ":127.0.0.1 ERROR :Bye for now!\r\n";
    send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0);
    _server.disconnectClient(_caller.getSocket());
    // reason
}

