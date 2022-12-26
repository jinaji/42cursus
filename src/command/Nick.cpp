#include "../../include/command/Command.hpp"

void    Command::Nick()
{
    if (_paraNum == 0)  // nickname X -> 431
    {
        this->Numerics(431);
        return ;
    }
    if (isdigit(_parsingPara[0].at(0)) == true) // 유효한 별명 X (숫자) -> 432
    {
        this->Numerics(432);
        return ;
    }
    std::list<Client *>::iterator it = _server.getClient().begin();
    for (; it != _server.getClient().end(); ++it)
    {
        if ((*it)->getNick() == _parsingPara[0]) // 이미쓰고있는 닉 -> 433
        {
            this->Numerics(433);
            return ;
        }
    }
    _caller.setNick(_parsingPara[0]);    
    _caller.setnickState(true);
}