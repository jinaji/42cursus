#include "ScavTrap.hpp"

int main()
{
	ScavTrap	tmp("tmp");

	tmp.attack("jina");
	tmp.takeDamage(10);
	tmp.takeDamage(10);
	tmp.beReparied(10);
	tmp.takeDamage(10);
}