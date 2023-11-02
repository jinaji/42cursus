#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& obj)
{
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	this->type = obj.type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat default destructor called" << std::endl;
}

void	WrongCat::makeSound() const
{
	std::cout << "an appropriate WrongCat sound" << std::endl;
}