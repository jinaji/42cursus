#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
	for (int i = 0; 100 > i; i++)
		this->ideas[i] = "No ideas";
}

Brain::Brain(const Brain &obj)
{
	*this = obj;
}

Brain& Brain::operator=(const Brain& obj)
{
	for (int i = 0; 100 > i; i++)
		this->ideas[i] = obj.ideas[i];
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain default destructor called" << std::endl;
}
