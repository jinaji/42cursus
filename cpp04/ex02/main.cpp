#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	Animal *animal[10];
	Animal *animal2[10];

	for (int i = 0; 5 > i; i++)
	{
		std::cout << i << " ";
		animal[i] = new Dog();
	}
	std::cout << std::endl;

	for (int i = 5; 10 > i; i++)
	{
		std::cout << i << " ";
		animal[i] = new Cat();
	}
	std::cout << std::endl;

	animal[0]->makeSound();
	animal[5]->makeSound();

	std::cout << std::endl;

	animal2[0] = animal[0];
	animal2[5] = animal[5];
	animal2[0]->makeSound();
	animal2[5]->makeSound();

	std::cout << std::endl;
	for (int i = 0; 10 > i; i++)
	{
		std::cout << i << " ";
		delete (animal[i]);
	}
	std::cout << std::endl;

	// {
	// 	const Animal* meta = new Animal();
	// 	meta->makeSound();

	// 	delete meta;
	// }

	return 0;
}