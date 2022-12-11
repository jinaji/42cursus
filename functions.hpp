#ifndef FUNCTIONS_HPP
# define FUNCTIONS_HPP

# include <cstddef>

namespace ft
{

template <class T, T v>
struct integral_constant
{
	static const T value = v;
	typedef T value_type;
	typedef integral_constant<T,v> type;
	operator value_type() const { return v; }
};

typedef integral_constant<bool, true> true_type;
typedef integral_constant<bool, false> false_type;

template <class T>
struct is_integral: public false_type {};
template <>
struct is_integral<bool>: public true_type {};	
template <>
struct is_integral<char>: public true_type {};
template <>
struct is_integral<char16_t>: public true_type {};
template <>
struct is_integral<char32_t>: public true_type {};
template <>
struct is_integral<wchar_t>: public true_type {};
template <>
struct is_integral<signed char>: public true_type {};
template <>
struct is_integral<short int>: public true_type {};
template <>
struct is_integral<int>: public true_type {};
template <>
struct is_integral<long int>: public true_type {};
template <>
struct is_integral<long long int>: public true_type {};
template <>
struct is_integral<unsigned char>: public true_type {};
template <>
struct is_integral<unsigned short int>: public true_type {};
template <>
struct is_integral<unsigned int>: public true_type {};
template <>
struct is_integral<unsigned long int>: public true_type {};
template <>
struct is_integral<unsigned long long int>: public true_type {};

template <bool B, typename T = void> // 
struct enable_if {};

template <class T>
struct enable_if<true, T> {typedef T type;}; 
// https://cplusplus.com/reference/type_traits/enable_if/?kw=enable_if

template <class InputIterator1, class InputIterator2>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2) // first1 last느ㄴ 범범위위잡고 first2랑 쭉 비교하는 식인듯
{
	while (first1 != last1)
	{
		if (!(first1 == first2))
			return false;
		first1++;
		first2++;
	}
	return true;
}

template <class InputIterator1, class InputIterator2, class BinaryPredicate>
bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
	while (first1 != last1)
	{
		if (!pred(first1, first2))
			return false;
		first1++;
		first2++;
	}
	return true;
}

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) // 순차적으로 요소크기까지 비교 인데 1이 작아야 true 반환
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		first1++;
		first2++;
	}
	return (first2 != last2); // 1 끝났는데 2 남았으면 true 리턴
}

template <class InputIterator1, class InputIterator2, class Compare>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
{
	while (first1 != last1)
	{
		if (first1 == first2 || comp(*first1, *first2))
			return true;
		else if (comp(*first2, *first1))
			return false;
	// 	if (first2 == last2 || *first2 < *first)
	// 		return false;
	// 	else if (*first1 < *first2)
	// 		return true;
		first1++;
		first2++;
	}
	return (first2 != last2); // 1 끝났는데 2 남았으면 true 리턴
}

// template <typename T1, typename T2>
// struct pair
// {

// };

}

#endif