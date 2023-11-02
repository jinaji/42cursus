#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called" << std::endl;
	this->type = "Animal";
}

Animal::Animal(const Animal& obj)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = obj;
}

Animal& Animal::operator=(const Animal &obj)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	this->type = obj.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal default destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "an appropriate Animal sound" << std::endl;
}

std::string	Animal::getType() const
{
	return (this->type);
}
