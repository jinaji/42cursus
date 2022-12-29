#include "../../include/command/Command.hpp"

/*
 :Angel!wings@irc.org INVITE Wiz #Dust

                                   ; Message to WiZ when he has been
                                   invited by user Angel to channel
                                   #Dust
*/

void Command::Invite()
{
    std::string target = _parsingPara[0];
    std::string chnlName = _parsingPara[1];
    
    std::string print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " INVITE " + target + chnlName;
    print += "\r\n";
	if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
        throw std::runtime_error("send 에러");
}