#include "Contact.hpp"
#include <iomanip>

void	Contact::showAll()
{
	std::cout << "first name: " << this->firstName << std::endl;
	std::cout << "last name: " << this->lastName << std::endl;
	std::cout << "nickname: " << this->nickName << std::endl;
	std::cout << "phone number: " << this->phoneNumber << std::endl;
	std::cout << "darkest secret: " << this->darkestSecret << std::endl;
}

std::string	Contact::informDisplay(std::string inform)
{
	if (inform.length() > 10)
		inform.assign(inform, 0, 9).append(".");
	else
		inform.assign(inform);
	return (inform);
}

void	Contact::display()
{
	std::cout << "index: " << std::setw(10) << this->index << " | ";
	std::cout << "first name: " << std::setw(10) << informDisplay(this->firstName) << " | ";
	std::cout << "last name: " << std::setw(10) << informDisplay(this->lastName) << " | ";
	std::cout << "nickname: " << std::setw(10) << informDisplay(this->nickName) << std::endl;
}

void	Contact::fillContact(std::string &str)
{
	while (1)
	{
		std::getline(std::cin, str);
		if (std::cin.eof() || str.empty())
		{
			std::cin.clear();
			clearerr(stdin);
			continue ;
		}
		else
			break ;
	}
}

void	Contact::addContact(int i)
{
	this->index = i;
	std::cout << "first name: ";
	fillContact(this->firstName);
	std::cout << "last name: ";
	fillContact(this->lastName);
	std::cout << "nickname: ";
	fillContact(this->nickName);
	std::cout << "phone number: ";
	fillContact(this->phoneNumber);
	std::cout << "darkest secret: ";
	fillContact(this->darkestSecret);
}