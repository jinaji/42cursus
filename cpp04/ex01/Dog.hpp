#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# include <string>
# include <iostream>
# include <typeinfo>

class Dog : public Animal
{
private:
	Brain *brain;
public:
	Dog();
	Dog(const Dog& obj);
	const Dog& operator=(const Dog &obj);
	~Dog();

	void	makeSound() const;
};

#endif