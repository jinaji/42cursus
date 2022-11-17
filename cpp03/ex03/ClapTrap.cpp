#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	std::cout << "ClapTrap Default constuctor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), HitPoint(10), EnergyPoint(10), AttackDamage(0)
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
	this->AttackDamage = obj.AttackDamage;
	this->EnergyPoint = obj.EnergyPoint;
	this->HitPoint = obj.HitPoint;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

void	ClapTrap::attack(const std::string& target)
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
	std::cout << name << " attacks " << target << ", causing " << this->AttackDamage << " points of damage!" << std::endl;
	this->EnergyPoint -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->HitPoint <= 0)
	{
		std::cout << name << " has no hit point" << std::endl;
		return ;
	}
	else
	{
		this->HitPoint -= amount;
		if (this->HitPoint < 0)
			this->HitPoint = 0;
		std::cout << name << " take damage " << amount << " of hit point" << std::endl;
	}
}

void	ClapTrap::beReparied(unsigned int amount)
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
	std::cout << name << " repair " << amount << " points of hit point" << std::endl;
	this->HitPoint += amount;
	this->EnergyPoint -= 1;
}
