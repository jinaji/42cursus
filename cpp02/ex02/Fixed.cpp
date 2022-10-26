#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fixed_num = 0;
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& f)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	this->fixed_num = f.getRawBits();
	return (*this);
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixed_num = n << 8;
}

Fixed::Fixed(const float f)
{
	// std::cout << "Float constuctor called" << std::endl;
	this->fixed_num = roundf(f * (1 << 8));
}

int	Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed_num);
}

void	Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

/* a(this) > b(param) */

bool	Fixed::operator>(const Fixed& f)
{
	if (this->fixed_num > f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<(const Fixed& f)
{
	if (this->fixed_num < f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator>=(const Fixed& f)
{
	if (this->fixed_num >= f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<=(const Fixed& f)
{
	if (this->fixed_num <= f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator==(const Fixed& f)
{
	if (this->fixed_num == f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator!=(const Fixed& f)
{
	if (this->fixed_num == f.fixed_num)
		return (0);
	else
		return (1);
}


Fixed& Fixed::operator+(const Fixed& f)
{
	this->fixed_num += f.fixed_num;
	return (*this);
}

Fixed&	Fixed::operator-(const Fixed& f)
{
	this->fixed_num -= f.fixed_num;
	return (*this);
}

Fixed&	Fixed::operator*(const Fixed& f)
{
	this->fixed_num *= f.fixed_num;
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed& f)
{
	this->fixed_num /= f.fixed_num;
	return (*this);
}


Fixed&	Fixed::operator++() // pre
{
	this->fixed_num += 1;
	return (*this);
}

Fixed&	Fixed::operator--()
{
	this->fixed_num -= 1;
	return (*this);
}

Fixed&	Fixed::operator++(int fixed_num) // post
{
	this->fixed_num = fixed_num + 1;
	return (*this);
}

Fixed&	Fixed::operator--(int fixed_num)
{
	this->fixed_num = fixed_num - 1;
	return (*this);
}

Fixed&	Fixed::min(Fixed& a, Fixed& b)
{
	if (a.fixed_num < b.fixed_num)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b)
{
	if (a.fixed_num < b.fixed_num)
		return (a);
	else
		return (b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b)
{
	if (a.fixed_num > b.fixed_num)
		return (a);
	else
		return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
	if (a.fixed_num > b.fixed_num)
		return (a);
	else
		return (b);
}

std::ostream&	operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}