#include "human.hpp"

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	std::cout << name << " is created" << std::endl;
}

void	HumanA::attack(void)
{
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;

}

HumanA::~HumanA()
{
}

HumanB::HumanB(std::string name) : name(name)
{
	std::cout << name << " is created" << std::endl;
}

void	HumanB::setWeapon(Weapon *weapon)
{
	this->weapon = weapon;
}

void	HumanB::attack(void)
{
	if (this->weapon->getType().compare(""))
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
	else
		std::cout << this->name << " has no weapon" <<  std::endl;
}

HumanB::~HumanB()
{
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
		jim.setWeapon(&club);
		jim.attack();
		club.setType("");
		jim.attack();
	}
return 0;
}