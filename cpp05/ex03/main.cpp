#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern	intern;
	Bureaucrat	me("jina", 20);
	
	ShrubberyCreationForm	*shrubbery;
	RobotomyRequestForm		*robotomy;
	PresidentialPardonForm	*pardon;

	try
	{
		shrubbery = (ShrubberyCreationForm *)intern.makeForm("shrubbery creation", "Home");
		robotomy = (RobotomyRequestForm *)intern.makeForm("robotomy request", "robo");
		pardon = (PresidentialPardonForm *)intern.makeForm("presidential pardon", "pardon");
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		me.signForm(*shrubbery);
		me.executeForm(*shrubbery);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		me.signForm(*robotomy);
		me.executeForm(*robotomy);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		me.signForm(*pardon);
		me.executeForm(*pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
}