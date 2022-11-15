#include "replace.hpp"
#include <fstream>
#include <iostream>

int main(int ac, char **av)
{
	std::ifstream	infile;
	std::string	s1;
	std::string	s2;
	std::string	input;
	std::string save;
	std::size_t	pos = 0;
	std::size_t	len1;
	std::size_t	len2;

	if (ac != 4)
	{
		std::cout << "Argument error" << std::endl;
		return (1);
	}
	infile.open(av[1]);
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			std::getline(infile, input, '\0');
			save.append(input);
		}
	}
	else
	{
		std::cout << "File error" << std::endl;
		return (1);
	}
	s1 = av[2];
	s2 = av[3];
	if (s1.empty())
	{
		std::cout << "Not valid input" << std::endl;
		return (1);
	}
	len1 = s1.length();
	len2 = s2.length();
	pos = save.find(s1);
	while (pos != std::string::npos) // find() 실패시 npos 반환
	{
		save.erase(pos, len1);
		save.insert(pos, s2);
		pos = save.find(s1, pos + len2);
	}
	std::ofstream out((std::string)av[1] + ".replace");
	out << save;
	out.close();
	return (0);
}
