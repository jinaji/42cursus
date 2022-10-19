#include "human.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
	this->name = name;
	this->weapon = weapon;
}

void	HumanB::setWeapon(Weapon weapon)
{
	this->weapon = &weapon;
}

int main()
{
	{
	Weapon club = Weapon("crude spiked club");
	HumanA bob("Bob", club);
	bob.attack();
	club.setType("some other type of club");
	bob.attack();
	}
	{
	Weapon club = Weapon("crude spiked club");
	HumanB jim("Jim");
	jim.setWeapon(club);
	jim.attack();
	club.setType("some other type of club");
	jim.attack();
	}
return 0;
}