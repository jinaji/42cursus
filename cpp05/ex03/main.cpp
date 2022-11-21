#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main()
{
	Intern	intern;
	Bureaucrat	me("jina", 50);
	ShrubberyCreationForm*	form;

	form = (ShrubberyCreationForm *)intern.makeForm("shrubbery creation", "Home");
	try
	{
		me.signForm(*form);
		me.executeForm(*form);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}