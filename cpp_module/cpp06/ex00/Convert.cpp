#include "Convert.hpp"
#include <cmath>
#include <unistd.h>

Convert::Convert() : data(0), endptr(NULL)
{
}

Convert::Convert(const Convert& obj)
{
	*this = obj;
}

Convert& Convert::operator=(const Convert& obj)
{
	if (this == &obj)
		return (*this);
	this->data = obj.data;
	return (*this);
}

Convert::~Convert()
{
}

// method
void	Convert::setData(char* val)
{
	if (strlen(val) == 1 && isascii(*val) && !isnumber(*val))
	{
		this->data = static_cast<char>(*val);
		this->endptr = strdup("");
	}
	else
		this->data = strtod(val, &endptr);
}

char	Convert::toChar()
{
	return (static_cast<char>(this->data));
}

int		Convert::toInt()
{
	return (static_cast<int>(this->data));
}

float	Convert::toFloat()
{
	return (static_cast<float>(this->data));
}

double	Convert::toDouble()
{
	return (static_cast<double>(this->data));
}

void	Convert::printChar()
{
	char tData =  this->toChar();
	std::string		tmpString = static_cast<std::string>(this->endptr);

	if ((tmpString.back() == 'f' && tmpString.length() != 1))
		std::cout << "char: " << "imposible" << std::endl;
	else if (tmpString.empty() == false && tmpString.back() != 'f')
		std::cout << "char: " << "imposible" << std::endl;
	else if (isprint(data) == true)
		std::cout << "char: " << "'" << tData << "'" << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
}

void	Convert::printInt()
{
	int	tData =  this->toInt();
	std::string		tmpString = static_cast<std::string>(this->endptr);

	if ((tmpString.back() == 'f' && tmpString.length() != 1))
		std::cout << "int: " << "imposible" << std::endl;
	else if (this->data > INT_MAX || this->data < INT_MIN)
		std::cout << "int: overflow" << std::endl;
	else if (tmpString.empty() == false && tmpString.back() != 'f')
		std::cout << "int: " << "imposible" << std::endl;
	else
		std::cout << "int: " << tData << std::endl;
}

void	Convert::printFloat()
{
	float	tData =  this->toFloat();
	std::string		tmpString = static_cast<std::string>(this->endptr);

	if ((tmpString.back() == 'f' && tmpString.length() != 1))
		std::cout << "float: " << "nanf" << std::endl;
	else if (tmpString.empty() == false && tmpString.back() != 'f')
		std::cout << "float: " << "nanf" << std::endl;
	else if (tData == static_cast<int>(tData))
		std::cout << "float: " << tData << ".0f" << std::endl;
	else
		std::cout << "float: " << tData << "f" << std::endl;
}

void	Convert::printDouble()
{
	double	tData =  this->toDouble();
	std::string		tmpString = static_cast<std::string>(this->endptr);

	if ((tmpString.back() == 'f' && tmpString.length() != 1))
		std::cout << "double: " << "nan" << std::endl;
	else if (tmpString.empty() == false && tmpString.back() != 'f')
		std::cout << "double: " << "nan" << std::endl;
	else if (tData == static_cast<int>(tData))
		std::cout << "double: " << tData << ".0" << std::endl;
	else
		std::cout << "double: " << tData << std::endl;
}
