#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat tmp("name", 1);
	
	std::cout << tmp << std::endl;
	try
	{
		// tmp.decrementGrade();
		tmp.incrementGrade();
	}
	catch(std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << tmp << std::endl;
}