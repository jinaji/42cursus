#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " created" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavtrap)
{
	*this = scavtrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavtrap)
{
	this->name = scavtrap.name;
	this->attackDamage = scavtrap.attackDamage;
	this->energyPoint = scavtrap.energyPoint;
	this->hitPoint = scavtrap.hitPoint;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->energyPoint <= 0)
	{
		std::cout << name << " has no energy point" << std::endl;
		return ;
	}
	else if (this->hitPoint <= 0)
	{
		std::cout << name << " has no hit point" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint -= 1;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->name << " is now in Gate keeper mode." << std::endl;
}