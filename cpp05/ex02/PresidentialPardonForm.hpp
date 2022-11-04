#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	const int gradeForSign;
	const int gradeForExecute;
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& obj);
	const PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
	~PresidentialPardonForm();

	PresidentialPardonForm(const Form& form);
	void execute(Bureaucrat const &excutor) const = 0;
};

PresidentialPardonForm::PresidentialPardonForm() : gradeForSign(25), gradeForExecute(5)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : gradeForSign(25), gradeForExecute(5)
{
	(void)obj;
	*this = obj;
}

const PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm::PresidentialPardonForm(const Form& form) : gradeForSign(25), gradeForExecute(5)
{
	if (form.getGrade() < this->gradeForExecute)
		throw (GradeTooLowException());
}

#endif