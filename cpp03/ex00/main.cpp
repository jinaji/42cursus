#include "ClapTrap.hpp"

int main()
{
	ClapTrap	tmp("tmp");

	tmp.attack("jina");
	tmp.takeDamage(10);
	tmp.takeDamage(10);
	tmp.beReparied(10);
	tmp.takeDamage(10);
}