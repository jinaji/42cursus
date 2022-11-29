#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

# include <string>
# include <iostream>
# include <typeinfo>

class Cat : public Animal
{
private:
	Brain *brain;
public:
	Cat();
	Cat(const Cat& obj);
	Cat& operator=(const Cat &obj);
	~Cat();

	void	makeSound() const;
};

#endif