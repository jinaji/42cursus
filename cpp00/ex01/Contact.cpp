#include "Contact.hpp"

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
	std::string	tmp;
	int			len;

	tmp = inform.data();
	len = inform.length();
	if (len > 10)
		tmp.resize(10);
	else
	{
		int i = 10 - len;
		for (; i; i--)
			tmp.insert(0, " ");
	}
	tmp[9] = '.';
	return (tmp);
}

void	Contact::display()
{
	std::cout << "index: " << "         " << this->index << " | ";
	std::cout << "first name: " << informDisplay(this->firstName) << " | ";
	std::cout << "last name: " << informDisplay(this->lastName) << " | ";
	std::cout << "nickname: " << informDisplay(this->nickName) << std::endl;
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