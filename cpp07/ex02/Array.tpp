#include "Array.hpp"

template <typename T>
Array<T>::Array()
{
	this->arr = NULL;
	this->idx = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	this->arr = new T[n];
	this->idx = n;
}

template <typename T>
Array<T>::Array(const Array& obj)
{
	*this = obj;
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	if (this == &obj)
		return (*this);
	for (size_t i = 0; obj.idx > i; i++)
		this->arr[i] = obj.arr[i];
}

template <typename T>
Array<T>::~Array()
{
	if (idx)
		delete[] arr;
}

template <typename T>
T& Array<T>::operator[](int idx)
{
	if (idx > this->idx)
		throw (std::exception());
	return (this->arr[idx]);
}

template <typename T>
int	Array<T>::size() const
{
	return (this->idx);
}
