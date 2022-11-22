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
	val = (std::string)av[1];

	// std::cout << conv.toChar() << std::endl;
	// std::cout << conv.toInt() << std::endl;
	// std::cout << conv.toFloat() << std::endl;
	// std::cout << conv.toDouble() << std::endl;
	conv.printChar();
	conv.printInt();
	conv.printFloat();
	conv.printDouble();
//strtod isnan isinf...inite
}