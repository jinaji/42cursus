#include "Cure.hpp"

Cure::Cure()
{
	this->type = "cure";
}

Cure::Cure(const Cure& obj)
{
	this->type = "cure";
	*this = obj;
}

const Cure& Cure::operator=(const Cure& obj)
{
	(void)obj;
	return (*this);
}

Cure::~Cure()
{
}

AMateria* Cure::clone() const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}