#include "Base.hpp"
#include <cmath>

Base::~Base()
{}

Base*	generate(void)
{
	srand(time(NULL));
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
		std::cout << "type: A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "type: B" << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "type: C" << std::endl;
}

void	identify(Base& p)
{
	Base tmp;
	
	try
	{
		tmp = dynamic_cast<A &>(p);
		std::cout << "type: A" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		tmp = dynamic_cast<B &>(p);
		std::cout << "type: B" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		tmp = dynamic_cast<C &>(p);
		std::cout << "type: C" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	// try catch https://cplusplus.com/reference/typeinfo/bad_cast/
}
