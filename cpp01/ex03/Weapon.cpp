#include "Weapon.hpp"

Weapon::Weapon(std::string weapon)
{
	this->type = weapon;
}

const std::string& Weapon::getType()
{
	return (this->type);
}

void	Weapon::setType(std::string type)
{
	this->type = type;
}