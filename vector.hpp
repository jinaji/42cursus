#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
// # include <vector>

# include <iterator>
# include "Iterator.hpp"
# include <limits>

# include <iostream>

# define FT_NOEXCEPT throw()

namespace ft
{

template <class T, class Allocator = std::allocator<T> >
class VectorBase
{
public:
    typedef Allocator									allocator_type;
	typedef std::allocator_traits<allocator_type>		__alloc_traits;
    // typedef typename allocator_traits<allocator_type>	__alloc_type;
    typedef typename __alloc_traits::size_type			size_type;

protected:
    typedef T											value_type;
	typedef value_type&									reference;
	typedef const value_type&							const_reference;
	typedef typename __alloc_traits::difference_type	difference_type;
	typedef typename __alloc_traits::pointer			pointer;
	typedef typename __alloc_traits::const_pointer		const_pointer;

    // typedef value_type&									reference;
    // typedef const value_type&							const_reference;
    // typedef typename allocator_type::difference_type	difference_type;
    // typedef typename allocator_type::pointer			pointer;
    // typedef typename allocator_type::const_pointer		const_pointer; // 글고 이거 이름 이터레이터랑 겹쳐도 되는거임???

	// typedef 
	// typedef typename ft::iterator_traits<std::vector<value_type>::iterator>::pointer				iterator;
    // typedef const_pointer								const_iterator;

	/* element */
	size_type			m_size;			// allocated size
    pointer				m_begin;		// begin iterator
    pointer				m_end;			// end iterator
    pointer				m_cap;			// capacity
	allocator_type		m_alloc;		// allocator type

	/* method */
	VectorBase() FT_NOEXCEPT : m_begin(NULL), m_end(NULL), m_cap(NULL), m_alloc(allocator_type()) {}
	VectorBase(const allocator_type& __a) : m_begin(NULL), m_end(NULL), m_cap(NULL), m_alloc(__a) {}
	VectorBase(size_t __n) : m_alloc(allocator_type())
	{
		_M_create_storage(__n);
	}
	VectorBase(size_t __n, const allocator_type& __a)
	{
		this->m_alloc = __a;
		_M_create_storage(__n);
	}

	virtual ~VectorBase()
	{
		_M_deallocate(m_begin, m_cap - m_begin, m_alloc);
	}

	// allocator_type& __alloc() FT_NOEXCEPT
	// {
	// 	return m_cap.second();
	// }
	// const allocator_type& __alloc() const FT_NOEXCEPT
	// {
	// 	return m_cap.second();
	// }
	// pointer& __end_cap() FT_NOEXCEPT
	// {
	// 	return m_cap.first();
	// }
	// const pointer& __end_cap() FT_NOEXCEPT
	// {
	// 	return m_cap.first();
	// }

	// void deallocate(pointer __p, size_t __n)
	// {
	// }

	// void __copy_assign_alloc(const VectorBase& __c)
	// {
	// 	__copy_assign_alloc(__c, intergral_constant<bool, __alloc_traits::propagate_on_container_copy_assignment::value>()); // ?? 11이ㄴ듯
	// }

	// void __move_assign_alloc(VectorBase& __c)
	// {
	// 	__move_assign_alloc(__c, integral_constant<bool, __alloc_traits::propagate_on_containter_move_assignment::value>());
	// }

	void _M_copy_data(const VectorBase& obj) // shallow? 
	{
		this->m_begin = obj.m_begin;
		this->m_end = obj.m_end;
		this->m_cap = obj.m_cap;
		this->m_alloc = obj.m_alloc;
	}

	void _M_swap_data(VectorBase& obj)
	{
		VectorBase tmp;
		tmp._M_copy_data(*this);
		_M_copy_data(obj);
		obj._M_copy_data(tmp);
	}

	size_type _M_capacity() const FT_NOEXCEPT
	{
		return static_cast<size_type>(m_cap - m_begin);
	}

	pointer	_M_allocate(size_t n)
	{
		if (n != 0)
		{
			return (__alloc_traits::allocate(m_alloc, n));
		}
		return (pointer());
	}

	void	_M_deallocate(pointer __p, size_t __n, allocator_type __a)
	{
		if (__p)
			__alloc_traits::deallocate(__a, __p, __n); // ???
	}

	void	_M_create_storage(size_t __n)
	{
		this->m_begin = this->_M_allocate(__n);
		this->m_end = this->m_begin + __n;
		this->m_cap = this->m_begin + __n;
	}
};

template <class T, class Allocator = std::allocator<T> >
class Vector : protected VectorBase <T,  Allocator>
{
private:
	typedef VectorBase<T, Allocator>				__base;
	typedef typename __base::__alloc_traits			__alloc_traits;
	typedef typename __base::allocator_type			allocator_type;
	typedef typename __base::size_type				size_type;
	// typedef std::allocator<T>						allocator_type;

public:
    typedef T											value_type;
	typedef typename __base::pointer					pointer;
    typedef typename __base::const_pointer				const_pointer;
	typedef typename __base::reference					reference;
	typedef typename __base::const_reference			const_reference;
    // typedef typename __alloc_traits::reference			reference;
    // typedef typename __alloc_traits::const_reference	const_reference;

	// typedef typename ft::iterator<std::random_access_iterator_tag, Vector>::pointer			iterator;

	typedef typename ft::iterator_traits<pointer>::pointer			iterator;
	typedef typename ft::iterator_traits<const_pointer>::pointer	const_iterator;
    // typedef __wrap_iter<const_pointer>							
	// typedef ft::iterator_traits<iterator>::pointer					pointer;
    // typedef _VSTD::reverse_iterator<iterator>		reverse_iterator;
    // typedef _VSTD::reverse_iterator<const_iterator>	const_reverse_iterator;
	
	Vector() {};
	Vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		this->m_alloc = alloc;
		this->_M_create_storage(n);
		std::uninitialized_fill(this->m_begin, this->m_begin + n, val);
	}
	Vector(iterator first, iterator last, const allocator_type& alloc = allocator_type())
	{
		this->m_alloc = alloc;
		this->_M_create_storage(last - first);
		std::uninitialized_copy(first, last, this->m_begin);
		this->m_end = this->m_begin + (last - first);
	}

	Vector(const Vector& x)
	{
		*this = x;
	}

	Vector& operator= (const Vector& x)
	{
		if (this == &x)
			return (*this);
		if (this->m_begin)
			this->_M_deallocate(this->m_begin, (this->m_cap - this->m_begin), this->m_alloc);
		this->m_begin = this->_M_allocate(x.m_cap - x.m_begin);
		std::uninitialized_copy(x.m_begin, x.m_end, this->m_begin);
		this->m_end = this->m_begin + (x.m_end - x.m_begin);
		this->m_cap = this->m_begin + (x.m_cap - x.m_begin);
		return (*this);
	}

	~Vector() {};

	// iterator
	iterator		begin() {return (this->m_begin);}
	const_iterator	begin() const {return this->m_begin;}
	iterator		end() {return (this->m_end);}
	const_iterator	end() const {return (this->m_end);}
	iterator		rbegin() {return (this->m_end);}
	const_iterator	rbegin() const {return (this->m_end);}
	iterator		rend() {return (this->m_begin);}
	const_iterator	rend() const {return (this->m_begin);}

// 	//capacity
	size_type	size() const {return (this->m_end - this->m_begin);}
	size_type	max_size() const {return (sizeof(this->size_type));} // maximum number of a vector container can hold as content. != capacity
	void		resize(size_type n, value_type val = value_type())
	{
		size_type	_size = size();

		if (n > capacity()) // realloc
		{
			pointer	_tmp;

			_tmp = _M_allocate((capacity() - this->m_begin) * 2);
			std::uninitialized_copy(this->m_begin, this->m_end, _tmp);
			_M_deallocate(this->m_begin);
			this->m_cap = (capacity() - this->m_begin) * 2;
			this->end = this->m_begin + n;
			this->m_begin = _tmp;
		}
		else if (_size > n) // 줄이기
		{
			while (_size > n)
			{
				__alloc_traits::destroy(this->m_end);
				_size--;
				this->m_end--;
			}
		}
		else if (_size < n) // 지금보다 크긴한데 자리남음
		{
			std::uninitialized_fill(this->m_end, this->m_end + (n - _size), val);
			this->m_end += (n - _size);
		}
	}
	size_type	capacity() const {return static_cast<size_type>(this->m_cap - this->m_begin);}
	bool		empty() const {return this->m_begin == this->m_end;}
	void		reverse(size_type n)
	{
		if (n > capacity())
		{
			pointer	_tmp;

			_tmp = _M_allocate(n);
			std::uninitialized_copy(this->m_begin, this->m_end, _tmp);
			_M_deallocate(this->m_begin);
			this->m_begin = _tmp;
			this->m_cap = this->m_begin + n;
			this->end = this->m_begin + n;
		}
	}

// element access
	reference 			operator[](size_type n) {return &(*(this->m_begin + n));}
	const reference		operator[](size_type n) const {return &(*(this->m_begin + n));}
	reference			at(size_type n) {if (n > size()) throw("out of range");}
	const_reference		at(size_type n) const {if (n > size()) throw("out of range");}
	reference			front() {return (*(this->begin()));}
	const reference		front() const {return (*(this->begin()));}
	reference			back() {return (*(this->end()));}
	const_reference		back() const {return (*(this->end()));}
	// value_type*			data() FT_NOEXCEPT {return (this->begin());} // no except c++ 11?? const ??  https://en.cppreference.com/w/cpp/container/vector/data
	// const value_type	data() const FT_NOEXCEPT {return (this->begin());}

// 	// modifiers
	template <class InputIterator>
	void		assign(InputIterator first, InputIterator last);
// 	void		assign(size_type n, const value_type& val);
// 	void		push_back(const value_type& val);
// 	void		pop_back();
// 	iterator	insert(iterator position, const value_type& val);
// 	void		insert(iterator position, size_type n, const value_type& val);
// template <class InputIterator>
// void		insert(iterator position, InputIterator first, InputIterator last);
// 	iterator	erase(iterator position);
// 	iterator	erase(iterator first, iterator last);
// 	void		swap(Vector& x);
// 	void		clear(); // memory alives

};

template <typename T>
struct	is_integral
{
	// https://en.cppreference.com/w/cpp/types/numeric_limits/is_integer
};

template <bool B, typename T = void> // 
struct enable_if {};

template <class T>
struct enable_if<true, T> {typedef T type;}; 
// https://cplusplus.com/reference/type_traits/enable_if/?kw=enable_if

}

#endif