#ifndef CONVERT_HPP
# define CONVERT_HPP

#include <string>
#include <iostream>

class Convert
{
private:
	double	data;
	char	*endptr;
public:
	Convert();
	Convert(const Convert& obj);
	const Convert& operator=(const Convert& obj);
	~Convert();

	void	setData(char* val);
	char	toChar();
	int		toInt();
	float	toFloat();
	double	toDouble();

	void	printChar();
	void	printInt();
	void	printFloat();
	void	printDouble();
};


#endif