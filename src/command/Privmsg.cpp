#include "../../include/command/Command.hpp"

int	getNickFd(std::string nick, std::list<Client *> clnt)
{
	for (std::list<Client *>::iterator it = clnt.begin(); it != clnt.end(); it++)
	{
		if ((*it)->getNick() == nick)
			return ((*it)->getSocket());
	}
	return (3);
}

void Command::Privmsg() // <target> <text to be sent>
{
	std::string msg;

	if (_paraNum == 1)
		return ;
	if (_parsingPara[0].find('#') == std::string::npos) // user
	{
		int fd = getNickFd(_parsingPara[0], _server.getClient());
		msg = _caller.getNick() +  " PRIVMSG " + _parsingPara[0] + " " + _parsingPara[1];
		send(fd, msg.c_str(), sizeof(msg), 0);
	}
}

// 없는 채널로 보내면 위에 뜸
// <#test>
// text 

// # 없이 보내면 일대일 대화방 생김 걔가 있든말든 nickname
// ban 된 채널이면 뭐 띄우지말고 걍 return ?? 인줄 알았는데 ban exception
// 이거 말고도 이거저거 영향줄 수 있는 모드들이 있대염

// 채널에 안 쏴지면 404