#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>
# include <iostream>

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
};
	std::ostream&	operator<<(std::ostream& os, const Fixed& f);

#endif