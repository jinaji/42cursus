#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_num = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_num = f.getRawBits();
	return (*this);
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_num = n << 8;
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constuctor called" << std::endl;
	this->fixed_num = roundf(f * (1 << 8));
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_num);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->fixed_num = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)(this->fixed_num) / (1 << 8)); 
}

int		Fixed::toInt(void)	const
{
	return (this->fixed_num / (1 << 8));
}

std::ostream&	operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}