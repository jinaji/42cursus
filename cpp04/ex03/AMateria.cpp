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
	if (this->type.compare("ice") == 0)
		std::cout << "* shoot an ice bolt at " << target.getName() << std::endl;
	else if (this->type.compare("cure") == 0)
		std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
