#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

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
	ShrubberyCreationForm	sign;

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