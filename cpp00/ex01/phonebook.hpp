#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>

class contact
{
	private:

	public:
	std::string	firstName;
	std::string	lastName;
	std::string	nickName;
	std::string	phoneNumber;
	std::string	darkestSecret;
	int		index;
};

class phoneBook
{

	private:

	public:
	contact	contact[8];
	int		count;
	void	add();
	void	search();
	void	exit();
	void	search_display(int i);
	void	display(int i);
};

#endif