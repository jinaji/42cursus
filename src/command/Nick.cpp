#include "../../include/command/Command.hpp"

void    Command::Nick()
{
    // 이미쓰고있는 닉 -> 433
    std::list<Client *>::iterator it = this->_server->getClient().begin();
    for (; it != this->_server->getClient().end(); ++it)
    {
        if ((*it)->getNick() == this->_parsingPara[0])
        {
            this->Numerics(433);
            return ;
        }
    }
    // 유효한 별명 X (숫자) -> 432
    // if (isdigit(_parsingPara[0].at(0) == true))
    //     this->Numerics(432);
    
    // 매개변수 X -> 431
    // if (_paraNum == 0)
    //     this->Numerics(431);

    _caller.setNick(_parsingPara[0]);
    
    // std::cout << "NICK GATE DONE\n";
}