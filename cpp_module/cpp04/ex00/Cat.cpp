#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
}

Cat::Cat(const Cat& obj)
{
	*this = obj;
}

Cat& Cat::operator=(const Cat &obj)
{
	this->type = obj.type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "an appropriate Cat sound" << std::endl;
}