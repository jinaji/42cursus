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
		return (1);
	infile.open(av[1]);
	if (infile.is_open())
	{
		while (!infile.eof())
		{
			getline(infile, input);
			save.append(input);
		}
	}
	s1 = av[2];
	s2 = av[3];
	if (s1.compare("") == 0)
		return (1);
	len1 = s1.length();
	len2 = s2.length();
	pos = save.find (s1);
	while (pos != std::string::npos)
	{
		save.erase(pos, len1);
		save.insert(pos, s2);
		pos = save.find(s1, pos + len2);
	}
	std::cout << save << "\n";
	std::ofstream out((std::string)av[1] + ".replace");
	out << save << std::endl;
	out.close();
	return (0);
}
