#include "Bureaucrat.hpp"

void lk()
{
	system("leaks a.out | grep leaked");
}

int main()
{
	Bureaucrat	tmp("jina", 5);
	Form sign("dinner choice", 4, 3);

	std::cout << std::endl << tmp << std::endl;
	try
	{
		tmp.signForm(sign);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sign << std::endl;
	
	try
	{
		tmp.incrementGrade();
		tmp.signForm(sign);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << sign << std::endl;

	atexit(lk);
}