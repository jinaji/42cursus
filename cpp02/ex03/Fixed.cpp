#include "Fixed.hpp"

Fixed::Fixed()
{
	this->fixed_num = 0;
}

Fixed::~Fixed()
{
}

Fixed::Fixed(const Fixed& f)
{
	*this = f;
}

Fixed& Fixed::operator=(const Fixed& f)
{
	this->fixed_num = f.getRawBits();
	return (*this);
}

Fixed::Fixed(const int n)
{
	this->fixed_num = n << 8;
}

Fixed::Fixed(const float f)
{
	this->fixed_num = roundf(f * (1 << 8));
}

int	Fixed::getRawBits(void) const
{
	return (this->fixed_num);
}

void	Fixed::setRawBits(int const raw)
{
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
// comparison operators
bool	Fixed::operator>(const Fixed& f) const
{
	if (this->fixed_num > f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<(const Fixed& f) const
{
	if (this->fixed_num < f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator>=(const Fixed& f) const
{
	if (this->fixed_num >= f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator<=(const Fixed& f) const
{
	if (this->fixed_num <= f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator==(const Fixed& f) const
{
	if (this->fixed_num == f.fixed_num)
		return (1);
	else
		return (0);
}

bool	Fixed::operator!=(const Fixed& f) const
{
	if (this->fixed_num == f.fixed_num)
		return (0);
	else
		return (1);
}

// arithmetic operators
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
	float	ret;

	ret = this->toFloat() * f.toFloat();
	this->fixed_num = roundf(ret * (1 << 8));
	return (*this);
}

Fixed&	Fixed::operator/(const Fixed& f)
{
	float	ret;

	ret = this->toFloat() / f.toFloat();
	this->fixed_num = roundf(ret * (1 << 8));
	return (*this);
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

Fixed	Fixed::operator++(int fixed_num) // post
{
	Fixed	tmp = *this;

	if (fixed_num == 0)
		this->fixed_num = this->fixed_num + 1;
	else
		this->fixed_num = this->fixed_num + fixed_num;
	return (tmp);
}

Fixed	Fixed::operator--(int fixed_num)
{
	Fixed	tmp = *this;

	if (fixed_num == 0)
		this->fixed_num = this->fixed_num + 1;
	else
		this->fixed_num = this->fixed_num - fixed_num;
	this->fixed_num = this->fixed_num - 1;
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

std::ostream&	operator<<(std::ostream& os, const Fixed& f)
{
	os << f.toFloat();
	return (os);
}