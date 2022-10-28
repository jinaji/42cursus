#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : name(ClapTrap::name)
{
	std::cout << "DiamondTrap " << name << " created" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 30;
	
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondtrap)
{
	*this = diamondtrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondtrap)
{
}

DiamondTrap::~DiamondTrap()
{
}

DiamondTrap::attack() : (ScavTrap::attack)
{
}