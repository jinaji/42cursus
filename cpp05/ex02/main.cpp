#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat	me("jina", 50);
	ShrubberyCreationForm	shrubbery("Home");
	RobotomyRequestForm		robotomy("robo");
	PresidentialPardonForm	president("pre");

	std::cout << me << std::endl;
	std::cout << std::endl;
	try
	{
		me.signForm(shrubbery);
		me.executeForm(shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		me.signForm(robotomy);
		me.executeForm(robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		me.signForm(president);
		me.executeForm(president);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << shrubbery << std::endl;
	std::cout << robotomy << std::endl;
	std::cout << president << std::endl;
}