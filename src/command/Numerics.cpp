#include "../../include/command/Command.hpp"

void Command::Numerics(int num)
{
	std::string print = ":127.0.0.1 " + std::to_string(num) + " " + _caller.getNick() + " ";

	switch (num)
	{
		case 1:
			print += ":Welcome to the Internet Relay Network";
			break;
		case 2:
			print += ":Your host is ft_irc, running version 0.01";
			break;
		case 3:
			print += ":This server was created 2022 ~ 2023";
			break;
		case 4:
			print += ":ft_irc 0.01 <available user modes> <available channel modes>";
			break;
        case 5:
            print += ":<1-13 tokens> :are supported by this server";
            break;
		case 462:
			print += ":You may not reregister";
			break;
		case 464:
			print += ":Password incorrect";
			break;
		
		default:
			break;
	}
    print += "\r\n";
    std::cout << "print[" << print << "]";
    if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
        throw std::runtime_error("send 에러");
}