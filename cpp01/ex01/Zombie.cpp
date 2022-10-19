#include "Zombie.hpp"

void	Zombie::announce(void)
{
 	std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	std::cout << mName << " created" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->mName = name;
	std::cout << mName << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << mName << " destructed" << std::endl;
}

Zombie*	newZombie(std::string name)
{
	return (new Zombie(name));
}

void	randomChump(std::string name)
{
	Zombie	tmp;

	tmp = Zombie(name);
	tmp.announce();
}
