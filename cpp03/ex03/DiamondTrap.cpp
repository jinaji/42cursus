#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::name += "_clap_name";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	std::cout << "DiamondTrap " << name << " created" << std::endl;
	this->name = name;
	ClapTrap::name += "_clap_name";
	this->hitPoint = 100;
	this->energyPoint = 50;
	this->attackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	this->name = obj.name;
	this->attackDamage = obj.attackDamage;
	this->energyPoint = obj.energyPoint;
	this->hitPoint = obj.hitPoint;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
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
	std::cout << "DiamondTrap " << name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint -= 1;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name " << this->name << std::endl;
	std::cout << "ClapTrap Name " << ClapTrap::name << std::endl;
}