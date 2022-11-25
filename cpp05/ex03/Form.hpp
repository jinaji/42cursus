#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const	std::string name;
	bool	sign;
	const int	gradeForSign;
	const int	gradeForExecute;
	std::string target;
	
public:
	Form();
	Form(const Form& obj);
	Form(std::string name, int gradeForSign, int gradeForExecute);
	const Form& operator=(const Form& obj);
	virtual ~Form();

public:
	const std::string getName() const;
	bool	getSign() const;
	int getGrade() const;
	int getGradeForSign() const;
	int getGradeForExecute() const;

	bool executionPermCheck(Bureaucrat const &executor);
	void beSigned(Bureaucrat& obj);
	virtual void execute(Bureaucrat const &executor) const = 0;
	void setTarget(const std::string target);
	std::string getTarget() const;

public:
	class GradeTooHighException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Grade too high");
		}
	};
	class GradeTooLowException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Grade too low");
		}
	};
	class NotSignedException : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Not Signed Form");
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif