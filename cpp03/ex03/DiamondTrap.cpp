#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap()
{
	std::cout << "DiamondTrap default constructor called" << std::endl;
	ClapTrap::name += "_clap_name";
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 30;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	std::cout << "DiamondTrap " << name << " created" << std::endl;
	this->name = name;
	ClapTrap::name += "_clap_name";
	this->HitPoint = 100;
	this->EnergyPoint = 50;
	this->AttackDamage = 30;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj)
{
	*this = obj;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	ClapTrap::name = obj.ClapTrap::name;
	this->name = obj.name;
	this->AttackDamage = obj.AttackDamage;
	this->EnergyPoint = obj.EnergyPoint;
	this->HitPoint = obj.HitPoint;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap Name: " << this->name << std::endl;
	std::cout << "ClapTrap Name: " << ClapTrap::name << std::endl;
}