#include "../../include/command/Command.hpp"

void Command::privmsgMessage(std::string name, std::string msg) // channel
{
	//for문으로 돌릴거임 참여자들 ~~~ name <- channel name
	Channel tmp;
	int flag = 0;
	for (std::list<Channel>::iterator it = _server.getChannel().begin(); it != _server.getChannel().end(); it++)
	{
		if (name == (*it).getName())
		{
			tmp = (*it);
			flag = 1;
			break ;
		}
	}
	std::map<int, std::string>::iterator it = tmp.getParticipantsFd().begin();

	if (flag == 0)
	{
		this->Numerics(401);
		return ;
	}
	for (size_t i = 0; i < tmp.getParticipantsSize(); i++, it++)
	{
		std::string print = ":" + _caller.getNick() + " PRIVMSG " + name + " :" + msg;
		print += "\r\n";
		std::cout << "print[" << print << "]";
		if (_caller.getSocket() == tmp.getParticipantsKey(it))
			continue ;
		if (send(tmp.getParticipantsKey(it), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러");
	}
}

void Command::privmsgMessage(std::string name, std::string msg, int fd) // user
{
	std::string print = ":" + _caller.getNick() + " PRIVMSG " + name + " :" + msg;
	print += "\r\n";
    std::cout << "print[" << print << "]";
    if (send(fd, print.c_str(), strlen(print.c_str()), 0) == -1)
        throw std::runtime_error("send 에러");
	// if (fd == _server.getFdmax())
	// 	this->Numerics(401);
}

int	Command::getNickFd(std::string nick, std::list<Client *> clnt)
{
	for (std::list<Client *>::iterator it = clnt.begin(); it != clnt.end(); it++)
	{
		if ((*it)->getNick() == nick)
			return ((*it)->getSocket());
	}
	return (_server.getFdmax());
}

void Command::Privmsg() // <target> <text to be sent>
{
	std::string msg;

	if (_paraNum == 1)
		return ;
	if (_parsingPara[0].find('#') == std::string::npos) // 유저
	{
		this->privmsgMessage(_parsingPara[0], _parsingPara[1], getNickFd(_parsingPara[0], _server.getClient()));
	}
	else
	{
		this->privmsgMessage(_parsingPara[0], _parsingPara[1]);
	}
}
 
// 없는 채널로 보내면 위에 뜸
// <#test>
// text 

// # 없이 보내면 일대일 대화방 생김 걔가 있든말든 nickname
// ban 된 채널이면 뭐 띄우지말고 걍 return ?? 인줄 알았는데 ban exception
// 이거 말고도 이거저거 영향줄 수 있는 모드들이 있대염

// 채널에 안 쏴지면 404

// void Command::Privmsg()
// {
// 	/*
// 	에러 코드
// 	*/
// 	std::string print = ":" + _caller.getNick() + " PRIVMSG";
// 	/*
// 	1. 채널에 전송
// 	2. 유저에 전송
// 	3. else

// 	parsingPara[0]을 ,기준으로 잘라서 각 채널에다 parsingPara[1]를 send
// 	없는 채널에 보내면 출력하고 Error(401)
// 	*/
// }