#include "../../include/command/Command.hpp"

// <channel> [<elistcond>] <- Clients MUST NOT submit an ELIST condition unless the server has explicitly defined support for that condition with the ELIST token.
// RPL_LIST (322) 
//   "<client> <channel> <client count> :<topic>"

void	showChannel(std::string name, std::list<Channel> chnl)
{
	for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
	{
		// std::cout << "name " << name << std::endl;
		// std::cout << "get name " << (*it).getName() << std::endl;

		// 지금 이거 찍어보면 마지막에 개행 붙은 것 때문에 #1,#12 식으로 들오오면 12만 인식 ,,,
		// 땜빵칠라고 name += "\r\n" 하니까 마지막 걸 못 읽음 ...
		// join 에서 좀 손봐야될듯 ... 낮잠자구 ...
		
		if (name == (*it).getName())
			std::cout << name << std::endl;
	}
	// LIST #twilight_zone,#42         ; Command to list the channels
    //   "#twilight_zone" and "#42".
	// 오징어에선 하나만 받음 
}

void	Command::List()
{
	if (_paraNum == 0)
	{
		for (std::list<Channel>::iterator it = _server.getChannel().begin(); it != _server.getChannel().end(); it++)
			std::cout << (*it).getName() << std::endl; // 근데 이거 어케보냄 클라이언트한테 ??
	}
	else if (_paraNum == 1)
	{
		if (_parsingPara[0].find('#') == std::string::npos)
			return ;
		std::string para = _parsingPara[0];
		std::string chnl;
		size_t i = 0;
		size_t pos = para.find(',');

		while (pos != std::string::npos)
		{
			chnl = para.substr(i, pos - i);
			i = pos + 1;
			pos = para.find(',', i);
			showChannel(chnl, _server.getChannel());
		}
		chnl = para.substr(i, pos - i);
		showChannel(chnl, _server.getChannel());
	}
}