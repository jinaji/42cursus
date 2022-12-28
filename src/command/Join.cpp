#include "../../include/command/Command.hpp"

/*

  JOIN #foobar                    ; join channel #foobar.

  JOIN &foo fubar                 ; join channel &foo using key "fubar".

  JOIN #foo,&bar fubar            ; join channel #foo using key "fubar"
								  and &bar using no key.

  JOIN #foo,#bar fubar,foobar     ; join channel #foo using key "fubar".
								  and channel #bar using key "foobar".

  JOIN #foo,#bar                  ; join channels #foo and #bar.

  ?????
  _para 뒤에 개행 띠고 채널 이름으로 넣어야 list에서 편할듯해염
*/

	// int		checkChannel(std::string name, std::list<Channel> chnl)
	// {
	// 	for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
	// 	{
	// 		if (name == (*it).getName())
	// 			return (0);
	// 	}
	// 	return (1);
	// }

	// :irc.example.com MODE #foobar +o bunny
	// ; The irc.example.com server gave channel
	// operator privileges to bunny on #foobar.
	// std::string print = ":127.0.0.1 MODE " + chnlName + " +o " + _caller.getNick();
	// print += "\r\n";
	// if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
	// 	throw std::runtime_error("send 에러");


void	Command::joinMessage(std::string name)
{
	//  :WiZ JOIN #Twilight_zone		; WiZ is joining the channel
	//  :dan-!d@localhost JOIN #test    ; dan- is joining the channel #test

	std::string print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " JOIN " + name;
	print += "\r\n";
	if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
        throw std::runtime_error("send 에러1");

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
	for (size_t i = 0; i < tmp.getParticipantsSize(); i++)
	{
		if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       		throw std::runtime_error("send 에러2");
		if (tmp.getParticipantsFd().end() != it && tmp.getParticipantsKey(it) != _caller.getSocket())
		{
			print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " JOIN " + name;
			print += "\r\n";
			if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       			throw std::runtime_error("send 에러3");
		}
		// // 332
		print = ":127.0.0.1 " + std::to_string(332) + " " + _caller.getNick() + " ";
		print += _caller.getNick() + " " + name + " :" + "\r\n"; // <client> <channel> :<topic>";
		if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러4");
		// // 333
		print = ":127.0.0.1 " + std::to_string(333) + " " + _caller.getNick() + " ";
		print += _caller.getNick() + " " + name + " " + tmp.getParticipantsValue(it) + "\r\n"; // "<client> <channel> <nick> <setat>";
		if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러5");
		// // 353
		print = ":127.0.0.1 " + std::to_string(353) + " " + _caller.getNick() + " ";
		print += "@ " + name + " :" + tmp.getParticipantsValue(it) + "\r\n"; // "<client> <symbol> <channel> :[prefix]<nick>{ [prefix]<nick>}";
		if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러6");
		// 366
		print = ":127.0.0.1 " + std::to_string(366) + " " + _caller.getNick() + " ";
		print += _caller.getNick() + " " + name + " :End of /Names list" + "\r\n"; //"<client> <channel> :End of /NAMES list";
		if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
			throw std::runtime_error("send 에러7");
		it++;
	}
/*

If a client’s JOIN command to the server is successful, the server MUST send, in this order:

A JOIN message with the client as the message <source> and the channel they have joined as the first parameter of the message.
The channel’s topic (with RPL_TOPIC (332) and optionally RPL_TOPICWHOTIME (333)), and no message if the channel does not have a topic.
A list of users currently joined to the channel (with one or more RPL_NAMREPLY (353) numerics followed by a single RPL_ENDOFNAMES (366) numeric). These RPL_NAMREPLY messages sent by the server MUST include the requesting client that has just joined the channel.

*/

}

void    Command::Join()
{
	// channel mode 확인하고 초대 ,,, 밴 뭐 어쩌구
	std::string chnlName = _parsingPara[0];
	std::string chnlPass = _parsingPara[1];
	size_t nameStart = 0;
	size_t passStart = 0;
	size_t namePos = chnlName.find(',');
	size_t passPos = chnlPass.find(',');

	while (namePos != std::string::npos)
	{
		chnlName = _parsingPara[0].substr(nameStart, namePos - nameStart);
		nameStart = namePos + 1;
		namePos = _parsingPara[0].find(',', nameStart);
		chnlPass = _parsingPara[1].substr(passStart ,passPos- passStart);
		passStart = passPos + 1;
		passPos = _parsingPara[1].find(',', passStart);

		if (chnlName.find(0x07) != std::string::npos || chnlName.find(',') != std::string::npos) // space 무조건 앞에서 잘려서 확인안함
		{
			this->Numerics(403);
			continue ;
		}
		if (checkChannel(chnlName) == false) // 채널 존재 안 함 새로 만듦
		{
			Channel instance(chnlName);
			instance.setPass(chnlPass);
			instance.setParticipants(1, _caller.getSocket(), _caller.getNick()); // op줘야댐 채널 모드도 줄거면 여기서 해야댐
			_caller.addChannel(instance);
			_server.getChannel().push_back(instance);
			this->joinMessage(chnlName);
		}
		else // 채널 있어서 거기 들어갈 거임
		{
			std::list<Channel> &chnl = _server.getChannel();

			for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
			{
				if ((*it).getName() == chnlName)
				{
					if ((*it).getPass() == chnlPass || (*it).getPass().empty())
					{
						(*it).setParticipants(1, _caller.getSocket(), _caller.getNick());
						this->joinMessage(chnlName);
					}
					else
						this->Numerics(475);
				}
			}
		}
	}
	chnlName = _parsingPara[0].substr(nameStart, namePos - nameStart);
	chnlPass = _parsingPara[1].substr(passStart ,passPos- passStart);
	if (!checkChannel(chnlName))
	{
		Channel instance(chnlName);
		instance.setPass(chnlPass);
		instance.setParticipants(1, _caller.getSocket(), _caller.getNick());
		_caller.addChannel(instance);
		_server.getChannel().push_back(instance);
		this->joinMessage(chnlName);
	}
	else
	{
		std::list<Channel> &chnl = _server.getChannel();
		
		for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
		{
			if ((*it).getName() == chnlName)
			{
				if ((*it).getPass() == chnlPass || (*it).getPass().empty())
				{
					(*it).setParticipants(1, _caller.getSocket(), _caller.getNick());
					this->joinMessage(chnlName);
					// if ((*it).getParticipants() == 1)
					// 	; // oper
				}
				else
					this->Numerics(475);
			}
		}
	}
}