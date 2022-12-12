#include <vector>
#include <string>
#include "Vector.hpp"

#define _ratio 1000
#define _vector ft::Vector

bool operator_not_equal_test() {
    std::vector<int> result, result_2;
    std::vector<int> v_int1, v_int2, v_int3;
    std::vector<std::string> v_str1, v_str2;
    _vector<int> V_int1, V_int2, V_int3;
    _vector<std::string> V_str1, V_str2;
    v_int1.push_back(1);
    v_int3.push_back(1);
    v_str1.push_back("aa");
    v_str2.push_back("ab");
    result.push_back(v_int1 != v_int2);
    v_int2.push_back(2);
    result.push_back(v_int1 != v_int2);
    result.push_back(v_int1 != v_int3);
    result.push_back(v_str1 != v_str2);
    V_int1.push_back(1);
    V_int3.push_back(1);
    V_str1.push_back("aa");
    V_str2.push_back("ab");
    result_2.push_back(V_int1 != V_int2);
    V_int2.push_back(2);
    result_2.push_back(V_int1 != V_int2);
    result_2.push_back(V_int1 != V_int3);
    result_2.push_back(V_str1 != V_str2);
    return result == result_2;
}

int main()
{
  std::vector<int> v;
	std::vector<int> v1;
	ft::Vector<int> v2;
	std::vector<int> v3;

	std::cout << operator_not_equal_test() << std::endl;

	// std::cout << v1.size() << std::endl;
	// std::cout << v1.capacity() << std::endl;

	// for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	// 	std::cout << *it <<  " " ;
	// std::cout << std::endl << std::endl;

	// std::cout << v3.size() << std::endl;
	// std::cout << v3.capacity() << std::endl;

	// for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
	// 	std::cout << *it <<  " " ;
	// std::cout << std::endl;

}