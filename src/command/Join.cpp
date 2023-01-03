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

void	Command::joinMessage(std::string name)
{
	//  :WiZ JOIN #Twilight_zone		; WiZ is joining the channel
	//  :dan-!d@localhost JOIN #test    ; dan- is joining the channel #test

	std::string print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " JOIN " + name + "\r\n";
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
	// std::cout << "size: " << tmp.getParticipantsSize() << std::endl;
	for (; it != tmp.getParticipantsFd().end(); it++)
	{
		// if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       	// 	throw std::runtime_error("send 에러2");
		if (tmp.getParticipantsFd().end() != it && tmp.getParticipantsKey(it) != _caller.getSocket())
		{
			print = ":" + _caller.getNick() + "!" + _caller.getUser() + "@127.0.0.1" + " JOIN " + name + "\r\n";
			if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       			throw std::runtime_error("send 에러3");
		}
		// names reply
		this->Numerics(353, name, tmp.getParticipantsValue(it));
		this->Numerics(366, name);
	}
	if (tmp.getTopicFlag() == true)
	{
		// topic
		this->Numerics(332, name, tmp.getTopic());
		this->Numerics(333, name, tmp.getTopicNick());
	}
}

void    Command::Join()
{
	std::string chnlName = _parsingPara[0];
	std::string chnlPass = _parsingPara[1];
	size_t nameStart = 0;
	size_t passStart = 0;
	size_t namePos = chnlName.find(',');
	size_t passPos = chnlPass.find(',');

	while (namePos != std::string::npos)
	{
		chnlName = parseComma(_parsingPara[0], nameStart, namePos);
		chnlPass = parseComma(_parsingPara[1], passStart, passPos);

		if (chnlName.find(0x07) != std::string::npos || chnlName.find(',') != std::string::npos) // space 무조건 앞에서 잘려서 확인안함
		{
			this->Numerics(403);
			continue ;
		}
		if (checkChannel_server(chnlName) == false) // 채널 존재 안 함 새로 만듦
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
						this->Numerics(475, chnlName);
				}
			}
		}
	}

	chnlName = parseComma(_parsingPara[0], nameStart, namePos);
	chnlPass = parseComma(_parsingPara[1], passStart, passPos);
	if (!checkChannel_server(chnlName))
	{
		Channel instance(chnlName);
		instance.setPass(chnlPass);
		instance.setParticipants(1, _caller.getSocket(), _caller.getNick()); // 채널 클래스에 추가
		_caller.addChannel(instance);	// 클라 클래스에 채널 추가
		_server.getChannel().push_back(instance);	// 서버 클래스에 채널 추가
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
					_caller.addChannel((*it));
					this->joinMessage(chnlName);
				}
				else
					this->Numerics(475, chnlName);
			}
		}
	}
}