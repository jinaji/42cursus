#include <iostream>
#include "phonebook.hpp"

void	PhoneBook::add()
{
	if (count >= 8)
		count -= 8;
	contact[count].index = count;
	std::cout << "first name" << std::endl;
	std::cin >> contact[count].firstName;
	std::cout << "last name" << std::endl;
	std::cin >> contact[count].lastName;
	std::cout << "nickname" << std::endl;
	std::cin >> contact[count].nickName;
	std::cout << "phone number" << std::endl;
	std::cin >> contact[count].phoneNumber;
	std::cout << "darkest secret" << std::endl;
	std::cin >> contact[count].darkestSecret;
	count++;
}

std::string	inform_display(std::string inform)
{
	std::string	tmp;
	int			len;

	tmp = inform.data();
	len = inform.length();
	if (len > 10)
	{
		for (int i = 0; 9 > i; i++)
			tmp[i] = inform[i];
		tmp[9] = '.';
	}
	else
	{
		for (int i = 0; len - 1 > i; i++)
			tmp[i] = inform[i];
		tmp[len - 1] = '.';
	}
	return (tmp);
}

void	PhoneBook::display(int i)
{
	std::cout << "index     | " << contact[i].index << std::endl;
	std::cout << "first name| " << inform_display(contact[i].firstName) << std::endl;
	std::cout << "last name | " << contact[i].lastName << std::endl;
	std::cout << "nickname  | " << contact[i].nickName << std::endl;
}

void	PhoneBook::search_display(int i)
{
	if (i == -1)
	{
		for (int j = 0; count > j; j++)
			display(j);
		return ;
	}
	else
		display(i);
}

void	PhoneBook::search()
{
	int	index;

	// std::cout << "index" << std::endl;
	// std::cout << "first name" << std::endl;
	// std::cout << "last name" << std::endl;
	// std::cout << "nickname" << std::endl;

	search_display(-1);

	std::cout << "index gogo" << std::endl;
	std::cin >> index;
	if (index >= 0 && count > index)
		display(index);
	else
		std::cout << "wrong index" << std::endl;
	// std::cout << "index: " << i << std::endl;
	// std::cout << "first name: " << contact[i].firstName << std::endl;
	// std::cout << "last name: " << contact[i].lastName << std::endl;
	// std::cout << "nickname: " << contact[i].nickName << std::endl;
}

void	exit(void)
{

}

int main(void)
{
	PhoneBook	book;
	std::string	command;
	
	std::cin >> command;
	book.count = 0;
	// memset(&book, 0, sizeof(PhoneBook));
	while (command.compare("EXIT"))
	{
		if (command.compare("ADD") == 0)
			book.add();
		else if (command.compare("SEARCH") == 0)
			book.search();
		command.clear();
		std::cin >> command;
	}
	exit();
	return (0);
}