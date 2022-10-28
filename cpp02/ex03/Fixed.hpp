#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>
# include <cmath>


class Fixed
{

private:
	int					fixed_num;
	static const int	n = 8;

public:
	Fixed();
	Fixed(const Fixed& f);
	Fixed& operator=(const Fixed& f);
	~Fixed();

	Fixed(const int n);
	Fixed(float f);

	int		getRawBits(void) const; // returns the raw value of the fixed-point value
	void	setRawBits(int const raw); // sets the raw value of the fixed-point number

	float	toFloat(void) const;
	int		toInt(void)	const;
//  a(this) > b(param)

	public: 
	// comparison operators
	bool	operator>(const Fixed& f) const;
	bool	operator<(const Fixed& f) const;
	bool	operator>=(const Fixed& f) const;
	bool	operator<=(const Fixed& f) const;
	bool	operator==(const Fixed& f) const;
	bool	operator!=(const Fixed& f) const;

	// arithmetic operators
	Fixed&	operator+(const Fixed& f);
	Fixed&	operator-(const Fixed& f);
	Fixed&	operator*(const Fixed& f);
	Fixed&	operator/(const Fixed& f);

	// increment / decrement operators
	Fixed&	operator++(); //pre
	Fixed&	operator--(); 
	Fixed	operator++(int fixed_num); //post
	Fixed	operator--(int fixed_num);

	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif