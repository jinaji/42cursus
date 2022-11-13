#include "PhoneBook.hpp"

void	PhoneBook::add()
{
	int	index;

	index = this->count % 8;
	contact[index].index = index;
	std::cout << "first name: ";
	while (contact[index].firstName.length() < 1)
		std::getline(std::cin, contact[index].firstName);
	std::cout << "last name: ";
	while (contact[index].lastName.length() < 1)
		std::getline(std::cin, contact[index].lastName);
	std::cout << "nickname: ";
	while (contact[index].nickName.length() < 1)
		std::getline(std::cin, contact[index].nickName);
	std::cout << "phone number: ";
	while (contact[index].phoneNumber.length() < 1)
		std::getline(std::cin, contact[index].phoneNumber);
	std::cout << "darkest secret: ";
	while (contact[index].darkestSecret.length() < 1)
		std::getline(std::cin, contact[index].darkestSecret);
	this->count++;
}

std::string	inform_display(std::string inform)
{
	std::string	tmp;
	int			len;
	tmp = inform.data();
	len = inform.length();
	if (len > 10)
	{
		tmp.resize(10);
	}
	else
	{
		int i = 10 - len;
		for (; i; i--)
			tmp.insert(0, " ");
	}
	tmp[9] = '.';
	return (tmp);
}

void	PhoneBook::display(int i)
{
	std::cout << "index: " << "         " << contact[i].index << " | ";
	std::cout << "first name: " << inform_display(contact[i].firstName) << " | ";
	std::cout << "last name: " << inform_display(contact[i].lastName) << " | ";
	std::cout << "nickname: " << inform_display(contact[i].nickName) << std::endl;
}

void	PhoneBook::display_index(int i)
{
	std::cout << "first name: " << this->contact[i].firstName << std::endl;
	std::cout << "last name: " << this->contact[i].lastName << std::endl;
	std::cout << "nickname: " << this->contact[i].nickName << std::endl;
	std::cout << "phone number: " << this->contact[i].phoneNumber << std::endl;
	std::cout << "darkest secret: " << this->contact[i].darkestSecret << std::endl;
}

void	PhoneBook::search_display()
{
	if (count > 8)
	{
		for (int j = 0; 8 > j; j++)
			display(j);
	}
	else
	{
		for (int j = 0; count > j; j++)
			display(j);
	}
}

void	PhoneBook::search()
{
	int	index = -1;

	search_display();
	std::cout << "input index" << std::endl;
	std::cin >> index;
	if (!isdigit(index) && index >= 0 && count > index)
		display_index(index);
	else
		std::cout << "wrong index" << std::endl;
	std::cin.clear();
}

void	exit(void)
{
}

int main(void)
{
	PhoneBook	book;
	std::string	command;
	
	// std::cout << "ADD SEARCH EXIT" << std::endl;
	// std::getline (std::cin, command);
	book.count = 0;
	// while (command.compare("EXIT"))
	// {
	// 	if (command.compare("ADD") == 0)
	// 		book.add();
	// 	else if (command.compare("SEARCH") == 0)
	// 		book.search();
	// 	command.clear();
	// 	std::getline (std::cin, command);
	// 	std::cout << "ADD SEARCH EXIT" << std::endl;
	// }
		std::cout << "ADD SEARCH EXIT" << std::endl;
	while (std::getline (std::cin, command))
	{
		if (command.compare("ADD") == 0)
			book.add();
		else if (command.compare("SEARCH") == 0)
			book.search();
		else if (command.compare("EXIT") == 0)
			exit();
		std::cout << "ADD SEARCH EXIT" << std::endl;
	}
	return (0);
}