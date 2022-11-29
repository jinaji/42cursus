#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

Character::Character() : index(0), f_index(0)
{
}

Character::Character(const Character& obj)
{
	*this = obj;
}

Character& Character::operator=(const Character& obj)
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
	int i = 0;
	
	if (this->index >= 4)
		delete m;
	for (; 4 > i; i++)
	{
		if (!this->inventory[i])
		{
			this->inventory[i] = m;
			break ;
		}
	}
	this->index++;
	std::cout << this->getName() << " equip " << m->getType() << " material on " << i << std::endl;
}

void Character::unequip(int idx)
{
	if (f_index > 9 || (0 > idx || idx >= 4) || this->index == 0)
		return ;
	if (!this->inventory[idx])
		return ;
	if (this->inventory[idx]->getType().compare("ice") == 0 || this->inventory[idx]->getType().compare("cure") == 0)
	{
		this->floor[f_index] = this->inventory[idx];
		std::cout << this->getName() << " unequip " << this->inventory[idx]->getType() << " material at " << idx << " slot" << std::endl;
		// 슬롯 비우기 ??
		this->inventory[idx] = NULL;
		this->f_index++;
		std::cout << "there are " << f_index << " materials on the floor" << std::endl;
		this->index--;
	}
}

void Character::use(int idx, ICharacter& target)
{
	AMateria	*tmp;

	if (0 > idx || idx >= 4)
		return ;
	if (!this->inventory[idx])
		return ;
	if (this->inventory[idx]->getType().compare("ice") == 0)
		tmp = new Ice();
	else
		tmp = new Cure();
	std::cout << this->getName() << " use " << idx << " slot's " << tmp->getType() << std::endl;
	tmp->use(target);
	delete tmp;
}
