#include "Convert.hpp"
#include <stdlib.h>

int main(int ac, char **av)
{
	Convert		conv;
	std::string	val;

	if (ac != 2)
	{
		std::cout << "Argument count error" << std::endl;
		return (1);
	}
	conv.setData(av[1]); // double
	val = static_cast<std::string>(av[1]);

	conv.printChar();
	conv.printInt();
	conv.printFloat();
	conv.printDouble();
}