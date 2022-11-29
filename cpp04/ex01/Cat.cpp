#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat& obj)
{
	this->brain = new Brain();
	*this = obj;
}

Cat& Cat::operator=(const Cat &obj)
{
	delete this->brain;
	this->type = obj.type;
	this->brain = new Brain(*obj.brain);
	return (*this);
}

Cat::~Cat()
{
	delete (this->brain);
	std::cout << "Cat default destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "an appropriate Cat sound" << std::endl;
}