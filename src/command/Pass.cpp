#include "../../include/command/Command.hpp"

void Command::Pass()
{
    std::cout << "pass: " << _pass << ", para: " << _para << ";" ;

    if (_caller.getpassState() == true) // 이미 등록
    {
        this->Numerics(462);
        return ;
    }
    if (_pass != _para) // 비밀번호 틀림
    {
        this->Numerics(464);
        return ;
    }
    else // 비밀번호 등록
        _caller.setpassState(true);
}