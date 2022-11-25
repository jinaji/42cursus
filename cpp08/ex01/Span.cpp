#include "Span.hpp"

Span::Span() : n(0), store(0)
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
	this->n = obj.n;
	this->store.assign(obj.store.begin(), obj.store.end());
}

Span::~Span()
{
}


Span::Span(unsigned int n) : n(n), store(n)
{
}

void Span::addNumber(int n)
{
	if (std::find(store.begin(), store.end(), n) == store.end())
		throw(doubleAdd());
}

int Span::shortestSpan()
{

}

int Span::longestSpan()
{

}
