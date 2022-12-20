#include "../../include/command/Command.hpp"
#include <iostream>

Command::Command(std::string input, std::string pass): _pass(pass)
{
    const unsigned long pos = input.find(' ');
    // const unsigned long nl = input.find("\n");

    if (pos != std::string::npos)
    {
        // std::cout << nl << std::endl;
        _cmd = input.substr(0, pos);
        this->_para = input.substr(pos + 1, input.size() - 1);
    }
    // std::cout << "_cmd " << _cmd << std::endl;
    // std::cout << "para " << _para << std::endl;s
    // else
    // {
    //     _cmd = NULL;
    //     this->_para = input;
    // }
    // _cmd.execute();
}

void Command::execute()
{
    if (this->_cmd == "PASS")
        Pass();
    else
        std::cout << "NO MATCHING COMMAND!";
    // else if (cmd == )

    // 맞는 함수 찾아서 호출

    // COMMAND asd asdsa d
}