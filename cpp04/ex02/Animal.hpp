#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>
# include <typeinfo>

class Animal
{
protected:
	std::string type;
public:
	Animal();
	Animal(const Animal& obj);
	const Animal& operator=(const Animal &obj);
	virtual ~Animal();

	virtual void	makeSound() const = 0;
	std::string	getType() const;
};

#endif