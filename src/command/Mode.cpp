#include "../../include/command/Command.hpp"

void	Command::modeMessage(std::string name, char flag)
{
    std::string print = ":127.0.0.1 MODE " + name + " " + flag + "o " + _parsingPara[2];
    print += "\r\n";
    if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
        throw std::runtime_error("send 에러");

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
	for (; it != tmp.getParticipantsFd().end(); it++)
	{
		if (send(tmp.getParticipantsKey(it) , print.c_str(), strlen(print.c_str()), 0) == -1)
       		throw std::runtime_error("send 에러");
		if (--tmp.getParticipantsFd().end() != it)
		{
			std::string print = ":127.0.0.1 MODE " + name + " " + flag + "o " + _parsingPara[2];
            print += "\r\n";
            if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
                throw std::runtime_error("send 에러");
		}
	}


}

void Command::Mode() // <target> [<modestring>] [<mode arguments>...]
{
    // 커맨드 1개 -> 461
    // 해당 nick이 X -> 401
    // Mode 커맨드를 사용한 user의 nick과 <target>의 nick이 다름 -> 502

    if (_paraNum == 0)
    {
        this->Numerics(461);
        return ;
    }
    if (checkClient(_parsingPara[0]) == false && checkChannel_server(_parsingPara[0]) == false)
    {
        this->Numerics(401);
        return ;
    }
    if (_parsingPara[0].at(0) == '#')   // mode가 user인지 channel인지
        _mode = 'c';
    else
        _mode = 'u';
    if (_caller.getNick() != _parsingPara[0] && _mode == 'u')
    {
        this->Numerics(502);
        return ;
    }
    // if (_paraNum == 1)
    //     return ;
    if (_parsingPara[1].at(0) == '+' || _parsingPara[1].at(0) == '-')
    {
        std::string modestring;
        char        flag = _parsingPara[1].at(0);
        size_t mode_num = 0; // +123 -> 3
        std::string::iterator it = _parsingPara[1].begin();
        while (it != _parsingPara[1].end())
        {
            if (*it != '+' && *it != '-')
            {
                modestring += *it;
                mode_num++;
            }
            it++;
        }
        if (mode_num == 0)
            return ;
        for (size_t i = 0; i < mode_num; i++)
        {
            if (excute_mode(modestring.at(i), _mode, flag) == false)
                this->Numerics(501);
        }
    }
    else
    {
        for (size_t i = 1; i < _parsingPara[1].length(); i++)
        {
            if (excute_mode(_parsingPara[1].at(i), _mode) == false)
                this->Numerics(501);
        }
    }
}

bool Command::excute_mode(char mode, char c, char flag)
{
    if (c == 'u')   // user_mode
    {
        // ignore
        if (mode == 'o')
        {
            _caller._userMode[user_o] = true;
            return true;
        }
    }
    else if (c == 'c')  // channel_mode
    {
        std::list<Channel>::iterator it = _server.getChannel().begin();
        for (; it != _server.getChannel().end(); it++)
        {
            if ((*it).getName() == _parsingPara[0])
            {
                if (mode == 'o' && flag == '+')
                {
                    (*it)._channelMode[channel_o] = true;
                    //:irc.example.com MODE #foobar +o bunny
                    this->modeMessage((*it).getName(), flag);
                    // std::string print = ":127.0.0.1 MODE " + (*it).getName() + " +o " + _parsingPara[2];
                    // print += "\r\n";
                    // if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
                    //     throw std::runtime_error("send 에러");
                    return true;
                }
                else if (flag == '-')
                {
                    (*it)._channelMode[channel_o] = true;
                    this->modeMessage((*it).getName(), flag);
                    // std::string print = ":127.0.0.1 MODE " + (*it).getName() + " -o " + _parsingPara[2];
                    // print += "\r\n";
                    // if (send(_caller.getSocket(), print.c_str(), strlen(print.c_str()), 0) == -1)
                    //     throw std::runtime_error("send 에러");
                    return true;
                }
            }
        }
    }
    return false;
}