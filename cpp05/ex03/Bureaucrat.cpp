#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat() : name("no name"), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat& obj)
{
	*this = obj;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& obj)
{
	if (this == &obj)
		return *this;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
	if (grade > 150)
		throw (GradeTooLowException());
	else if (1 > grade)
		throw (GradeTooHighException());
}

Bureaucrat::~Bureaucrat()
{
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->grade <= 1)
		throw GradeTooHighException();
	this->grade--;
	std::cout << this->name << "'s grade is " << this->grade << std::endl;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= 150)
		throw GradeTooLowException();
	this->grade++;
	std::cout << this->name << "'s grade is " << this->grade << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ".";
	return (os);
}

void	Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
	std::cout << this->name << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(Form const& form)
{
	form.execute(*this);
	std::cout << this->getName() << " executed " << form.getName() << std::endl;
}