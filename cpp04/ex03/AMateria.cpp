#include "AMateria.hpp"

AMateria::AMateria()
{
}

AMateria::AMateria(const AMateria& obj)
{
	*this = obj;
}

const AMateria& AMateria::operator=(const AMateria& obj)
{
	this->type = obj.type;
	return (*this);
}

AMateria::~AMateria()
{
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

std::string const& AMateria::getType() const
{
	return (this->type);
}

void AMateria::use(ICharacter& target)
{
	if (this->type == "ice")
		std::cout << "* shoot an ice bolt at " << target.getName() << std::endl;
	else if (this->type == "cure")
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
