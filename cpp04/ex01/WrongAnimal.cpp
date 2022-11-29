#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(const WrongAnimal& obj)
{
	*this = obj;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &obj)
{
	this->type = obj.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal default destructor called" << std::endl;
}

void	WrongAnimal::makeSound() const
{
	std::cout << "an appropriate WrongAnimal sound" << std::endl;
}

std::string	WrongAnimal::getType() const
{
	return (this->type);
}
