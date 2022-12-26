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

int		checkChannel(std::string name, std::list<Channel> chnl)
{
	for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
	{
		if (name == (*it).getName())
			return (0);
	}
	return (1);
}


void	joinMessage()
{

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
		if (checkChannel(chnlName, _server.getChannel())) // 채널 존재 안 함 새로 만듦
		{
			Channel instance(chnlName);
			instance.setPass(chnlPass);
			instance.setParticipants(1, _caller.getSocket()); // op줘야댐 채널 모드도 줄거면 여기서 해야댐
			_caller.addChannel(instance);
			_server.getChannel().push_back(instance);
		}
		else // 채널 있어서 거기 들어갈 거임
		{
			std::list<Channel> chnl = _server.getChannel();

			for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
			{
				if ((*it).getName() == chnlName)
				{
					if ((*it).getPass() == chnlPass || (*it).getPass().empty())
						(*it).setParticipants(1, _caller.getSocket());
					else
						this->Numerics(475);
				}
			}
		}
	}
		chnlName = _parsingPara[0].substr(nameStart);
		chnlPass = _parsingPara[1].substr(passStart);
		if (checkChannel(chnlName, _server.getChannel()))
		{
			Channel instance(_para);
			instance.setPass(chnlPass);
			instance.setParticipants(1, _caller.getSocket());
			_caller.addChannel(instance);
			_server.getChannel().push_back(instance);
		}
		else
		{
			std::list<Channel> chnl = _server.getChannel();

			for (std::list<Channel>::iterator it = chnl.begin(); it != chnl.end(); it++)
			{
				if ((*it).getName() == chnlName)
				{
					if ((*it).getPass() == chnlPass || (*it).getPass().empty())
					{
						(*it).setParticipants(1, _caller.getSocket());
						if ((*it).getParticipants() == 1)
							; // oper
					}
					else
						this->Numerics(475);
				}
			}
		}
}