#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap& operator=(const ScavTrap& scavtrap);
	ScavTrap(const ScavTrap& scavtrap);
	~ScavTrap();

	ScavTrap(std::string name);

	void	guardGate();
};




#endif