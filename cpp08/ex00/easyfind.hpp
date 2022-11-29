#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <algorithm>

class notFoundException : public std::exception
{
	public:
	const char* what() const throw()
	{
		return ("Element not found");
	}
};

template <typename T>
int easyfind(T container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
	{
		std::cout << "Found " << *it << std::endl;
		// std::cout << *(it + 1) << std::endl; // 하나 뒤 
		return (*it);
	}
	else
		throw (notFoundException());
}

#endif