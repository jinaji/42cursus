#ifndef INTERN_HPP
# define INTERN_HPP

# include "Form.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	std::string	form[3];
public:
	Intern();
	Intern(const Intern& obj);
	Intern& operator=(const Intern& obj);
	~Intern();

	Form	*makeForm(std::string formName, std::string target);

	class WrongFormException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Wrong Form");
		}
	};
};

#endif