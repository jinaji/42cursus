#include "../../include/command/Command.hpp"

void Command::Oper()
{
    if (_paraNum != 2)
    {
        this->Numerics(461);
        return ;
    }
    if (_pass != _parsingPara[1])
    {
        this->Numerics(464);
    }
    std::list<Client *>::iterator it = _server.getClient().begin();
    for (; it != _server.getClient().end(); ++it)
    {
        if ((*it)->getNick() != _parsingPara[0])
        {
            this->Numerics(491);
            return ;
        }
    }
    _caller.setservOper(true);
    this->Numerics(381);
}