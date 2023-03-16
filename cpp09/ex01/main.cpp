#include "RPN.hpp"

void lk()
{
    system("leaks RPN | grep leaked");
}

int main(int ac, char **av)
{
    RPN rpn;

    atexit(lk);
    if (ac != 2)
    {
        std::cout << "Error" << std::endl;
        exit (1);
    }
    try
    {
        rpn.calculate(av[1]);
        std::cout << rpn._stack.top() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}