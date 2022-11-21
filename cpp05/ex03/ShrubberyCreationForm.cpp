#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
	(void)obj;
}

const ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	(void)obj;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getGradeForExecute() < executor.getGrade())
		throw (GradeTooLowException());
	if (this->getSign() == false)
		throw (NotSignedException());
	std::ofstream writeFile(this->getTarget() + "_shruberry");
	writeFile << 
	"	     _-_\n "
	"    //~~   ~~\n "
	" //~~         ~~\n "
	"{               }\n "
	" \\  _-     -_  //\n "
	"   ~  \\ //  ~\n "
	"_- -   | | _- _\n "
	"  _ -  | |   -_\n "
	"      // \\\n ";

	writeFile.close();
}