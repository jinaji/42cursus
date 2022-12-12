#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstddef>
# include <vector>
# include <iterator>
# include <iostream>

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
struct iterator_traits
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
	typedef ptrdiff_t							difference_type;
	typedef T									value_type;
	typedef T*									pointer;
	typedef T&									reference;
	typedef std::random_access_iterator_tag		iterator_category;
};

template <typename T> 
struct iterator_traits<const T*>
{
	typedef ptrdiff_t							difference_type;
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
	public:
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
	reverse_iterator	operator+(difference_type n) {return reverse_iterator(current - n);}
	reverse_iterator&	operator+=(difference_type n) {current -= n; return *this;}
	reverse_iterator	operator-(difference_type n) {return reverse_iterator(current + n);}
	reverse_iterator&	operator-=(difference_type n) {current += n; return *this;}
	reference			operator[](difference_type n) const {return *(this + n);}
	bool				operator==(reverse_iterator n) {if (current == n.current) return true; return false;}
	bool				operator!=(reverse_iterator n) {if (current == n.current) return false; return true;}
};

template <typename T>
class random_access_iterator : public ft::iterator<std::random_access_iterator_tag, T>
{
	T*	val;
	
public:
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::value_type			value_type;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::difference_type		difference_type;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::pointer				pointer;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::reference			reference;
	typedef typename ft::iterator<std::random_access_iterator_tag, T>::iterator_category	iterator_category;

	random_access_iterator() {}
  	random_access_iterator(T* x) : val(x) {}
  	random_access_iterator(const random_access_iterator& mit) : val(mit.val) {}

  	reference				operator*() {return *val;}
	pointer					operator->() const {return &(operator*());}
	random_access_iterator&	operator++() {++val; return *this;}
	random_access_iterator	operator++(int) {random_access_iterator tmp(*this); ++val; return tmp;}
	random_access_iterator&	operator--() {--val; return *this;}
	random_access_iterator	operator--(int) {random_access_iterator tmp(*this); --val; return tmp;}
	random_access_iterator	operator+(difference_type n) {return random_access_iterator(val + n);}
	random_access_iterator&	operator+=(difference_type n) {val += n; return *this;}
	random_access_iterator	operator-(difference_type n) {return random_access_iterator(val - n);}
	size_t					operator-(random_access_iterator n) {return static_cast<size_t>(val - n.val);}
	random_access_iterator&	operator-=(difference_type n) {val -= n; return *this;}
	reference				operator[](difference_type n) const {return *(this + n);}
	bool					operator<(random_access_iterator n) {if ((*this - n) > 0) return true; return false;}
	bool					operator==(random_access_iterator n) {return val == n.val;}
	bool					operator!=(random_access_iterator n) {return val != n.val;}
  	bool					operator==(const random_access_iterator& n) const {return val == n.val;}
  	bool 					operator!=(const random_access_iterator& n) const {return val != n.val;}
	bool					operator==(difference_type n) {if ((*this - n) == 0) return true; return false;}
	bool					operator!=(difference_type n) {if ((*this - n) == 0) return false; return true;}


	// bool operator==(const random_access_iterator& rhs) const {return p==rhs.p;}
	// bool operator!=(const random_access_iterator& rhs) const {return p!=rhs.p;}
};

}

#endif