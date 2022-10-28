#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
private:
	std::string name;
public:
	DiamondTrap();
	DiamondTrap(const DiamondTrap& diamondtrap);
	DiamondTrap& operator=(const DiamondTrap& diamondtrap);
	~DiamondTrap();

	DiamondTrap(std::string name);
	void	whoAmI();
};

#endif