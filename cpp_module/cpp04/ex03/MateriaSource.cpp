#include "MateriaSource.hpp"

MateriaSource::MateriaSource() : index(0)
{
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	for (int i = 0; this->index > i; i++)
		delete this->slot[i];
	for (int i = 0; obj.index > i; i++)
		this->slot[i] = obj.slot[i]->clone();
	this->index = obj.index;
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; this->index > i; i++)
		delete this->slot[i];
}

void MateriaSource::learnMateria(AMateria* obj)
{
	if (this->index >= 4)
	{
		std::cout << "no place for more Materia" << std::endl;
		delete obj;
		return ;
	}
	this->slot[index] = obj;
	this->index++;
}

AMateria* MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; this->index > i; i++)
	{
		if ((this->slot[i]->getType()).compare(type) == 0)
			return (this->slot[i]->clone());
	}
	std::cout << "no match materia" << std::endl;
	return (0);
}
