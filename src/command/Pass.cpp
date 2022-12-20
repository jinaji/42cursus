#include "../../include/command/Command.hpp"

void Command::Pass()
{
    if (_pass.compare(_para))
    {
        if (_para.find("\n"))
            std::cout << "엥";
        else if (_para.find("\r\n"))
            std::cout << "rpd";
        else
            std::cout << "dpaskdak";
        std::cout << "NO!";
        std::cout << "pass " << _pass;
        std::cout << ", para " << _para << " 111";
    }
    else
        std::cout << "YES!";
}