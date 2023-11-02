#include "HumanB.hpp"

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << this->name << " is created" << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon->getType().empty())
		std::cout << this->name << " has no weapon. Punch!" <<  std::endl;
	else
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

HumanB::~HumanB()
{
	std::cout << this->name << " is descructed" << std::endl;
}
