#include "ClapTrap.hpp"

int main()
{
	ClapTrap	clap("clap");
	std::cout << std::endl;

	clap.attack("jina");
	clap.takeDamage(5);
	clap.beReparied(5);
	clap.takeDamage(10);
	std::cout << std::endl;
	
	clap.takeDamage(10);
	clap.beReparied(5);
	clap.attack("jina");
}