#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	tmp("jina", 5);
	Form sign(4, 3);

	std::cout << std::endl << tmp << std::endl;
	try
	{
		tmp.signForm(sign);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sign << std::endl;
	std::cout << "*" << std::endl << std::endl;

	try
	{
		tmp.incrementGrade();
		tmp.signForm(sign);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sign << std::endl;
}