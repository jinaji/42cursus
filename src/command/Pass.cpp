#include "../../include/command/Command.hpp"

void Command::Pass()
{
    // std::cout << "pass: " << _pass << ", para: " << _para << ";" ;

    if (_caller.getpassState() == true)
        this->Numerics(462);
    if (_pass != _para)
    {
        // 틀렸다는 메세지
        this->Numerics(464);
    }
    else
    {
        _caller.setpassState(true);
        std::cout << "PASS GATE DONE\n";
    }
        // 클라이언트의 PASS정보 통과
}