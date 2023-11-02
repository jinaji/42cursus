#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <map>
# include <fcntl.h>
# include <fstream>
# include <stdlib.h>
# include <list>
# include <sstream>

class BitcoinExchange
{
	private:
	BitcoinExchange(const BitcoinExchange& obj);
	BitcoinExchange& operator=(const BitcoinExchange& obj);

	public:
	BitcoinExchange();
	~BitcoinExchange();

	std::map<std::string, float>	_db;
	// std::map<std::string, float> _input;
	std::list<std::string>			_date;
	std::list<float>				_value;
	std::list<float>				_calculatedValue;

	void createDb();
	void createList(char *file);
	void displayList();

	void caculate(float& value, std::string& date);
	std::string checkValidDay(float& value, std::string& date);


	class errorInDatabase : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Error");
		}
	};
};

#endif