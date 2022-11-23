#ifndef BASE_HPP
# define BASE_HPP

class Base
{
public:
	virtual ~Base();
};

Base::~Base()
{
}

class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

Base*	generate(void);
void	identify(Base* p);
void	indentify(Base& p);

#endif