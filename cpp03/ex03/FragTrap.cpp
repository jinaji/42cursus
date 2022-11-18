#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " created" << std::endl;
	this->HitPoint = 100;
	this->EnergyPoint = 100;
	this->AttackDamage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
	this->AttackDamage = fragtrap.AttackDamage;
	this->EnergyPoint = fragtrap.EnergyPoint;
	this->HitPoint = fragtrap.HitPoint;
	this->name = fragtrap.name;
	return (*this);
}

FragTrap::FragTrap(const FragTrap& fragtrap)
{
	*this = fragtrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Positive high fives request from " << this->name << std::endl;
}