#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

# include <string>
# include <iostream>
# include <typeinfo>

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(const WrongCat& obj);
	const WrongCat& operator=(const WrongCat &obj);
	~WrongCat();

	void	makeSound() const;
};

#endif