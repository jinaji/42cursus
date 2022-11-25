#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
	T	*arr;
	int idx;

	public:
	Array();
	Array(unsigned int n);
	Array(const Array& obj);
	~Array();
	const Array& operator=(const Array& obj);
	T& operator [](int idx);

	int	size() const;
};
# include "Array.tpp"

#endif