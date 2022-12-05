#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <vector>
# include <iterator>

namespace ft
{

template <typename category, typename T, typename Distance = ptrdiff_t, typename Pointer = T*, typename Reference = T&>
class iterator
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

template <typename It>
class reverse_iterator : public iterator<typename iterator_traits<It>::iterator_category,
                      typename iterator_traits<It>::value_type,
                      typename iterator_traits<It>::difference_type,
                      typename iterator_traits<It>::pointer,
                      typename iterator_traits<It>::reference>
{
	protected:
		It current;
	typedef It												iterator_type;
	typedef typename iterator_traits<It>::difference_type	difference_type;
	typedef typename iterator_traits<It>::reference			reference;
	typedef typename iterator_traits<It>::pointer			pointer;

	reverse_iterator() : current() {}
	reverse_iterator(It obj) : current(obj) {} // ㄷㅏ르ㄴ타입 이터레이터 ... 연산자들 거꾸로
	template <typename Iter>
	reverse_iterator(const reverse_iterator<Iter>& obj) : current(obj.base()) {} // 얜 걍 리버스 이터레이터 복사뜨는
	template <typename Iter>
	reverse_iterator& operator=(const reverse_iterator<Iter>& obj) {current = obj.base(); return *this;}
	It base() const {return current;}

	// operator
	reference			operator*() const {It tmp = current; return *--tmp;}
	pointer				operator->() const {return &(operator*());}
	reverse_iterator&	operator++() {--current; return *this;}
	reverse_iterator	operator++(int) {reverse_iterator tmp(*this); --current; return tmp;}
	reverse_iterator&	operator--() {++current; return *this;}
	reverse_iterator	operator--(int) {reverse_iterator tmp(*this); ++current; return tmp;}
	reverse_iterator	operator+(difference_type n) const {return reverse_iterator(current - n);}
	reverse_iterator&	operator+=(difference_type n) const {current -= n; return *this;}
	reverse_iterator	operator-(difference_type n) const {return reverse_iterator(current + n);}
	reverse_iterator&	operator-=(difference_type n) const {current += n; return *this;}
	reference			operator[](difference_type n) const {return *(this + n);}
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