// #include <vector>
#include <string>
#include "vector.hpp"

int main()
{
	ft::Vector<std::string> test(5, "hi");
	ft::Vector<std::string>::iterator it = test.begin();
	ft::Vector<std::string>::iterator ite = test.end();
	
	for (; it != ite; it++)
		std::cout << *it << std::endl;

	ft::Vector<std::string> test5(test);
	ft::Vector<std::string>::iterator it5 = test5.begin();
	ft::Vector<std::string>::iterator ite5 = test5.end();

	for (; it5 != ite5; it5++)
		std::cout << *it5 << std::endl;

	// ft::Vector<std::string>	test2(it, ite);
	// ft::Vector<std::string>::iterator it2 = test2.begin();
	// ft::Vector<std::string>::iterator ite2 = test2.end();
	
	// for (; it2 != ite2; it2++)
	// 	std::cout << *it2 << std::endl;

	// ft::Vector<int>				test3(5, 1);
	// ft::Vector<int>::iterator 	it3 = test3.begin();
	// ft::Vector<int>::iterator 	ite3 = test3.end();

	// for (; it3 != ite3; it3++)
	// 	std::cout << *it3 << std::endl;

	// std::vector<int>				test4(5, 1);
	// std::vector<int>::iterator 	it4 = test4.begin();
	// std::vector<int>::iterator 	ite4 = test4.end();


	// std::cout << it << std::endl;
	// std::cout << ite << std::endl;
} 