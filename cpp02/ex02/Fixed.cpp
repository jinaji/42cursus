#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_num = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& obj)
{
	*this = obj;
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	this->fixed_num = obj.getRawBits();
	return (*this);
}

Fixed::Fixed(const int n)
{
	// std::cout << "Int constructor called" << std::endl;
	this->fixed_num = n << this->bit;
}

Fixed::Fixed(const float obj)
{
	// std::cout << "Float constuctor called" << std::endl;
	this->fixed_num = roundf(obj * (1 << this->bit));
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
	return ((float)(this->fixed_num) / (1 << this->bit)); 
}

int		Fixed::toInt(void)	const
{
	return (this->fixed_num / (1 << this->bit));
}

/* a(this) > b(param) */
// comparison operators
bool	Fixed::operator>(const Fixed& obj)
{
	if (this->fixed_num > obj.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<(const Fixed& obj)
{
	if (this->fixed_num < obj.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator>=(const Fixed& obj)
{
	if (this->fixed_num >= obj.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<=(const Fixed& obj)
{
	if (this->fixed_num <= obj.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator==(const Fixed& obj)
{
	if (this->fixed_num == obj.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator!=(const Fixed& obj)
{
	if (this->fixed_num == obj.fixed_num)
		return (0);
	else
		return (1);
}

// arithmetic operators
Fixed Fixed::operator+(const Fixed& obj)
{
	// this->fixed_num += obj.fixed_num;
	// return (*this);
	
	Fixed	tmp;
	tmp.fixed_num = this->fixed_num + obj.fixed_num;
	return (tmp);
}

Fixed	Fixed::operator-(const Fixed& obj)
{
	Fixed	tmp;
	tmp.fixed_num = this->fixed_num - obj.fixed_num;
	return (tmp);
	// this->fixed_num -= obj.fixed_num;
	// return (*this);
}

Fixed	Fixed::operator*(const Fixed& obj)
{	
	Fixed	tmp;
	float	ret;

	ret = this->toFloat() * obj.toFloat();
	tmp.fixed_num = roundf(ret * (1 << this->bit));
	return (tmp);
}

Fixed	Fixed::operator/(const Fixed& obj)
{
	Fixed	tmp;
	float	ret;

	ret = this->toFloat() / obj.toFloat();
	tmp.fixed_num = roundf(ret * (1 << this->bit));
	return (tmp);
}

// increment / decrement operators
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

const Fixed	Fixed::operator++(int) // post
{
	const Fixed	tmp = *this;

	// if (fixed_num == 0)
	// 	this->fixed_num = this->fixed_num + 1;
	// else
	// 	this->fixed_num = this->fixed_num + fixed_num;
	this->fixed_num += 1;
	return (tmp);
}

const Fixed	Fixed::operator--(int)
{
	const Fixed	tmp = *this;

	// if (fixed_num == 0)
	// 	this->fixed_num = this->fixed_num + 1;
	// else
	// 	this->fixed_num = this->fixed_num - fixed_num;
	// this->fixed_num = this->fixed_num - 1;
	this->fixed_num -= 1;
	return (tmp);
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

std::ostream&	operator<<(std::ostream& os, const Fixed& obj)
{
	os << obj.toFloat();
	return (os);
}