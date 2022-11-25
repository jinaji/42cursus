#ifndef EASYFIND_HPP
# define EASYFIND_HPP
#include <iostream>
#include <algorithm>

template <typename T>
int easyfind(T container, int n)
{
	typename T::iterator it;

	it = std::find(container.begin(), container.end(), n);
	if (it != container.end())
	{
		std::cout << "Found" << " " << *it << std::endl;
		return (*it);
	}
	else
	{
		std::cout << "Not Found" << std::endl;
		return (-1);
	}
	// for (size_t i = 0; arr.size() > i ; i++)
	// {
	// 	std::cout << i << " " << arr[i] << std::endl;
	// 	if (arr[i] == n)
	// 		return (i);
	// }
}

#endif