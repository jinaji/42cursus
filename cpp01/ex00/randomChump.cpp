#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	tmp;

	tmp = Zombie(name);
	tmp.announce();
}
