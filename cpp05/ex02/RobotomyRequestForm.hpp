#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	const int gradeForSign;
	const int gradeForExecute;
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& obj);
	const RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
	~RobotomyRequestForm();

	RobotomyRequestForm(const Form& form);
	void execute(Bureaucrat const &excutor) const = 0;
};

RobotomyRequestForm::RobotomyRequestForm() : gradeForSign(72), gradeForExecute(45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : gradeForSign(72), gradeForExecute(45)
{
	(void)obj;
	*this = obj;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm::RobotomyRequestForm(const Form& form) : gradeForSign(72), gradeForExecute(45)
{
	if (form.getGrade() < this->gradeForExecute)
		throw (GradeTooLowException());
}

#endif