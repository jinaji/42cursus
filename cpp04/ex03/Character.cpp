#include "Character.hpp"

Character::Character() : index(0), f_index(0)
{
}

Character::Character(const Character& obj)
{
	*this = obj;
}

const Character& Character::operator=(const Character& obj)
{
	for (int i = 0; this->index > i; i++)
		delete this->inventory[i];
	for (int i = 0; this->f_index > i; i++)
		delete this->floor[i];
	for (int i = 0; obj.index > i; i++)
		this->inventory[i] = obj.inventory[i]->clone();
	for (int i = 0; obj.f_index > i; i++)
		this->floor[i] = obj.floor[i]->clone();
	this->name = obj.name;
	this->index = obj.index;
	this->f_index = obj.f_index;
	return (*this);
}

Character::~Character()
{
	for (int i = 0; this->index > i; i++)
		delete this->inventory[i];
	for (int i = 0; this->f_index > i; i++)
		delete this->floor[i];
}

Character::Character(std::string name) : name(name), index(0), f_index(0)
{
}

std::string const& Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	if (index >= 4)
		delete m;
	this->inventory[index] = m;
	this->index++;
	std::cout << this->getName() << " equip " << this->index << " slot " << m->getType() << " material" << std::endl;
}

void Character::unequip(int idx)
{
	if (f_index >= 10 || (0 >= idx || idx >= 4) || this->index == 0)
		return ;
	this->floor[f_index] = this->inventory[idx];
	std::cout << this->getName() << " unequip " << this->inventory[index]->getType() << " material at " << this->index << "slot" << std::endl;
	std::cout << "there are " << f_index << " materials on the floor" << std::endl;
	this->f_index++;
	this->index--;
}

void Character::use(int idx, ICharacter& target)
{
	AMateria	*tmp;

	if (0 >= idx || idx >= 4)
		return ;
	tmp->use(target);
}
