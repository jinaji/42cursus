#include "../../include/command/Command.hpp"

void Command::Numerics(int num, std::string name, std::string other)
{
	std::string print = ":127.0.0.1 " + std::to_string(num) + " " + _caller.getNick() + " ";

    (void) other;

	switch (num)
	{
        // come
		case 1:
			print += ":Welcome to the Internet Relay Network";
			break;
		case 2:
			print += ":Your host is ft_irc, running version 0.01";
			break;
		case 3:
			print += ":This server was created ~2022/12.31";
			break;
		case 4:
			print += ":ft_irc 0.01";
			break;
        case 5:
            print += ":are supported by this server";
            break;
        // RPL_TOPIC (332) https://modern.ircdocs.horse/#rpltopic-332
        case 332:
            // print += _caller.getNick() + " " + name + " :" + other;
            break;
        // RPL_TOPICWHOTIME (333) https://modern.ircdocs.horse/#rpltopicwhotime-333
        case 333:
            print += _caller.getNick() + " " + name + " " + other;
            break;
        // RPL_NAMREPLY (353) https://modern.ircdocs.horse/#rpltopicwhotime-333
        case 353:
            print += "@ " + name + " :" + other;
            break;
        // RPL_ENDOFNAMES (366) https://modern.ircdocs.horse/#rplendofnames-366
        case 366:
            print += _caller.getNick() + " " + name + " :End of /Names list";
            break;
        case 381:
            print += ":You are now an IRC operator";
            break;
        case 421:
            print += _cmd + " :Unknown command";
            break;
        case 431:
            print += ":No nickname given";
            break;
        case 432:
            print += ":Erroneous nickname";
            break;
        case 433:
            print += ":Nickname is already in use";
            break;
        case 461:
            print += ":Not enough parameters";
            break;
		case 462:
			print += ":You may not reregister";
			break;
		case 464:
			print += ":Password incorrect";
			break;
        case 491:
            print += ":No O-lines for your host";
            break;

		default:
			break;
	}
    print += "\r\n";
    if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
        throw std::runtime_error("send 에러");
}