#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap " << name << " created" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& obj)
{
	*this = obj;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->EnergyPoint = obj.EnergyPoint;
	this->HitPoint = obj.HitPoint;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->EnergyPoint <= 0)
	{
		std::cout << name << " has no energy point" << std::endl;
		return ;
	}
	else if (this->HitPoint <= 0)
	{
		std::cout << name << " has no hit point" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoint -= 1;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << name << " destructor called" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << this->name << " is now in Gate keeper mode." << std::endl;
}