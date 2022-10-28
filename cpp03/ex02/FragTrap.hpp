#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap& operator=(const FragTrap& fragtrap);
	FragTrap(const FragTrap& fragtrap);
	~FragTrap();

	void	highFivesGuys(void);
};

#endif