#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl		tmp;
	std::string	str;
	int			level;

	if (ac != 2)
	{
		tmp.nothing();
		return (1);
	}
	str = av[1];
	level = tmp.getLevel(str);
	switch(level)
	{
		case NOTHING :
		{
			tmp.nothing();
			break ;
		}
		case DEBUG :
			tmp.complain("DEBUG");
		case INFO :
			tmp.complain("INFO");
		case WARNING :
			tmp.complain("WARNING");
		case ERROR :
			tmp.complain("ERROR");
	}
}