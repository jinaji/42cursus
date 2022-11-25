#include <string>
#include <iostream>

template<typename T>
class Test{
	T val;
	public:
	Test(T v) : val(v) {};
	T getVal();
	void printInfo(){
		std::cout << val << std::endl;
	}
};

template<typename T>
T Test<T>::getVal(){
	return val;
}

int main()
{
	Test<int> t_int(10);
	Test<std::string> t_str("HI");

	t_int.printInfo();
	t_str.printInfo();
}