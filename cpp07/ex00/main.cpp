#include "whatever.hpp"
#include <iostream>
#include <string>

void lk()
{
	system("leaks a.out | grep leaked");
}

int main()
{
	{
		int a = 4;
		int b = 2;

		std::cout << "origin : " << a << " " << b << std::endl;
		swap(a, b);
		std::cout << "swap: " << a << " " << b << std::endl;
		std::cout << "min : " << min(a, b) << std::endl;
		std::cout << "max : " << max(a, b) << std::endl;
	}

	std::cout << std::endl;

	{
		const int a = 4;
		const int b = 2;

		std::cout << a << " " << b << std::endl;
		std::cout << "min : " << min(a, b) << std::endl;
		std::cout << "max : " << max(a, b) << std::endl;
	}

	std::cout << std::endl;

	{
		std::string a = "hihi";
		std::string b = "hello";

		std::cout << "origin : " << a << " " << b << std::endl;
		swap(a, b);
		std::cout << "swap: " << a << " " << b << std::endl;
		std::cout << "min : " << min(a, b) << std::endl;
		std::cout << "max : " << max(a, b) << std::endl;
	}

	std::cout << std::endl;
	
	{
		int a = 2;
		int b = 3;

		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}

	std::cout << std::endl;
	atexit(lk);
}