#include <iostream>
#include "phonebook.hpp"

void	PhoneBook::add(int i)
{
	if (i > 8)
		i -= 8;
	std::cout << "first name" << std::endl;
	std::cin >> contact[i].firstName;
	std::cout << "last name" << std::endl;
	std::cin >> contact[i].lastName;
	std::cout << "nickname" << std::endl;
	std::cin >> contact[i].nickName;
	std::cout << "phone number" << std::endl;
	std::cin >> contact[i].phoneNumber;
	std::cout << "darkest secret" << std::endl;
	std::cin >> contact[i].darkestSecret;
}

void	PhoneBook::search(int i)
{
	std::cout << "index: " << i << std::endl;
	std::cout << "first name: " << contact[i].firstName << std::endl;
	std::cout << "last name: " << contact[i].lastName << std::endl;
	std::cout << "nickname: " << contact[i].nickName << std::endl;
}

void	exit(void)
{

}

int main(void)
{
	PhoneBook	book;
	std::string	command;
	int			i = 0;
	
	book.add(i);
	book.search(i);
	std::cin >> command;

	exit();
	return (0);
}