#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	AMateria *inventory[4];
	AMateria *floor[10];
	std::string name;
	int			index;
	int			f_index;

public:
	Character();
	Character(const Character& obj);
	Character& operator=(const Character& obj);
	~Character();

public:
	Character(std::string name);

public:
	std::string const& getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif