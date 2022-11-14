#include "Zombie.hpp"

void	Zombie::announce(void)
{
 	std::cout << mName << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	std::cout << "Zombie created" << std::endl;
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
