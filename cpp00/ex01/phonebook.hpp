#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{

	private:

	public:
	contact	contact[8];
	int		count;
	void	add();
	void	search();
	void	exit();
	void	search_display();
	void	display(int i);
	void	display_index(int i);
};

#endif