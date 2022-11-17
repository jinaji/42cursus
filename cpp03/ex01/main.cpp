#include "ScavTrap.hpp"

int main()
{
	ScavTrap	scav("scav");

	scav.attack("jina");
	scav.takeDamage(10);
	scav.takeDamage(10);
	scav.beReparied(10);
	scav.takeDamage(10);

	std::cout << std::endl;
	scav.guardGate();
	std::cout << std::endl;
}