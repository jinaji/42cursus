#include "Intern.hpp"

#define SHRUBBERY 0
#define ROBOTOMY 1
#define PARDON 2

Intern::Intern()
{
	this->form[0] = "shrubbery creation";
	this->form[1] = "robotomy request";
	this->form[2] = "presidential pardon";
}

Intern::Intern(const Intern& obj)
{
	*this = obj;
}

const Intern& Intern::operator=(const Intern& obj)
{
	if (this == &obj)
		return *this;
	return (*this);
}

Intern::~Intern()
{
}

Form* Intern::makeForm(std::string formName, std::string target)
{
	Form *tmp;
	int i = 0;

	for (; this->form[i] != formName && 4 > i; i++)
		;

	switch (i)
	{
		case SHRUBBERY :
		{
			tmp = new ShrubberyCreationForm(target);
			return (tmp);
		}
		case ROBOTOMY :
		{
			tmp = new RobotomyRequestForm(target);
			return (tmp);
		}
		case PARDON :
		{
			tmp = new PresidentialPardonForm(target);
			return (tmp);
		}
	}
	throw (WrongFormException());
}