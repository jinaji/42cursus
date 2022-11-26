#include "Span.hpp"
#include <algorithm>
#include <iostream>

Span::Span() : maxCount(0), curCount(0), store(0)
{
}

Span::Span(const Span& obj)
{
	*this = obj;
}

const Span& Span::operator=(const Span& obj)
{
	if (this == &obj)
		return (*this);
	this->maxCount = obj.maxCount;
	this->curCount = obj.curCount;
	this->store.assign(obj.store.begin(), obj.store.end());
	return (*this);
}

Span::~Span()
{
}


Span::Span(unsigned int n) : maxCount(n), curCount(0), store(0)
{
}

void Span::addNumber(int n)
{
	if (std::find(store.begin(), store.end(), n) != store.end())
		throw(doubleElement());
	if (maxCount == curCount)
		throw(sizeOver());
	this->store.push_back(n);
	curCount++;
}

int Span::shortestSpan()
{
	int	ret;
	std::vector<int>	tmp;

	if (2 > this->curCount)
		throw(notEnoughCount());
	tmp = this->store;
	sort(tmp.begin(), tmp.end());
	ret = *(tmp.begin() + 1) - *(tmp.begin());
	for (std::vector<int>::iterator it = tmp.begin() + 1; it != tmp.end(); it++)
	{
		if (ret > (*(it) - *(it - 1)))
			ret = (*(it) - *(it - 1));
	}
	return (ret);
}

int Span::longestSpan()
{
	std::vector<int>	tmp;

	if (2 > this->curCount)
		throw(notEnoughCount());

	tmp = this->store;
	sort(tmp.begin(), tmp.end());
	return (*(tmp.end() - 1) - *(tmp.begin()));
}
