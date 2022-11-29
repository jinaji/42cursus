#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("Shrubbery Creation Form", 145, 137)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("Shrubbery Creation Form", 145, 137)
{
	setTarget(target);
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj)
{
	*this = obj;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return *this;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSign() == false)
		throw (NotSignedException());
	if (this->getGradeForExecute() < executor.getGrade())
	{
		std::cout << "Execute failed beceause ";
		throw (GradeTooLowException());
	}
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