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
	*this = obj;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return *this;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw (NotSignedException());
	if (this->getGradeForExecute() < executor.getGrade())
		throw (GradeTooLowException());
	std::cout << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}