#ifndef HUMAN_HPP
# define HUMAN_HPP

# include <string>
# include <iostream>
# include "Weapon.hpp"

class	HumanA
{
private:
	std::string	name;
	Weapon		&weapon;
public:
	HumanA();
	HumanA(std::string name, Weapon &weapon);
	~HumanA();
	void	attack(void);
};

class	HumanB
{
private:
	Weapon*		weapon;
	std::string	name;
public:
	HumanB();
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	setWeapon(Weapon weapon);
};

#endif