#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
	std::string mName;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void 	announce(void);
	void	setZombieName(std::string name);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);
Zombie*	ZombieHorde(int N, std::string name);

#endif