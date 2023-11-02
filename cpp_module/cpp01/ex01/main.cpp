#include "Zombie.hpp"

int main()
{
	Zombie* horde = zombieHorde(3, "hihi");
	for (int i = 0; 3 > i; i++)
		horde[i].announce();
	delete[] horde;
}