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
    if (checkClient() == false)
    {
        this->Numerics(401);
        return ;
    }
    if (_caller.getNick() != _parsingPara[0])
    {
        this->Numerics(502);
        return ;
    }
    if (_parsingPara[1].at(0) == '+' || _parsingPara[1].at(0) == '-')
    {
        std::string modestring;
        size_t mode_num = 0; // +123 -> 
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
            if (excute_mode(modestring.at(i)) == false)
            {
                this->Numerics(501);
                return ;
            }
        }
    }
    else
    {
        for (size_t i = 0; i < _parsingPara[1].length(); i++)
        {
            if (excute_mode(modestring.at(i)) == false)
            {
                this->Numerics(501);
                return ;
            }
        }
    }
	//User mode
    

    //Channel mode
}

bool Command::excute_mode(char mode)
{
    (void) mode;
    return true;

    if (mode == 'a')
    {

    }
    else if (mode == 'i')
    {

    }
    else if (mode == 'w')
    {

    }
    else if (mode == 'r')
    {

    }
    else if (mode == 'o')
    {

    }
    else if (mode == 'O')
    {

    }
    else if (mode == 's')
    {

    }
    else
        return false;


        /*
           a - user is flagged as away;
           i - marks a users as invisible;
           w - user receives wallops;
           r - restricted user connection;
           o - operator flag;
           O - local operator flag;
           s - marks a user for receipt of server notices.
        */
}