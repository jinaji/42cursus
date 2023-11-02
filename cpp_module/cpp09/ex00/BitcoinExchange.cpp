#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}


void BitcoinExchange::createDb()
{
	std::ifstream					in("data.csv");
	std::string						__data;
	std::string						__date;
	float							__rate;
	int								__pos;
	char							**endptr = NULL;

	if (in.is_open())
	{
		while (in >> __data)
		{
			// std::cout << __data << std::endl;
			__pos = __data.find(',');
			__date = __data.substr(0, __pos);
			__rate = strtof((__data.substr(__pos + 1)).c_str(), endptr);
			if (__date == "date")
				continue;
			if (__date.length() != 10 || __rate < 0)
				throw(errorInDatabase());
			_db.insert(std::pair<std::string, float>(__date, __rate));
		}
	}
	else
		std::cout << "Error: could not open file." << std::endl;
}

void BitcoinExchange::createList(char *file)
{
	std::ifstream					in(file);
	std::string						__data;
	std::string						__date;
	double							__value;
	size_t							__pos;
	char							**endptr = NULL;

	// if (static_cast<std::string>(file) == "btc")
	// 	return ;
	if (in.is_open())
	{
		while (std::getline(in, __data))
		{
			// std::cout << __data << std::endl;
			__pos = __data.find('|');
			__date = __data.substr(0, __pos - 1);
			__value = strtod((__data.substr(__pos + 2)).c_str(), endptr);
			// std::cout << __date << " * " << __value << std::endl;
			if (__date == "date")
				continue;
			if (__value < 0)
				__value = -1;
			if (__pos == std::string::npos)
				__value = -2;
			if (__value > 2147483647)
				__value = -3;
			_date.push_back(__date);
			_value.push_back(static_cast<float>(__value));
			// std::cout << _input.size() << std::endl;
			__data.clear();
		}
	}
	else
		std::cout << "Error: could not open file." << std::endl;
}

void BitcoinExchange::caculate(float& value, std::string& date)
{
	if (value == -1)
	{
		date = "Error: not a positive number.";
		return ;
	}
	else if (value == -2)
	{
		date = "Error: bad input => " + date;
		return ;
	}
	else if (value == -3)
	{
		date = "Error: too large a number.";
		return ;
	}
	else if (value == -4)
		return ;
	
	std::map<std::string, float>::iterator it = _db.lower_bound(date);
	if (date.substr(1, 5) == "Error")
	{
		value = -4;
		return ;
	}
	if (it == _db.end())
	{
		it--;
		value = value * (*it).second;
	}
	else if ((*it).first.substr(9, 2) == date.substr(9, 2))
	{
		value *= (*it).second;
	}
	else
	{
		it--;
		value *= (*it).second;
	}
}

std::string BitcoinExchange::checkValidDay(float& value, std::string& date)
{
	std::stringstream ss;
	std::string __year;
	std::string __month;
	std::string __day;
	int 		__num;
	int 		__num2;
	std::string	__ret = date;

	__year = date.substr(0, 4);
	ss.str(__year);
	ss >> __num;
	if (__num < 2009 || __num > 2022)
	{
		value = -4;
		return ("Error: bad input => " + date);
	}
	ss.clear();

	__month = date.substr(5, 2);
	ss.str(__month);
	ss >> __num;
	if (__num < 0 || __num > 12)
	{
		value = -4;
		return ("Error: bad input => " + date);
	}
	ss.clear();

	__day = date.substr(8, 2);
	ss.str(__day);
	ss >> __num2;

	if (__num2 < 0 || __num2 > 31)
	{
		value = -4;
		return ("Error: bad input => " + date);
	}
	else if (__num == 2 && __num2 > 28)
	{
		value = -4;
		return ("Error: bad input => " + date);
	}
	else if ((__num == 4 || __num == 6 || __num == 9 || __num == 11) && __num2 > 30)
	{
		value = -4;
		return ("Error: bad input => " + date);
	}
	return (__ret);
}

void BitcoinExchange::displayList()
{
	_calculatedValue = _value;
	std::list<float>::iterator ite = _calculatedValue.begin();
	std::list<float>::iterator iter = _value.begin();
	
	for (std::list<std::string>::iterator it = _date.begin(); it != _date.end(); it++, ite++, iter++)
	{
		*it = checkValidDay(*ite, *it);
		caculate(*ite, *it);
		if (*ite > -1)
			std::cout << (*it) << " => " << (*iter) << " = " << (*ite) << std::endl;
		else
			std::cout << (*it) << std::endl;
	}
}