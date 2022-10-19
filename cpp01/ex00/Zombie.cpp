#include "Zombie.hpp"

void	Zombie::announce(void)
{
 	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie()
{
	std::cout << name << " created" << std::endl;
}

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << name << " created" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << name << " destructed" << std::endl;
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

int main()
{
	Zombie	*a;

	a = newZombie("a");
	Zombie("b").announce();
	a->announce();
	delete a;
}