#include "../../include/command/Command.hpp"

void Command::Pass()
{
    // std::cout << "pass: " << _pass << ", para: " << _para << ";" ;

    // if (_caller.getpassState() == true)
    // {
    //     this->Numerics(462);
    //     return ;
    // }
    // if (_pass != _para)
    // {
    //     // 비번 틀렸다는 메세지
    //     this->Numerics(464);
    //     return ;
    // }
    // else
    // {
    //     // std::cout << "PASS GATE DONE\n";
    // }
        _caller.setpassState(true);
}