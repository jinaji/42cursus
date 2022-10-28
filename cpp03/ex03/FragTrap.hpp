#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap& operator=(const FragTrap& fragtrap);
	FragTrap(const FragTrap& fragtrap);
	~FragTrap();

	FragTrap(std::string name);

	void	highFivesGuys(void);
};

#endif