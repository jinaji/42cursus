#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap
{
protected:
	std::string 	name;
	int	hitPoint;
	int	energyPoint;
	int	attackDamage;
public:
	ClapTrap();
	ClapTrap(const ClapTrap& claptrap);
	ClapTrap& operator=(const ClapTrap& claptrap);
	virtual ~ClapTrap();

	ClapTrap(std::string name);
	
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beReparied(unsigned int amount);
};



#endif