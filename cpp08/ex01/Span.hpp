#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>

class Span
{
private:
	unsigned int n;
	std::vector<int>	store;
public:
	Span();
	Span(const Span& obj);
	const Span& operator=(const Span& obj);
	~Span();

	Span(unsigned int n);
	void addNumber(int n);
	int shortestSpan();
	int longestSpan();

	public :
	class notValidCount : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("No enough elements");
		}
	};

	public :
	class doubleAdd : public std::exception
	{
		public:
		const char* what() const throw()
		{
			return ("Already exist element");
		}
	};
};

#endif