#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <exception>

class Bureaucrat
{
private:
	const	std::string name;
	int		grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& obj);
	const Bureaucrat& operator=(const Bureaucrat& obj);
	~Bureaucrat();

	Bureaucrat(const std::string name, int grade);
	
public:
	const std::string getName() const;
	int 	getGrade() const;
	void incrementGrade();
	void decrementGrade();

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
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif