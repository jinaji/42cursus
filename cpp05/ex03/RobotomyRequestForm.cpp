#include "RobotomyRequestForm.hpp"
#include <stdlib.h>
#include <time.h>

RobotomyRequestForm::RobotomyRequestForm() : Form("Robotomy Request Form", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("Robotomy Request Form", 72, 45)
{
	setTarget(target);
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj)
{
	(void)obj;
	*this = obj;
}

const RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	(void)obj;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	srand(time(NULL));
	if (this->getGradeForExecute() < executor.getGrade())
		throw (GradeTooLowException());
	if (this->getSign() == false)
		throw (NotSignedException());

	std::cout << "Makes some drilling noises" << std::endl;
	std::cout << this->getTarget();
	if (rand() % 2)
		std::cout << " has been robotomized successfully" << std::endl;
	else
		std::cout << "'s robotomy is failed" << std::endl;
}