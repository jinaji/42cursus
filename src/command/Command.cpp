#include "../../include/Command.hpp"

void Command::execute(std::string str)
{
    std::string cmd;
    int pos = str.find(' ');

    if (pos != string::npos)
        cmd = str.substr(0, pos);
    else
        cmd = NULL;
    // 맞는 함수 찾아서 호출

    // COMMAND asd asdsa d
}