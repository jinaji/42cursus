#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl		harl;
	int			level;

	if (ac != 2)
	{
		harl.nothing();
		return (1);
	}
	level = harl.getLevel((std::string)av[1]);

	switch(level)
	{
		case NOTHING :
		{
			harl.nothing();
			break ;
		}
		case DEBUG :
			harl.complain("DEBUG");
		case INFO :
			harl.complain("INFO");
		case WARNING :
			harl.complain("WARNING");
		case ERROR :
			harl.complain("ERROR");
	}
}