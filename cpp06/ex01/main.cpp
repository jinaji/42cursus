#include <iostream>
#include "Data.hpp"

int main()
{
	Data	ptr;

	ptr.data = 42;

	std::cout << "origin data" << std::endl;
	std::cout << ptr.data << std::endl; // value
	std::cout << &(ptr.data) << std::endl << std::endl; // address

	std::cout << "serialize" << std::endl;
	uintptr_t raw = serialize(&ptr);
	std::cout << raw << std::endl; // value
	std::cout << &raw << std::endl << std::endl; // address

	std::cout << "deserialize" << std::endl;
	std::cout << deserialize(raw)->data << std::endl; // value
	std::cout << &(deserialize(raw)->data) << std::endl << std::endl; // address
}
