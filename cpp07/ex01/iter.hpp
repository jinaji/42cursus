#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void iter(T *arr, int len, void (*f)(const T&))
{
	if (0 > len)
	{
		std::cout << "len range error" << std::endl;
		return ;
	}
	for (int i = 0; len > i; i++)
		f(arr[i]);
}

#endif