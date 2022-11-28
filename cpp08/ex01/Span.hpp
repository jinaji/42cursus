#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
private:
	unsigned int maxCount;
	unsigned int curCount;
	std::vector<int>	store;
public:
	Span();
	Span(const Span& obj);
	Span& operator=(const Span& obj);
	~Span();

public:
	Span(unsigned int n);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();

	public :
	class notEnoughCount : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Not enough elements");
		}
	};

	public :
	class doubleElement : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Already exist element");
		}
	};

	public :
	class sizeOver : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Size over");
		}
	};
};

#endif