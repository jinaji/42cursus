#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat tmp("jina", 1);
	Bureaucrat tmp2("jina2", 150);
	
	std::cout << tmp << std::endl;
	try
	{
		tmp.decrementGrade();
		tmp.incrementGrade();
		tmp.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << std::endl;
		tmp2.decrementGrade();
		tmp2.incrementGrade();
		tmp2.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << tmp << std::endl;
	std::cout << tmp2 << std::endl;
}