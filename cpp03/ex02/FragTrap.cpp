#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " created" << std::endl;
	this->hitPoint = 100;
	this->energyPoint = 100;
	this->attackDamage = 30;
}

FragTrap& FragTrap::operator=(const FragTrap& fragtrap)
{
	this->attackDamage = fragtrap.attackDamage;
	this->energyPoint = fragtrap.energyPoint;
	this->hitPoint = fragtrap.hitPoint;
	this->name = fragtrap.name;
	return (*this);
}

FragTrap::FragTrap(const FragTrap& fragtrap)
{
	*this = fragtrap;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "Positive high fives request from " << this->name << std::endl;
}