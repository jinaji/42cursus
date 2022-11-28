#include "iter.hpp"
#include <string>

void lk()
{
	system("leaks a.out | grep leaked");
}

template<typename T>
void test(T const& obj)
{
	std::cout << obj << std::endl;
}

int main()
{
	int arr[] = {0, 1, 2, 3, 4};

	iter(arr, 5, test);

	std::cout << std::endl;
	atexit(lk);
}