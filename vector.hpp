#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <vector>

# include "Iterator.hpp"

# define FT_NOEXCEPT throw()


namespace ft
{

template <class T, class Allocator = std::allocator<T>>
class VectorBase
{
public:
    typedef Allocator									allocator_type;
    typedef typename allocator_traits<allocator_type>	__alloc_traits;
    typedef typename allocator_type::size_type			size_type;

protected:
    typedef T											value_type;
    typedef value_type&									reference;
    typedef const value_type&							const_reference;
    typedef typename allocator_type::difference_type	difference_type;
    typedef typename allocator_type::pointer			pointer;
    typedef typename allocator_type::const_pointer		const_pointer; // 글고 이거 이름 이터레이터랑 겹쳐도 되는거임???

	typedef pointer										iterator;
    typedef const_pointer								const_iterator;

	/* element */
    iterator											m_begin;		// begin iterator
    iterator											m_end;			// end iterator
    iterator											m_cap;			// capacity
	allocator_type										m_a;			// allocator type

	/* method */
	VectorBase() FT_NOEXCEPT : m_begin(NULL), m_end(NULL), m_cap(NULL), m_a(allocator_type) {}
	VectorBase(const allocator_type& __a);
	VectorBase(allocator_type&& m_a) FT_NOEXCEPT;
	
	~VectorBase();
	{
		if (m_begin != NULL)
		{
			clear();
			__alloc_traits::deallocate(__alloc(), m_begin, _M_capacity());
		}
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

	void _M_copy_data(const VectorBase& obj)
	{
		this->m_begin = obj.m_begin;
		this->m_end = obj.m_end;
		this->m_cap = obj.m_cap;
		this->m_a = obj.m_a;
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
		return static_cast<size_type>(m_end - m_begin);
	}

	void	_M_create_storage(size_t n, const value_type& val)
	{
		this->m_begin = m_a.allocate(n);
		for (size_t i = 0; n > i; i++)
		{
			m_begin = m_a.construct(n, val);
			m_begin++;
		}
	}

	iterator	_M_allocate(size_t n)
	{
		if (n != 0)
		{
			// 
		}
	}
};

template <class T, class Allocator = std::allocator<T>>
class Vector : private VectorBase <class T, class Allocator>
{
private:
	typedef VectorBase<T, Allocator>				__base;
	typedef std::allocator<T>							__default_allocator_type;

public:
    typedef T										value_type;
    typedef Allocator								allocator_type;
    typedef typename __base::__alloc_traits			__alloc_traits;
    typedef typename __base::reference				reference;
    typedef typename __base::const_reference		const_reference;
    typedef typename __base::pointer				pointer;
    typedef typename __base::const_pointer			const_pointer;
    typedef typename __base::size_type				size_type;
    typedef typename __base::difference_type		difference_type;
    typedef ft::random_access_iterator<T>::pointer					iterator;
    typedef __wrap_iter<const_pointer>				const_iterator;
    typedef _VSTD::reverse_iterator<iterator>		reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>	const_reverse_iterator;

	explict Vector();
	explict Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	Vector(const vector& x);
	~Vector();
	vector& operator= (const vector& x);

	// iterator
	iterator		begin();
	const_iterator	begin() const;
	iterator		end();
	const_iterator	end() const;
	iterator		rbegin();
	const_iterator	rbegin() const;
	iterator		rend();
	const_iterator	rend() const;
	iterator		cbegin();
	const_iterator	cbegin() const;
	iterator		cend();
	const_iterator	cend() const;
	iterator		crbegin();
	const_iterator	crbegin() const;
	iterator		crend();
	const_iterator	crend() const;

	//capacity
	size_type	size() const;
	size_type	max_size() const; // maximum number of a vector container can hold as content. != capacity
	void		resize(size_type n, value_type val = value_type());
	size_type	capacity() const;
	bool		empty() const;
	void		reverse(size_type n);

	// element access
	reference 			operator[](size_type n);
	const reference		operator[](size_type n) const;
	reference			at(size_type n);
	const_reference		at(size_type n) const;
	reference			front();
	const reference		front() const;
	reference			back();
	const_reference		back() const;
	value_type*			data() FT_NOEXCEPT; // no except c++ 11?? const ??  https://en.cppreference.com/w/cpp/container/vector/data
	const value_type	data() const FT_NOEXCEPT;

	// modifiers
	template <class InputIterator>
	void		assign(InputIterator first, InputIterator last);
	void		assign(size_type n, const value_type& val);
	void		push_back(const value_type& val);
	void		pop_back();
	iterator	insert(iterator position, const value_type& val);
	void		insert(iterator position, size_type n, const value_type& val);
	template <class InputIterator>
	void		insert(iterator position, InputIterator first, InputIterator last);
	iterator	erase(iterator position);
	iterator	erase(iterator first, iterator last);
	void		swap(Vector& x);
	void		clear(); // memory alives

	allocator_type	get_allocator() const;

	explict Vector() {}
	explict Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
	{
		_M_create_storage(n, val);
	}
	template <class InputIterator>
	Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	Vector(const vector& x)
	Vector::~Vector()
{
}

};

}

#endif