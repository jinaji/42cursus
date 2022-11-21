#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Presidential Pardon Form", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("Presidential Pardon Form", 25, 5)
{
	setTarget(target);
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj)
{
	(void)obj;
	*this = obj;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	(void)obj;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getGradeForExecute() < executor.getGrade())
		throw (GradeTooLowException());
	if (this->getSign() == false)
		throw (NotSignedException());
	std::cout << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}