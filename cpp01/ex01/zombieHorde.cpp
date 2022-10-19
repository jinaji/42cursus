#include "Zombie.hpp"

void	Zombie::setZombieName(std::string name)
{
	this->mName = name;
}

Zombie*	zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 0; N > i; i++)
		horde[i].setZombieName(name);

	return (horde);
}

int main()
{
	Zombie* horde = zombieHorde(3, "hihi");
	for (int i = 0; 3 > i; i++)
		horde[i].announce();
	delete[] horde;
}