#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;
		int		index;

	public:
		void showAll();
		void display();
		void addContact(int i);
		void fillContact(std::string &str);
		std::string informDisplay(std::string inform);
};

#endif