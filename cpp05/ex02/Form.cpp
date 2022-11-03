#include "Form.hpp"


Form::Form() : name("form no name"), sign(false), grade(0), gradeForSign(0), gradeForExecute(0)
{
}

Form::Form(const Form& obj) : name("form no name"), sign(false), grade(obj.grade), gradeForSign(obj.gradeForSign), gradeForExecute(obj.gradeForExecute)
{
	*this = obj;
}

Form::Form(int grade, int gradeForSign, int gradeForExecute) : name("form no name"), grade(grade), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute)
{
}

const Form& Form::operator=(const Form& obj)
{
	(void)obj;
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

int Form::getGrade() const
{
	return (this->grade);
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
	this->sign = true;
}

std::ostream& operator<<(std::ostream& os, const Form& obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << ". Signed: " << obj.getSign() << std::endl;
	return (os);
}
