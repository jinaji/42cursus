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

const Ice& Ice::operator=(const Ice& obj)
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

