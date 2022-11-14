#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	newBook;
	std::string	command;

	std::cout << "ADD SEARCH EXIT" << std::endl;
	while (1)
	{
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (command.compare("ADD") == 0)
			newBook.add();
		else if (command.compare("SEARCH") == 0)
			newBook.search();
		else if (command.compare("EXIT") == 0)
			break ;
		else
			continue ;
		if (!std::cin.eof())
			std::cout << "ADD SEARCH EXIT" << std::endl;
	}
	newBook.exit();
	return (0);
}
