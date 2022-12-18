#include <iostream>

int main(int ac, char **av)
{
    try
    {
        if (ac != 3)
		    throw std::runtime_error("Usage: ./ircserv <port> <password>");



        return 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return 1;
    }
}