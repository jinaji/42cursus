#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>

template <typename T>
class MutantStack
{
private:
	/* data */
public:
	MutantStack();
	MutantStack(const MutantStack& obj);
	const MutantStack& operator=(const MutantStack& obj);
	~MutantStack();

public:

};

template <typename T>
MutantStack<T>::MutantStack()
{
}

template <typename T>
MutantStack<T>::~MutantStack()
{
}


#endif