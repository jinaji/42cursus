#include "FragTrap.hpp"

int main()
{
	FragTrap	tmp("tmp");

	tmp.attack("jina");
	tmp.takeDamage(10);
	tmp.takeDamage(10);
	tmp.beReparied(10);
	tmp.takeDamage(10);
	tmp.highFivesGuys();
}