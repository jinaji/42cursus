#include "../../include/command/Command.hpp"

void    Command::Nick()
{
    // 이미쓰고있는 닉 -> 433
    // 유효한 별명 X -> 432
    // 매개변수 X -> 431
    _caller.setNick(_para);
    // std::cout << "NICK GATE DONE\n";
}