#include "Fixed.hpp"

int main(void)
{
	Fixed			a;
	Fixed	const	b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl; // 0
	std::cout << ++a << std::endl; // 1
	std::cout << a << std::endl; // 1 
	std::cout << a++ << std::endl; // 1
	std::cout << a << std::endl; // 2

	std::cout << b << std::endl;

	std::cout << Fixed::max(a,b) << std::endl;

	// Fixed		a(3.5f);
	// Fixed		b(2.0f);
	
	// std::cout << "a: " << a << std::endl;
	// std::cout << "b: " << b << std::endl << std::endl;

	// std::cout << a + b << std::endl; // 5.5
	// std::cout << a - b << std::endl; // 1.5
	// std::cout << a * b << std::endl; // 7
	// std::cout << a / b << std::endl; // 1.75

	return (0);
}