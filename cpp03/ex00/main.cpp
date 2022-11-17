#include "ClapTrap.hpp"

int main()
{
	ClapTrap	clap("clap");

	clap.attack("jina");
	clap.takeDamage(5);
	clap.beReparied(5);
	clap.takeDamage(10);
	clap.takeDamage(10);
	clap.beReparied(5);
}