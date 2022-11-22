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

const Convert& Convert::operator=(const Convert& obj)
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
	this->data = strtod(val, &endptr);
	std::cout << this->data << std::endl;
	if (endptr != '\0')
		std::cout << "endptr " << (std::string)endptr << std::endl;
}

char	Convert::toChar()
{
	return ((char)this->data);
}

int		Convert::toInt()
{
	return ((int)this->data);
}

float	Convert::toFloat()
{
	return ((float)this->data);
}

double	Convert::toDouble()
{
	return ((double)this->data);
}

void	Convert::printChar()
{
	char tData =  this->toChar();
	std::string		tmpString = (std::string)this->endptr;

	if ((tmpString.back() == 'f' && tmpString.length() != 1))
		std::cout << "char: " << "imposible" << std::endl;
	else if (tmpString.empty() == false && tmpString.back() != 'f')
		std::cout << "char: " << "imposible" << std::endl;
	else if (isprint(data) == true)
		std::cout << "char: " << tData << std::endl;
	else
		std::cout << "char: " << "Non displayable" << std::endl;
}

void	Convert::printInt()
{
	int	tData =  this->toInt();
	std::string		tmpString = (std::string)this->endptr;

	if (this->data > INT_MAX || this->data < INT_MIN)
		std::cout << "int: overflow" << std::endl;
	else if ((tmpString.back() == 'f' && tmpString.length() != 1))
		std::cout << "int: " << "imposible" << std::endl;
	else if (tmpString.empty() == false && tmpString.back() != 'f')
		std::cout << "int: " << "imposible" << std::endl;
	else
		std::cout << "int: " << tData << std::endl;
}

void	Convert::printFloat()
{
	float	tData =  this->toFloat();
	std::string		tmpString = (std::string)this->endptr;

	if ((tmpString.back() == 'f' && tmpString.length() != 1))
		std::cout << "float: " << "nanf" << std::endl;
	else if (tmpString.empty() == false && tmpString.back() != 'f')
		std::cout << "float: " << "nanf" << std::endl;
	else if (tData == (int)tData)
		std::cout << "float: " << tData << ".0f" << std::endl;
	else
		std::cout << "float: " << tData << "f" << std::endl;
}

void	Convert::printDouble()
{
	double	tData =  this->toDouble();
	std::string		tmpString = (std::string)this->endptr;

	if ((tmpString.back() == 'f' && tmpString.length() != 1))
		std::cout << "double: " << "nan" << std::endl;
	else if (tmpString.empty() == false && tmpString.back() != 'f')
		std::cout << "double: " << "nan" << std::endl;
	else if (tData == (int)tData)
		std::cout << "double: " << tData << ".0" << std::endl;
	else
		std::cout << "double: " << tData << std::endl;
}
