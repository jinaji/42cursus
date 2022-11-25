#include <iostream>
#include "Base.hpp"

int main()
{
	Base*	ptr;
	ptr = generate();

	std::cout << "dynamic cast by pointer" << std::endl;
	identify(ptr);
	std::cout << std::endl;
	std::cout << "dynamic cast by reference" << std::endl;
	identify(*ptr);
}