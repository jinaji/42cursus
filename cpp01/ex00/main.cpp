#include "Zombie.hpp"

int main()
{
	Zombie	*a;

	a = newZombie("a");
	Zombie("b").announce();
	a->announce();
	delete a;
}
