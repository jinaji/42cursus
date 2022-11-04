#include "Bureaucrat.hpp"

int main()
{
	// Bureaucrat tmp("name", 1);
	
	// std::cout << tmp << std::endl;
	// try
	// {
	// 	tmp.incrementGrade();
	// }
	// catch(std::exception &e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }
	// std::cout << tmp << std::endl;

	Bureaucrat	tmp("name", 5);
	Form sign(5, 4, 3);

	std::cout << tmp << std::endl;
	try
	{
		tmp.signForm(sign);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}