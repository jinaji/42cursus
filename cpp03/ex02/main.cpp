#include "FragTrap.hpp"

int main()
{
	FragTrap	frag("frag");
	std::cout << std::endl;

	frag.attack("jina");
	frag.takeDamage(10);
	frag.takeDamage(10);
	frag.beReparied(10);
	frag.takeDamage(10);

	std::cout << std::endl;
	frag.highFivesGuys();
	std::cout << std::endl;
}