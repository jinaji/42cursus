#include "../../include/command/Command.hpp"

void	Command::showChannel(std::string name, std::list<Channel> chnl)
{
	for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
	{
		if (name == (*it).getName())
		{
			std::string print = ":127.0.0.1 322 " + _caller.getNick() + " " + (*it).getName() + " " + std::to_string((*it).getParticipantsSize()) + " :" + (*it).getTopic() + "\r\n";
			if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
				std::runtime_error("send error");
			// this->Numerics(322); 하려다가 인자 너무 많아서 일단 여기서 send ,,, nick / chnlname / participants count
		}
	}
}

void	Command::List()
{
	if (_paraNum == 0) // LIST 창 끄면 다시 명령어 입력했을 때 창이 안 뜨고 / 목록에서 update 하면 목록 밑으로 중복돼서 달림 이거뭐임
	{
		for (std::list<Channel>::iterator it = _server.getChannel().begin(); it != _server.getChannel().end(); it++)
		{
			std::string print = ":127.0.0.1 322 " + _caller.getNick() + " " + (*it).getName() + " " + std::to_string((*it).getParticipantsSize()) + " :" + (*it).getTopic() + "\r\n";
			if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
				std::runtime_error("send error");
		}
	}
	else if (_paraNum == 1)
	{
		if (_parsingPara[0].find('#') == std::string::npos)
			return ;
		std::string chnl;
		size_t start = 0;
		size_t pos = _parsingPara[0].find(',');

		while (pos != std::string::npos)
		{
			chnl = parseComma(_parsingPara[0], start, pos);
			showChannel(chnl, _server.getChannel());
		}
		chnl = parseComma(_parsingPara[0], start, pos);
		showChannel(chnl, _server.getChannel());
		
		std::string print = ":127.0.0.1 323 " + _caller.getNick() + " :End of /LIST\r\n"; // 이거 넣으면 뭔가 될 줄 알았는데 안 됨 ... 없어도 되눈 부분
		if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
			std::runtime_error("send error");
	}
}