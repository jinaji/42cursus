#include "Base.hpp"
#include <cmath>

Base*	generate(void)
{
	int i = rand() % 3;
	switch(i)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
	return (0);
}

void	identify(Base* p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "A" << std::endl;
}

void	identify(Base& p)
{
	Base tmp;
	try
	{
		tmp = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tmp = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		tmp = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	// try catch https://cplusplus.com/reference/typeinfo/bad_cast/
}
