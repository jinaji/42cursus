#include "Base.hpp"
#include <cmath>

Base*	generate(void)
{
	int i = rand() % 3;
	switch(i)
	{
		case 0:
			return (new A);
		case 1:
			return (new B);
		case 2:
			return (new C);
	}
}

void	identify(Base* p)
{

}

void	indentify(Base& p)
{

}

int main()
{
	//	다운캐스팅 되는지 어케봄??
}