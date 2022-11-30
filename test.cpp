#include <vector>
#include <iostream>

int main()
{

		std::vector<int> a(0, 2);
		std::vector<int>::iterator it = a.begin();
		std::cout << *it << std::endl;
	}
	
	
}