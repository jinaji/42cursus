#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : gradeForSign(145), gradeForExecute(137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : gradeForSign(145), gradeForExecute(137)
{
	(void)obj;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const Form& form) : gradeForSign(145), gradeForExecute(137)
{
	if (form.getGrade() < this->gradeForExecute)
		throw (GradeTooLowException());
	
	std::ofstream writeFile(form.getName() + "_shruberry");
	writeFile << 
	"	     _-_"
	"    //~~   ~~\\ "
	" //~~         ~~\\ "
	"{               }"
	" \\  _-     -_  //"
	"   ~  \\ //  ~"
	"_- -   | | _- _"
	"  _ -  | |   -_"
	"      // \\";

	writeFile.close();
	std::ofstream writeFile;
	writeFile.open(form.getName() + "_shrubbery");
}

void ShrubberyCreationForm::execute(Bureaucrat const &excutor) const
{
	if (this->getSign() == false)
		throw (GradeTooLowException());
}