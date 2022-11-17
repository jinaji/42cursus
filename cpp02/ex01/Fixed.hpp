#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

class Fixed
{
private:
	int					fixed_num;
	static const int	bit = 8;
public:
	Fixed();
	Fixed(const Fixed& obj);
	Fixed& operator=(const Fixed& obj);
	~Fixed();

	int		getRawBits(void) const; // returns the raw value of the fixed-point value
	void	setRawBits(int const raw); // sets the raw value of the fixed-point number

	Fixed(const int n);
	Fixed(const float obj);

	float	toFloat(void) const;
	int		toInt(void)	const;
};

std::ostream&	operator<<(std::ostream& os, const Fixed& obj);

#endif