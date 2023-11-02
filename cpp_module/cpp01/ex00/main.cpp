#include "Zombie.hpp"

int main()
{
	Zombie	b;
	Zombie	*c;

	Zombie("a");
	b = Zombie("b");
	c = newZombie("c");

	std::cout << std::endl;
	
	b.announce();
	c->announce();
	delete c;
}
