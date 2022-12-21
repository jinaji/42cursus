#include "../../include/command/Command.hpp"
#include <iostream>

Command::Command(std::string input, std::string pass, Client caller): _caller(caller)
{
    std::cout << input << std::endl;
    input_parse(input);
    _pass = pass + "\r\n";
}

void Command::input_parse(std::string input)
{
    size_t pos = input.find(' ');
    if (pos != std::string::npos || pos)
    {
        _cmd = input.substr(0, pos);
        _para = input.substr(pos + 1);
        if (_cmd == _para)
        {
            std::cout << "NO parameter\n";
            return ;
        }
        else
            para_parse(_para);
    }
}

void Command::para_parse(std::string para)
{
    int i = 0;
    size_t pos = para.find(' ');
    
    while (pos != std::string::npos)
    {
        std::string sub = para.substr(i, pos - i);
        // _parsingPara[i] = sub;
        i = pos + 1;
        pos = para.find(' ', i);
    }
    // _parsingPara[i] = para.substr(i, pos - i);
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
    // std::cout << "_cmd: " << _cmd << std::endl;
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