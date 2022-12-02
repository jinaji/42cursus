#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>

namespace ft
{

template <typename category, typename T, typename distance = ptrdiff_t, typename pointer = T*, typename reference = T&>
struct iterator
{
	typedef	T			value_type;
	typedef	distance	difference_type;
	typedef	pointer		pointer;
	typedef	reference	reference;
	typedef	category 	iterator_category;
};

template <typename Iterator>
class iterator_traits // class?? struct???
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <typename T> 
class iterator_traits<T*>
{
	typedef ptrdiff_t							diffrence_type;
	typedef T									value_type;
	typedef T*									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template <typename T> 
class iterator_traits<const T*>
{
	typedef ptrdiff_t							diffrence_type;
	typedef T									value_type;
	typedef T*									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template <typename T>
class random_access_iterator : public iterator<random_access_iterator_tag, T>
{
	typedef typename iterator<random_access_iterator_tag, T>::value_type		value_type;
	typedef typename iterator<random_access_iterator_tag, T>::difference_type	difference_type;
	typedef typename iterator<random_access_iterator_tag, T>::pointer			pointer;
	typedef typename iterator<random_access_iterator_tag, T>::reference			reference;
	typedef typename iterator<random_access_iterator_tag, T>::iterator_category	iterator_category;
}

}

#endif