#include "Ice.hpp"

Ice::Ice()
{
	this->type = "ice";
}

Ice::Ice(const Ice& obj)
{
	this->type = "ice";
	*this = obj;
}

Ice& Ice::operator=(const Ice& obj)
{
	(void)obj;
	return (*this);
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoot an ice bolt at " << target.getName() << std::endl;
}