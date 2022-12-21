#include "../../include/command/Command.hpp"
#include <iostream>

Command::Command(std::string input, std::string pass, Client caller): _caller(caller)
{
    const unsigned long pos = input.find(' ');

    _pass = pass + "\r\n";
    if (pos != std::string::npos)
    {
        _cmd = input.substr(0, pos);
        _para = input.substr(pos + 1);
    }
    // else
    // {
    //     _cmd = NULL;
    //     _para = input;
    // }
    // _cmd.execute();
}


// Command::Command(std::string input, std::string pass)
// {
//     const unsigned long pos = input.find(' ');

//     _pass = pass + "\n";
//     if (pos != std::string::npos)
//     {
//         _cmd = input.substr(0, pos);
//         _para = input.substr(pos + 1);
//     }
//     // else
//     // {
//     //     _cmd = NULL;
//     //     _para = input;
//     // }
//     // _cmd.execute();
// }

void Command::execute()
{
    // 무조건 PASS -> NICK, USER
    std::cout << "_cmd: " << _cmd << std::endl;
    if (_cmd == "PASS")
        Pass();
    else if (_cmd == "NICK")
        Nick();
    else if (_cmd == "USER")
        User();
    else if (_cmd == "JOIN")
        Join();
    else
        std::cout << "NO MATCHING COMMAND!" << std::endl;
    // else if (cmd == )

    // 맞는 함수 찾아서 호출

    // COMMAND asd asdsa d
}

void Command::Numerics(int num)
{
    switch (num)
    {
    case 462:
        std::cout << "<client> :You may not reregister" << std::endl;
    case 464:
        std::cout << "<client> :Password incorrect" << std::endl;
        break;
    
    default:
        break;
    }
}