#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	this->type = weapon;
}

Weapon::~Weapon()
{
	std::cout << this->getType() << " is destructed" << std::endl;
}

const std::string& Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}