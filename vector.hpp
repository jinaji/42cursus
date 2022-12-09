#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <vector>

# include <iterator>
# include <limits>
# include "Iterator.hpp"
# include "functions.hpp"

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
    // typedef std::allocator::<allocator_type>			__alloc_type;
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
	// size_type			m_size;			// allocated size
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

	void	_M_deallocate(pointer __p, size_t __n, allocator_type __a = allocator_type())
	{
		if (__p)
			__alloc_traits::deallocate(__a, __p, __n); // ???
	}

	void	_M_create_storage(size_t __n)
	{
		this->m_begin = this->_M_allocate(__n);
		this->m_end = this->m_begin;
		this->m_cap = this->m_begin + __n;
	}
};

template <class T, class Allocator = std::allocator<T> >
class Vector : protected VectorBase <T,  Allocator>
{
private:
	typedef VectorBase<T, Allocator>					__base;
	typedef typename __base::__alloc_traits				__alloc_traits;
	typedef typename __base::allocator_type				allocator_type;
	// typedef std::allocator<T>						allocator_type;

public:
    typedef T											value_type;
	typedef typename __base::pointer					pointer;
    typedef typename __base::const_pointer				const_pointer;
	typedef typename __base::reference					reference;
	typedef typename __base::const_reference			const_reference;
	typedef typename __base::size_type					size_type;
    // typedef typename __alloc_traits::reference			reference;
    // typedef typename __alloc_traits::const_reference	const_reference;

	// typedef typename ft::iterator<std::random_access_iterator_tag, Vector>::pointer			iterator;

	// typedef typename ft::iterator_traits<pointer>::pointer			iterator;
	// typedef typename ft::iterator_traits<const_pointer>::pointer	const_iterator;
    // typedef __wrap_iter<const_pointer>							
	// typedef ft::iterator_traits<iterator>::pointer					pointer;
    typedef ft::random_access_iterator<value_type>			iterator;
    typedef ft::random_access_iterator<const value_type>	const_iterator;
	typedef ft::reverse_iterator<iterator>					reverse_iterator;
    typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
	
	Vector()
	{
		this->m_begin = NULL;
		this->m_end = NULL;
		this->m_cap = NULL;
		this->m_alloc = allocator_type();
	};
	Vector(size_t n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		this->m_alloc = alloc;
		this->_M_create_storage(n);
		this->m_end += n;
		while (n--)
			this->m_alloc.construct(this->m_begin + n, val);
		// std::uninitialized_fill(this->m_begin, this->m_begin + n, val);
	}

	template <class InputIterator>
	Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0)
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

// capacity
	size_type	size() const {return static_cast<size_type>(this->m_end - this->m_begin);}
	size_type	max_size() const {return (-1);} // maximum number of a vector container can hold as content. != capacity
	void		resize(size_type n, value_type val = value_type())
	{
		size_type	_size = size(); // n이 사이즈보다 클 때만 val로 채우는 건가
		// size_type	_cap = capacity() - n;

		if (capacity() == 0)
		{
			this->_M_create_storage(n);
			while (n--)
				this->m_alloc.construct(this->m_begin + n, val);
			// std::uninitialized_fill(this->m_begin, this->m_begin + n, val);
			// this->m_end += n;
		}
		else if (n > capacity()) // realloc
		{
			pointer	_tmp;
			size_type _end = size(); // 뻐큐 
			size_type _cap = capacity();
			while (n > _cap)
				_cap *= 2;
			_tmp = this->_M_allocate(_cap); // segfault 
			// std::cout << capacity() * 2 << std::endl;
			std::uninitialized_copy(this->m_begin, this->m_end, _tmp);
			this->_M_deallocate(this->m_begin, this->m_end - this->m_begin, this->m_alloc);
			std::uninitialized_fill_n(_tmp + _end, n - _end, val);
			this->m_begin = _tmp;
			// std::cout << "under " << capacity() * 2 << std::endl;
			this->m_cap = this->m_begin + _cap;
			this->m_end = this->m_begin + n - _end;
			// std::cout << "hi 2 cap: " << capacity() << std::endl;
		}
		else if (_size > n) // end 땡겨서 줄이기
		{
			std::cout << "hi 3" << std::endl;
			while (_size > n)
			{
				__alloc_traits::destroy(this->m_alloc, this->m_end);
				_size--;
			}
			// std::uninitialized_fill_n(this->m_begin, n, val);
			this->m_end = this->m_begin + n;
		}
		else // 지금보다 크긴한데 자리남음
		{
			std::cout << "hi 4" << std::endl;

			for (size_type i = size(); n > i; i++)
				__alloc_traits::destroy(this->m_alloc, this->m_end);
			std::uninitialized_fill_n(this->m_end, n - size(), val);
			this->m_end = this->m_begin + n;
			// std::uninitialized_fill(this->m_end, this->m_end + (n - _size), val);
			// this->m_end += (n - _size);
		}
	}
	size_type	capacity() const {return static_cast<size_type>(this->m_cap - this->m_begin);}
	bool		empty() const {return this->m_begin == this->m_end;}
	void		reserve(size_type n)
	{
		std::cout << "reserve "<< capacity() << std::endl;
		if (n > capacity())
			resize(n);
		// if (n > capacity())
		// {
		// 	pointer	_tmp;

		// 	_tmp = this->_M_allocate(n);
		// 	std::uninitialized_copy(this->m_begin, this->m_end, _tmp);
		// 	_M_deallocate(this->m_begin);
		// 	this->m_begin = _tmp;
		// 	this->m_cap = this->m_begin + n;
		// 	this->end = this->m_begin + n;
		// }
	}

// element access
	reference 			operator[](size_type n) {return (*(this->m_begin + n));}
	const reference		operator[](size_type n) const {return (*(this->m_begin + n));}
	reference			at(size_type n) {if (n > size()) throw("out of range"); return (this->m_begin + n);}
	const_reference		at(size_type n) const {if (n > size()) throw("out of range"); return (this->m_begin + n);}
	reference			front() {return (*(this->begin()));}
	const reference		front() const {return (*(this->begin()));}
	reference			back() {return (*(this->end() - 1));}
	const_reference		back() const {return (*(this->end() - 1));}
	// value_type*			data() FT_NOEXCEPT {return (this->begin());} // no except c++ 11?? const ??  https://en.cppreference.com/w/cpp/container/vector/data
	// const value_type	data() const FT_NOEXCEPT {return (this->begin());}

// 	// modifiers
	template <class InputIterator>
	void		assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
	{
		size_type	_size = (last - first);

		for (size_type i = 0; _size > i; i++)
			__alloc_traits::destroy(this->m_alloc, this->m_begin);
		if (!this->m_begin)
			this->_M_create_storage(last - first);
		std::uninitialized_copy(first, last, this->m_begin);
	}

	void		assign(size_type n, const value_type& val)
	{
		// while (n > capacity())
		// 	resize(n, val);
		// size_type	_size = size();
		// std::uninitialized_fill(this->m_end, this->m_end + (n), val);
		// resize(n, val);
		// this->m_end += (n);
		// std::cout << capacity() << std::endl;
		// std::cout << size() << std::endl;
		if (capacity() == 0)
			resize(n, val);
		else if (this->m_end == this->m_cap)
			resize(n * 2);
		for (size_type i = 0; n > i; i++)
			__alloc_traits::destroy(this->m_alloc, this->m_begin);
		std::uninitialized_fill_n(this->m_begin, n, val);
		this->m_end = this->m_begin + n;
	}

	void		push_back(const value_type& val)
	{
		if (capacity() == 0)
			this->_M_create_storage(1);
		else if (capacity() == size())
			resize(capacity() * 2);
		this->m_alloc.construct(this->m_end, val);
		// std::uninitialized_fill_n(this->m_end, 1, val);
		this->m_end += 1;
	}

	void		pop_back()
	{
		if (empty())
			return ;
		__alloc_traits::destroy(this->m_alloc, this->m_end);
		this->m_end -= 1;
	}

	iterator	insert(iterator position, const value_type& val)
	{                                                             
		size_type	_size = (size()) + 1;
		size_type	_pos = position - this->m_begin;
		pointer		_tmp;

		if (_size >= capacity())
			resize(capacity() * 2);
		_tmp = this->_M_allocate(size() - _pos);
		std::uninitialized_copy_n(this->m_begin + _pos, size() - _pos, _tmp);
		this->m_alloc.construct(this->m_begin + _pos, val);
		this->m_end += 1;
		std::uninitialized_copy_n(_tmp, _size - _pos, this->m_begin + _pos + 1);
		return (this->m_begin + _pos); 
	}

	void		insert(iterator position, size_type n, const value_type& val)
	{
		size_type	_size = (size()) + n;
		size_type	_pos = position - this->m_begin;
		pointer		_tmp;

		if (_size >= capacity())
			resize(capacity() * 2);
		_tmp = this->_M_allocate(size() - _pos);
		std::uninitialized_copy_n(this->m_begin + _pos, size() - _pos, _tmp);
		this->m_end += n;
		while (n--)
			this->m_alloc.construct(this->m_begin + _pos + n, val);
		std::uninitialized_copy_n(_tmp, _size - _pos, this->m_begin + _pos + n);
	}

template <class InputIterator>
void		insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
{
		size_type	n = (last - first);
		size_type	_size = (size()) + n;
		size_type	_pos = position - this->m_begin;
		pointer		_tmp;

		if (_size >= capacity())
			resize(capacity() * 2);
		_tmp = this->_M_allocate(size() - _pos);
		std::uninitialized_copy_n(this->m_begin + _pos, size() - _pos, _tmp);
		while (first != last)
			this->m_alloc.construct(this->m_begin + _pos, *first++);
		this->m_end += n;
		std::uninitialized_copy_n(_tmp, _size - _pos, this->m_begin + _pos + n);
}

// 	iterator	erase(iterator position);
// 	iterator	erase(iterator first, iterator last);
// 	void		swap(Vector& x);
// 	void		clear(); // memory alives

};

}

#endif