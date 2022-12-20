#include "../../include/command/Command.hpp"

void Command::Pass()
{
    // std::cout << "pass: " << _pass << ", para: " << _para << ";" ;
    if (_pass != _para)
    {
        // 틀렸다는 메세지
        this->Numerics(464);
    }
    else
        _caller.setPass(_pass);
        // 클라이언트의 PASS정보 통과
}