#include "../../include/command/Command.hpp"

void Command::noticeMessage(std::string name, std::string msg) // channel
{
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

	for (size_t i = 0; i < tmp.getParticipantsSize(); i++, it++)
	{
		std::string print = ":" + _caller.getNick() + " NOTICE " + name + " :" + msg;
		print += "\r\n";
		std::cout << "print[" << print << "]";
		if (_caller.getSocket() == tmp.getParticipantsKey(it))
			continue ;
		if (send(tmp.getParticipantsKey(it), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러");
		// if (tmp.getParticipantsKey(it) == _server.getFdmax())
		// 	this->Numerics(401);
	}
}

void Command::Notice() // <target> <text to be sent>
{
	std::string msg;

	if (_paraNum == 1)
		return ;
	if (_parsingPara[0].find('#') != std::string::npos) // 유저
	{
		// Client *tmp = new Client();
		std::cout << "유저!!!!!!1\n";
		this->noticeMessage(_parsingPara[0], _parsingPara[1]);
		// this->noticeMessage(_parsingPara[0], _parsingPara[1], getNickFd(_parsingPara[0], _server.getClient()));
	}
	else
	{
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