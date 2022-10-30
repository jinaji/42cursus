#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
private:
	std::string ideas[100];
public:
	Brain();
	Brain(const Brain& obj);
	const Brain& operator=(const Brain& obj);
	~Brain();
};

#endif