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

	// void _M_copy_data(const VectorBase& obj) // shallow? 
	// {
	// 	this->m_begin = obj.m_begin;
	// 	this->m_end = obj.m_end;
	// 	this->m_cap = obj.m_cap;
	// 	this->m_alloc = obj.m_alloc;
	// }

	// void _M_swap_data(VectorBase& obj)
	// {
	// 	VectorBase tmp;
	// 	tmp._M_copy_data(*this);
	// 	_M_copy_data(obj);
	// 	obj._M_copy_data(tmp);
	// }

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


    // typedef typename ft::iterator_traits<ft::random_access_iterator<value_type> >::pointer 			iterator;
    // typedef typename ft::iterator_traits<ft::random_access_iterator<const value_type> >::pointer 			const_iterator;
    
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
		this->m_alloc = x.get_allocator();
		this->m_begin = this->_M_allocate(x.m_cap - x.m_begin);
		std::uninitialized_copy(x.m_begin, x.m_end, this->m_begin);
		this->m_end = this->m_begin + (x.m_end - x.m_begin);
		this->m_cap = this->m_begin + (x.m_cap - x.m_begin);
		return (*this);
	}

	~Vector() {};

	// iterator
	iterator				begin() {return this->m_begin;}
	const_iterator			begin() const {return this->m_begin;}
	iterator				end() {return (this->m_end);}
	const_iterator			end() const {return (this->m_end);}
	reverse_iterator		rbegin() {return reverse_iterator(this->end());}
	const_reverse_iterator	rbegin() const {return reverse_iterator(this->end());}
	reverse_iterator		rend() {return reverse_iterator(this->begin());}
	const_reverse_iterator	rend() const {return reverse_iterator(this->begin());}

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
			this->m_end += n;
			while (n--)
				this->m_alloc.construct(this->m_begin + n, val);
			// std::uninitialized_fill(this->m_begin, this->m_begin + n, val);
		}
		else if (n < _size) // end 땡겨서 줄이기
		{
			while (_size > n)
			{
				__alloc_traits::destroy(this->m_alloc, this->m_end);
				_size--;
			}
			// std::uninitialized_fill_n(this->m_begin, n, val);
			this->m_end = this->m_begin + n;
		}
		else if (n <= capacity()) // 지금보다 크긴한데 자리남음
		{
			for (size_type i = size(); n > i; i++)
				__alloc_traits::destroy(this->m_alloc, this->m_end);
			std::uninitialized_fill_n(this->m_end, n - size(), val);
			this->m_end = this->m_begin + n;
			// std::uninitialized_fill(this->m_end, this->m_end + (n - _size), val);
			// this->m_end += (n - _size);
		}
		else // realloc 인데 ... 큰거 걍 던지는 거 생각해서 좀 바꿔봐야할듯
		{
			pointer	_tmp;
			size_type _end = size(); // 뻐큐 
			size_type _cap = capacity();

			while (n > _cap)
				_cap *= 2;
			_tmp = this->_M_allocate(_cap); // segfault 
			// std::cout << capacity() * 2 << std::endl;
			std::uninitialized_copy(this->m_begin, this->m_end, _tmp);
			this->_M_deallocate(this->m_begin, capacity(), this->m_alloc);
			std::uninitialized_fill_n(_tmp + _end, n - _end, val);
			this->m_begin = _tmp;
			// std::cout << "under " << capacity() * 2 << std::endl;
			this->m_cap = this->m_begin + _cap;
			// if (size() == 0)
			// this->m_end = this->m_begin + n - _end;
			// else
			this->m_end = this->m_begin + n;
			// std::cout << "in resize size " << size() << std::endl;
			// this->m_end = this->m_begin + _end;
			// std::cout << "hi 2 cap: " << capacity() << std::endl;
		}
	}
	size_type	capacity() const {return static_cast<size_type>(this->m_cap - this->m_begin);}
	bool		empty() const {return this->m_begin == this->m_end;}
	void		reserve(size_type n)
	{
		if (n > capacity())
		{
			size_type	_size = size();
			pointer	_tmp;

			_tmp = this->_M_allocate(n);
			std::uninitialized_copy(this->m_begin, this->m_end, _tmp);
			this->_M_deallocate(this->m_begin, capacity());
			this->m_begin = _tmp;
			this->m_cap = this->m_begin + n;
			this->m_end = this->m_begin + _size;
		}
	}

// element access
	reference 			operator[](size_type n) {return (*(this->m_begin + n));}
	const_reference		operator[](size_type n) const {return (*(this->m_begin + n));}
	reference			at(size_type n) {if (n > size()) throw("out of range"); return this->m_begin[n];}
	const_reference		at(size_type n) const {if (n > size()) throw("out of range"); return this->m_begin[n];}
	reference			front() {return (*(this->begin()));}
	const_reference		front() const {return *(this->begin());}
	reference			back() {this->m_alloc.destroy(this->m_end); return (*(this->end() - 1));}
	const_reference		back() const {this->m_alloc.destroy(this->m_end); return (*(this->end() - 1));}
	// value_type*			data() FT_NOEXCEPT {return (this->begin());} // no except c++ 11?? const ??  https://en.cppreference.com/w/cpp/container/vector/data
	// const value_type	data() const FT_NOEXCEPT {return (this->begin());}

// 	// modifiers
	template <class InputIterator>
	void		assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
	{
		size_type	_dist = (last - first);
		size_type	_size = _dist;

		if (this->m_begin)
		{
			while (_dist--)
				this->m_alloc.destroy(this->m_begin + _dist);
			if (capacity() < _size)
				this->m_alloc.deallocate(this->m_begin, capacity());
		}
		if (capacity() < _size)
		{
			this->_M_create_storage(_size);
		}
		// this->m_cap = this->m_begin + _size;
		// this->m_begin = this->m_alloc.allocate(_size);
		std::uninitialized_copy(first, last, this->m_begin);
		this->m_end = this->m_begin + _size;
		// this->m_cap = this->m_begin + _size;
		// std::cout << "assign capa " << capacity() << std::endl;
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

		// if (!this->m_begin)
		// 	this->_M_create_storage(n);
		// if (capacity() == 0)
		// 	resize(n, val);
		// else if (this->m_end == this->m_cap)
		// 	resize(n);
		// for (size_type i = 0; n > i; i++)
		// 	this->m_alloc.destroy(this->m_begin);
		// std::uninitialized_fill_n(this->m_begin, n, val);
		// this->m_end = this->m_begin + n;

		size_type	_size = size();

		if (this->m_begin)
		{
			while (_size--)
				this->m_alloc.destroy(this->m_begin + _size);
			if (capacity() < n)
				this->m_alloc.deallocate(this->m_begin, capacity());
		}
		// this->m_end = m_begin + n;
		if (capacity() < n)
			this->_M_create_storage(n);
		this->m_end = this->m_begin + n;
		while (n--)
			this->m_alloc.construct(this->m_begin + n, val);
		// this->m_cap = this->m_begin + n;
	}

	void		push_back(const value_type& val)
	{
		if (capacity() == 0)
			this->_M_create_storage(1);
		else if (capacity() == size())
			reserve(capacity() * 2);
		this->m_alloc.construct(this->m_end, val);
		this->m_end += 1;
		// std::uninitialized_fill_n(this->m_end, 1, val);
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

		if (_size > capacity())
			resize(capacity() * 2);
		this->m_end = this->m_begin + _size;
		_tmp = this->_M_allocate(size() - _pos);
		std::uninitialized_copy_n(this->m_begin + _pos, size() - _pos, _tmp);
		this->m_alloc.construct(this->m_begin + _pos, val);
		std::uninitialized_copy_n(_tmp, _size - _pos, this->m_begin + _pos + 1);
		this->_M_deallocate(_tmp, size() - _pos);
		return (this->m_begin + _pos); 
	}

	void		insert(iterator position, size_type n, const value_type& val)
	{
		size_type	_size = (size()) + n;
		size_type	_n = n;
		size_type	_pos = position - this->m_begin;
		pointer		_tmp;

		if (n == 0)
			return ;
		if (n > max_size())
			throw "length error";
		if (_size > capacity())
			assign(_size, val);
		_tmp = this->_M_allocate(size() - _pos);
		std::uninitialized_copy_n(this->m_begin + _pos, size() - _pos, _tmp);
		while (_n)
		{
			this->m_alloc.construct(this->m_begin + _pos + _n, val);
			_n--;
		}
		std::uninitialized_copy_n(_tmp, _size - _pos, this->m_begin + _pos);
		this->_M_deallocate(_tmp, size() - _pos);
	}

template <class InputIterator>
void		insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
{
		size_type	_n = (last - first);
		size_type	_size = (size()) + _n;
		size_type	_pos = position - this->m_begin;
		pointer		_tmp;

		if (position < begin() ||  end() < position || &(*first) > &(*last))
                 throw std::out_of_range("vector");
		if (_size > capacity())
			resize(_size);
		_tmp = this->_M_allocate(_size);
		std::uninitialized_copy_n(this->m_begin + _pos, size() - _pos, _tmp);
		try
		{
			for (size_type i = 0; first != last; i++)
			{
				// this->m_alloc.destroy(this->m_begin + _pos + i);
				this->m_alloc.construct(this->m_begin + _pos + i, *first++);
			}
		}
		catch(...)
		{
			for (size_type i = 0; i < _size; i++)
				this->m_alloc.destroy(_tmp + i);
			for (size_type i = 0; i < size(); i++)
				this->m_alloc.destroy(this->m_begin + i);
			// this->_M_deallocate(this->m_begin, size());
			this->_M_deallocate(_tmp, _size);
			this->m_cap = this->m_begin;
			this->m_end = this->m_begin;
			// for (size_type i = 0; i < _n; i++)
			// 	this->m_alloc.destroy(first + i);
			// this->_M_deallocate(first, _n);
			throw;
		}
		std::uninitialized_copy_n(_tmp, _size - _pos, this->m_begin + _pos);
		for (size_type i = 0; i < _size; i++)
				this->m_alloc.destroy(_tmp + i);
		this->_M_deallocate(_tmp, _size);
		this->m_end = this->m_begin + _size;
}

iterator	erase(iterator position)
{                                                           
	size_type	_pos = position - this->m_begin;
	size_type	_size = (size()) - _pos - 1;
	pointer		_tmp;

	_tmp = this->_M_allocate(_size);
	std::uninitialized_copy_n(this->m_begin + _pos + 1, size() - _pos - 1, _tmp);
	this->m_alloc.destroy(this->m_begin + _pos);
	std::uninitialized_copy_n(_tmp, _size, (this->m_begin + _pos));
	this->_M_deallocate(_tmp, _size);
	this->m_end -= 1;
	return (this->m_begin + _pos);
}

iterator	erase(iterator first, iterator last)
{
	size_type	_n = (last - first);
	size_type	_pos = first - this->m_begin;
	size_type	_size = (size()) - _pos - _n;
	pointer		_tmp;

	_tmp = this->_M_allocate(_size);
	std::uninitialized_copy_n(this->m_begin + _pos + _n, size() - _pos - _n, _tmp);
	this->m_end -= _n;
	while (_n--)
		this->m_alloc.destroy(this->m_begin + _n + _pos);
	std::uninitialized_copy_n(_tmp, _size, (this->m_begin + _pos));
	this->m_alloc.deallocate(_tmp, _size);
	return (this->m_begin + _pos);
}

void		swap(Vector& x)
{
	pointer		_tmp;
	size_type	_cap = capacity();
	size_type	_size = size();

	_tmp = this->_M_allocate(_size);
	std::uninitialized_copy_n(this->m_begin, _size, _tmp);
	this->m_alloc.deallocate(this->m_begin, _cap);
	this->m_begin = x.m_begin;
	this->m_end = x.m_end;
	this->m_cap = x.m_cap;
	x.m_begin = _tmp;
	x.m_end = _tmp + _size;
	x.m_cap = _tmp + _cap;

	// pointer		_tmp;
	// size_type	_cap = capacity();
	// size_type	_size = size();

	// _tmp = this->m_begin;
	// this->m_begin = x.m_begin;
	// this->m_end = x.m_end;
	// this->m_cap = x.m_cap;
	// x.m_begin = _tmp;
	// x.m_cap = _tmp + _cap;
	// x.m_end = _tmp + _size;
}

void		clear() // memory alives
{
	while (this->m_begin != this->m_end--)
		this->m_alloc.destroy(this->m_end);
	this->m_end = this->m_begin;
}

// Allocator
allocator_type	get_allocator() const
{
	return (this->m_alloc);
}

};
// Non-member function overloads

template <class T, class Alloc>  
bool operator== (const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return false;
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
}

template <class T, class Alloc>  
bool operator!= (const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs)
{
	if (!(lhs == rhs))
		return true;
	return false;
}

template <class T, class Alloc>  
bool operator< (const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <class T, class Alloc>  
bool operator<= (const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs)
{
	if (!(rhs < lhs))
		return true;
	return false;
}

template <class T, class Alloc>  
bool operator> (const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs)
{
	if (rhs < lhs)
		return true;
	return false;
}

template <class T, class Alloc>  
bool operator>= (const ft::Vector<T,Alloc>& lhs, const ft::Vector<T,Alloc>& rhs)
{
	if (!(lhs < rhs))
		return true;
	return false;
}

}

#endif