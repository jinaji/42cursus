#include "phoneBook.hpp"

void	phoneBook::add()
{
	if (count >= 8)
		count -= 8;
	contact[count].index = count;
	std::cout << "first name: ";
	std::getline(std::cin, contact[count].firstName);
	std::cout << "last name: ";
	std::getline(std::cin, contact[count].lastName);
	std::cout << "nickname: ";
	std::getline(std::cin, contact[count].nickName);
	std::cout << "phone number: ";
	std::getline(std::cin, contact[count].phoneNumber);
	std::cout << "darkest secret: ";
	std::getline(std::cin, contact[count].darkestSecret);
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

void	phoneBook::display(int i)
{
	std::cout << "index: " << contact[i].index << " | ";
	std::cout << "first name: " << inform_display(contact[i].firstName) << " | ";
	std::cout << "last name: " << inform_display(contact[i].lastName) << " | ";
	std::cout << "nickname: " << inform_display(contact[i].nickName) << std::endl;
}

void	phoneBook::search_display(int i)
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

void	phoneBook::search()
{
	int	index;

	search_display(-1);
	std::cout << "input index" << std::endl;
	std::cin >> index;
	if (!isdigit(index) && index >= 0 && count > index)
		display(index);
	else
		std::cout << "wrong index" << std::endl;
	std::cin.clear();
}

void	exit(void)
{
}

int main(void)
{
	phoneBook	book;
	std::string	command;
	
	// std::cin >> command;
	std::cout << "ADD SEARCH EXIT" << std::endl;
	std::getline (std::cin, command);
	book.count = 0;
	// std::cin.clear();
	// clearerr(stdin);
	while (command.compare("EXIT"))
	{
		if (command.compare("ADD") == 0)
			book.add();
		else if (command.compare("SEARCH") == 0)
			book.search();
		command.clear();
		// std::cin >> command;
		std::getline (std::cin, command);
	}
	exit();
	return (0);
}