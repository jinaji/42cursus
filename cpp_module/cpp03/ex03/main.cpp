#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap	dia("dia");

	std::cout << std::endl;

	dia.attack("jina");
	dia.takeDamage(10);
	dia.takeDamage(10);
	dia.beReparied(10);
	dia.takeDamage(10);

	std::cout << std::endl;
	dia.guardGate();

	std::cout << std::endl;  
	dia.highFivesGuys();

	std::cout << std::endl;
	dia.whoAmI();
	std::cout << std::endl;
}