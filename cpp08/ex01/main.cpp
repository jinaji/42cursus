#include "Span.hpp"
#include <iostream>

void lk()
{
	system("leaks a.out | grep leaked");
}

int main()
{
	try
	{
		Span	test(5);

		test.addNumber(6);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span	test(3); // size over

		test.addNumber(6);
		test.addNumber(3);
		test.addNumber(17);
		test.addNumber(9);
		test.addNumber(11);
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span	test(5); // no enough element

		test.addNumber(6);
		// test.addNumber(3);
		// test.addNumber(17);
		// test.addNumber(9);
		// test.addNumber(11);
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Span	test(5); // duplicated element

		test.addNumber(6);
		test.addNumber(6);
		// test.addNumber(17);
		// test.addNumber(9);
		// test.addNumber(11);
		std::cout << "shortest " << test.shortestSpan() << std::endl;
		std::cout << "longest " << test.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// {
	// 	try
	// 	{
	// 		Span	test(10000);

	// 		srand(time(NULL));
	// 		for (int i = 0; 10000 > i; i++)
	// 		{
	// 			const int value = rand();
	// 			test.addNumber(value);
	// 		}
	// 		test.getCount();
	// 		std::cout << "shortest " << test.shortestSpan() << std::endl;
	// 		std::cout << "longest " << test.longestSpan() << std::endl;
	// 	}
	// 	catch(const std::exception& e)
	// 	{
	// 		std::cerr << e.what() << '\n';
	// 	}
		
	// }
	atexit(lk);
}