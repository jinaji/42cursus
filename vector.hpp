#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <vector>

# define FT_NOEXCEPT throw()

namespace ft
{

template <class T, class Allocator = std::allocator<T>>
class VectorBase
{
public:
    typedef Allocator									allocator_type;
    typedef allocator_traits<allocator_type>			__alloc_traits;
    typedef typename __alloc_traits::size_type			size_type;

protected:
    typedef T											value_type;
    typedef value_type&									reference;
    typedef const value_type&							const_reference;
    typedef typename __alloc_traits::difference_type	difference_typ e;
    typedef typename __alloc_traits::pointer			pointer;
    typedef typename __alloc_traits::const_pointer		const_pointer;

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
		if (__bigin_ != nullptr)
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
};

template <class T, class Allocator = std::allocator<T>>
class Vector : private VectorBase <class T, class Allocator>
{
private:
	typedef VectorBase<T, Allocator>				__base;
	typedef allocator<T>							__default_allocator_type;
public:
    typedef vector									__self;
    typedef T										value_type;
    typedef Allocator								allocator_type;
    typedef typename __base::__alloc_traits			__alloc_traits;
    typedef typename __base::reference				reference;
    typedef typename __base::const_reference		const_reference;
    typedef typename __base::size_type				size_type;
    typedef typename __base::difference_type		difference_type;
    typedef typename __base::pointer				pointer;
    typedef typename __base::const_pointer			const_pointer;
    typedef __wrap_iter<pointer>					iterator;
    typedef __wrap_iter<const_pointer>				const_iterator;
    typedef _VSTD::reverse_iterator<iterator>		reverse_iterator;
    typedef _VSTD::reverse_iterator<const_iterator>	const_reverse_iterator;

	explict Vector();
	explict Vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
	template <class InputIterator>
	Vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	Vector(const vector& x);
	~Vector();

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