#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	// const Animal* meta = new Animal();
	// const Animal* j = new Dog();
	// const Animal* i = new Cat();

	// std::cout << j->getType() << " " << std::endl;
	// std::cout << i->getType() << " " << std::endl;

	// i->makeSound(); //will output the cat sound!
	// j->makeSound();
	// meta->makeSound();

	// delete (meta);
	// delete (j);
	// delete (i);

	// const WrongAnimal	*meta2 = new WrongAnimal();
	// const WrongCat		*i2 = new WrongCat();

	// std::cout << meta2->getType() << " " << std::endl;
	// std::cout << i2->getType() << " " << std::endl;

	// meta2->getType();
	// i2->makeSound();

	// delete (meta2);
	// delete (i2);

	Animal *animal[10];
	for (int i = 0; 5 > i; i++)
		animal[i] = new Dog();
	for (int i = 5; 10 > i; i++)
		animal[i] = new Cat();

	for (int i = 0; 10 > i; i++)
		delete (animal[i]);

	return 0;	
}