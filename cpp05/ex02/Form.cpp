#include "Form.hpp"

Form::Form() : name("form no name"), sign(false), gradeForSign(0), gradeForExecute(0)
{
}

Form::Form(const Form& obj) : name("form no name"), sign(false), gradeForSign(obj.gradeForSign), gradeForExecute(obj.gradeForExecute)
{
	*this = obj;
}

Form::Form(std::string name, int gradeForSign, int gradeForExecute) : name(name), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute)
{
}

Form& Form::operator=(const Form& obj)
{
	if (this == &obj)
		return *this;
	return (*this);
}

const std::string Form::getName() const
{
	return (this->name);
}

bool Form::getSign() const
{
	return (this->sign);
}

int Form::getGradeForSign() const
{
	return (this->gradeForSign);
}

int Form::getGradeForExecute() const
{
	return (this->gradeForExecute);
}

Form::~Form()
{
}

void Form::beSigned(Bureaucrat& obj)
{
	if (obj.getGrade() > this->getGradeForSign())
		throw GradeTooLowException();
	else
		this->sign = true;
}

bool Form::executionPermCheck(Bureaucrat const &executor)
{
	if (this->gradeForExecute > executor.getGrade())
		throw GradeTooLowException();
	else
		return (true);
}

void Form::setTarget(const std::string target)
{
	this->target = target;
}

std::string Form::getTarget() const
{
	return (this->target);
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << " needs grade " << obj.getGradeForSign() << " for sign and " << obj.getGradeForExecute() << " for execute. ";
	if (obj.getSign() == 1)
		std::cout << obj.getName() << " is signed" << std::endl;
	else
		std::cout << obj.getName() << " isn't signed " << std::endl;
	return (os);
}
