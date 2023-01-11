#include "../../include/command/Command.hpp"

void Command::Numerics(int num, std::string name, std::string other)
{
	std::string print = ":127.0.0.1 " + std::to_string(num) + " " + _caller.getNick() + " ";

    (void) other;

	switch (num)
	{
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
        // RPL_LISTSTART (321) https://modern.ircdocs.horse/#rplliststart-321
        case 321:
            print += "Channel :Users  Name";
            break;
        // RPL_LIST (322) https://modern.ircdocs.horse/#rpllist-322 
        // case 322:
            // name chnlname participants topic 
        // RPL_TOPIC (332) https://modern.ircdocs.horse/#rpltopic-332
        case 332:
            print += name + " :" + other; // + setat
            break;
        // RPL_TOPICWHOTIME (333) https://modern.ircdocs.horse/#rpltopicwhotime-333
        case 333:
            print += name + " " + other;
            break;
        // RPL_INVITELIST (336) https://modern.ircdocs.horse/#rplinvitelist-336
        case 336:
            print += " " + name;
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
        // ERR_NOSUCHCHANNEL (403) https://modern.ircdocs.horse/#errnosuchchannel-403
        case 401:
            print += name + " :No such nick/channel";
            break;
        case 403:
            print += name + " :No such channel";
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
        // ERR_NOTONCHANNEL (442) https://modern.ircdocs.horse/#errnotonchannel-442
        case 442:
            print += name + " :You're not on that channel";
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
        // ERR_BADCHANNELKEY (475) https://modern.ircdocs.horse/#errbadchannelkey-475
        case 475:
            print += name + " :Cannot join channel (+k)";
            break;
        // ERR_CHANOPRIVSNEEDED (482) https://modern.ircdocs.horse/#errchanoprivsneeded-482
        case 482:
            print += name + " :You're not channel operator";
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