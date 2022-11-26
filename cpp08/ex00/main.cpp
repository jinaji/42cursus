#include "easyfind.hpp"
#include <iostream>
#include <array>
#include <deque>
#include <vector>

void lk()
{
	system("leaks a.out | grep leaked");
}

int main()
{
	std::array<int, 5> test1 = {0, 1, 2, 3, 4};

	std::deque<int> test2(5); // 4 3 2 1 0
	test2.push_front(0);
	test2.push_front(1);
	test2.push_front(2);
	test2.push_front(3);
	test2.push_front(4);

	std::vector<int> test3; // 0 1 2 3 4 
	test3.push_back(0);
	test3.push_back(1);
	test3.push_back(2);
	test3.push_back(3);
	test3.push_back(4);

	std::cout << easyfind(test1, 3) << std::endl << std::endl;
	std::cout << easyfind(test2, 3) << std::endl << std::endl;
	std::cout << easyfind(test3, 3) << std::endl << std::endl;

	atexit(lk);
}