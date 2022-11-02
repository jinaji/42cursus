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
	Bureaucrat(const std::string name);
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();

public:
	int GradeTooHighException();
	int GradeTooLowException();
	
	const std::string getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& os, Bureaucrat& obj);

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(const std::string name) : name(name), grade(0)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade)
{
}

Bureaucrat::~Bureaucrat()
{
}

int Bureaucrat::GradeTooHighException()
{
	std::cout << this->grade << " is too high" << std::endl;
}

int Bureaucrat::GradeTooLowException()
{
	std::cout << this->grade << " is too low" << std::endl;
}

const std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade()
{
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	this->grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj)
{
	std::cout << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;
}

#endif