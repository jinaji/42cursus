#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{
private:
	const int gradeForSign;
	const int gradeForExecute;
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& obj);
	const ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
	~ShrubberyCreationForm();

	ShrubberyCreationForm(const Form& form);
	void execute(Bureaucrat const &excutor) const;
};

#endif