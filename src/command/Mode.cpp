#include "../../include/command/Command.hpp"

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
    if (checkClient(_parsingPara[0]) == false && checkChannel(_parsingPara[0]) == false)
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
    /*
        Mode: +ins
        Created at: Dec 27, 2022 at 2:46 PM
    */
    // if (_paraNum == 1)
    //     return ;
    if (_parsingPara[1].at(0) == '+' || _parsingPara[1].at(0) == '-')
    {
        std::string modestring;
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
            if (excute_mode(modestring.at(i), _mode) == false)
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

bool Command::excute_mode(char mode, char c)
{
    if (c == 'u')   // user_mode
    {
        if (mode == 'a')
        {
            _caller._userMode[user_a] = true;
            return true;
        }
        else if (mode == 'i')
        {
            std::cout << "IIOIOIIIIIIIIIII\n";
            _caller._userMode[user_i] = true;                
            return true;
        }
        else if (mode == 'w')
        {
            _caller._userMode[user_w] = true;                
            return true;
        }
        else if (mode == 'r')
        {
            _caller._userMode[user_r] = true;                
            return true;
        }
        else if (mode == 'o')
        {
            _caller._userMode[user_o] = true;                
            return true;
        }
        else if (mode == 'O')
        {
            _caller._userMode[user_O] = true;                
            return true;
        }
        else if (mode == 's')
        {
            _caller._userMode[user_s] = true;                
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
                if (mode == 'o')
                {
                    (*it)._channelMode[channel_o] = true;
                    return true;
                }
                else if (mode == 'p')
                {
                    (*it)._channelMode[channel_p] = true;
                    return true;
                }
                else if (mode == 's')
                {
                    (*it)._channelMode[channel_s] = true;
                    return true;
                }
                else if (mode == 't')
                {
                    (*it)._channelMode[channel_t] = true;
                    return true;
                }
                else if (mode == 'm')
                {
                    (*it)._channelMode[channel_m] = true;
                    return true;
                }
                else if (mode == 'v')
                {
                    (*it)._channelMode[channel_v] = true;
                    return true;
                }
                else if (mode == 'l')
                {
                    (*it)._channelMode[channel_l] = true;
                    return true;
                }
                else if (mode == 'b')
                {
                    (*it)._channelMode[channel_b] = true;
                    return true;
                }
                else if (mode == 'k')
                {
                    (*it)._channelMode[channel_k] = true;
                    return true;
                }
            }
        }
    }
    return false;
}