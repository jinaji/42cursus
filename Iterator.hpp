#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <vector>
# include <iterator>

namespace ft
{

template <typename category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
struct iterator
{
	typedef	T			value_type;
	typedef	Distance	difference_type;
	typedef	Pointer		pointer;
	typedef	Reference	reference;
	typedef	category 	iterator_category;
}; // ㅇㅣ거 걍  std 이터레이터인데 필요한가 ???

template <typename Iterator>
struct iterator_traits // class?? struct???
{
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
	typedef typename Iterator::iterator_category	iterator_category;
};

template <typename T> 
struct iterator_traits<T*>
{
	typedef ptrdiff_t							diffrence_type;
	typedef T									value_type;
	typedef T*									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template <typename T> 
struct iterator_traits<const T*>
{
	typedef ptrdiff_t							diffrence_type;
	typedef T									value_type;
	typedef T*									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

// template <typename T>
// class random_access_iterator : public iterator<std::random_access_iterator_tag, T>
// {
// 	typedef typename iterator<std::random_access_iterator_tag, T>::value_type		value_type;
// 	typedef typename iterator<std::random_access_iterator_tag, T>::difference_type	difference_type;
// 	typedef typename iterator<std::random_access_iterator_tag, T>::pointer			pointer;
// 	typedef typename iterator<std::random_access_iterator_tag, T>::reference			reference;
// 	typedef typename iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;
// };

}

#endif