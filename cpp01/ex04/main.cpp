#include "replace.hpp"
#include <fstream>

int main(int ac, char **av)
{
	std::ifstream	file;
	std::string	s1;
	std::string	s2;
	std::string	input;
	std::string save;

	if (ac != 4)
		return (1);
	file.open(av[1]);
	if (file.is_open())
	{
		while (!file.eof())
		{
			getline(file, input);
			save.append(input);
		}
	}
	s1 = av[2];
	s2 = av[3];
}