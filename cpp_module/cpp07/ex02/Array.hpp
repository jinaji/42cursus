#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
	private:
	T	*arr;
	unsigned int idx;

	public:
	Array();
	Array(unsigned int n);
	Array(const Array& obj);
	~Array();
	Array& operator=(const Array& obj);
	T& operator [](int idx);

	int	size() const;
	void deleteArr(void);

};

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
	idx = 0;
	*this = obj;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	if (this == &obj)
		return (*this);
	else if (this->idx)
		delete (this->arr);
	else
		this->arr = new T[obj.idx];
	for (unsigned int i = 0; obj.idx > i; i++)
		this->arr[i] = obj.arr[i];
	this->idx = obj.idx;
	return (*this);
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
	unsigned int index = static_cast<unsigned int>(idx);

	if (index >=this->idx || 0 > index)
		throw (std::exception());
	return (this->arr[index]);
}

template <typename T>
int	Array<T>::size() const
{
	return (this->idx);
}

template <typename T>
void Array<T>::deleteArr(void)
{
	delete (this->arr);
}

#endif