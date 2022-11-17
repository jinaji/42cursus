#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constuctor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
	std::cout << "ClapTrap " << name << " has created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	*this = obj;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	this->name = obj.name;
	this->attackDamage = obj.attackDamage;
	this->energyPoint = obj.energyPoint;
	this->hitPoint = obj.hitPoint;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
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
	std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
	this->energyPoint -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoint <= 0)
	{
		std::cout << name << " has no hit point" << std::endl;
		return ;
	}
	else
	{
		this->hitPoint -= amount;
		if (this->hitPoint < 0)
			this->hitPoint = 0;
		std::cout << "ClapTrap " << name << " take damage " << amount << " of hit point" << std::endl;
	}
}

void	ClapTrap::beReparied(unsigned int amount)
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
	std::cout << "ClapTrap " << name << " repair " << amount << " points of hit point" << std::endl;
	this->hitPoint += amount;
	this->energyPoint -= 1;
}
