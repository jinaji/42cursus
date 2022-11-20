#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>
# include <iostream>
# include <typeinfo>

class WrongAnimal
{
protected:
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(const WrongAnimal& obj);
	const WrongAnimal& operator=(const WrongAnimal &obj);
	virtual ~WrongAnimal();

	void	makeSound() const;
	std::string	getType() const;
};

#endif