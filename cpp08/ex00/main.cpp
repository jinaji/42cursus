#include "easyfind.hpp"
#include <iostream>
#include <deque>
#include <vector>

void lk()
{
	system("leaks a.out | grep leaked");
}

int main()
{
	std::deque<int> test(5); // 4 3 2 1 0
	test.push_front(0);
	test.push_front(1);
	test.push_front(2);
	test.push_front(3);
	test.push_front(4);

	std::vector<int> test2; // 0 1 2 3 4 
	test2.push_back(0);
	test2.push_back(1);
	test2.push_back(2);
	test2.push_back(3);
	test2.push_back(4);

	try
	{
		std::cout << easyfind(test, 3) << std::endl << std::endl;
		std::cout << easyfind(test2, 3) << std::endl << std::endl;
		std::cout << easyfind(test2, 6) << std::endl << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	atexit(lk);
}