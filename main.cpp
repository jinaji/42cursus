#include <vector>
#include <string>
#include "Vector.hpp"
#include <type_traits>

int main()
{
	// ft::Vector<std::string> test(5, "hi");
	// ft::Vector<std::string>::iterator it = test.begin();
	// ft::Vector<std::string>::iterator ite = test.end();
	
	// for (; it != ite; it++)
	// 	std::cout << *it << std::endl;

	// std::cout << std::endl;

	// std::vector<std::string> stest(5, "hi");
	// std::vector<std::string>::iterator sit = stest.begin();
	// std::vector<std::string>::iterator site = stest.end();
	
	// for (; sit != site; sit++)
	// 	std::cout << *sit << std::endl;

	// ft::Vector<std::string> test5(test);
	// ft::Vector<std::string>::iterator it5 = test5.begin();
	// ft::Vector<std::string>::iterator ite5 = test5.end();

	// for (; it5 != ite5; it5++)
	// 	std::cout << *it5 << std::endl;

	// ft::Vector<std::string>	test2(it, ite);
	// ft::Vector<std::string>::iterator it2 = test2.begin();
	// ft::Vector<std::string>::iterator ite2 = test2.end();
	
	// for (; it2 != ite2; it2++)
	// 	std::cout << *it2 << std::endl;

	// ft::Vector<int>				test3(5, 1);
	// ft::Vector<int>::iterator 	it3 = test3.begin();
	// ft::Vector<int>::iterator 	ite3 = test3.end();

	// int* p = test3.data();
	// *p = 10;
	// ++p;
	// *p = 20;

	// for (; it3 != ite3; it3++)
	// 	std::cout << *it3 << std::endl;

	// std::numeric_limits<T>::is_integral()

	// std::cout << std::endl;

	// test3.front() += 1;
	// std::cout << test3.front() << std::endl;

	// it3 = test3.begin();
	// for (; it3 != ite3; it3++)
	// 	std::cout << *it3 << std::endl;


	// std::vector<int>				stest3(5);
	// std::vector<int>::iterator 	sit3 = stest3.begin();
	// std::vector<int>::iterator 	site3 = stest3.end();

	// std::cout << "size " << (stest3.size()) << std::endl;
	// std::cout << "capacity " << (stest3.capacity()) << std::endl;
	// std::cout << "end - begin " << (stest3.end() - stest3.begin()) << std::endl;
	// int* p = stest3.data();
	// *p = 10;
	// ++p;
	// *p = 20;
	// for (; sit3 != site3; sit3++)
	// 	std::cout << *sit3 << std::endl;

	// std::cout << "resize " << std::endl;

	// stest3.resize(5);
	// sit3 = stest3.begin();
	// site3 = stest3.end();
	// for (; sit3 != site3; sit3++)
	// 	std::cout << *sit3 << std::endl;

	// std::vector<int>				test4(5, 1);
	// std::vector<int>::iterator 	it4 = test4.begin();
	// std::vector<int>::iterator 	ite4 = test4.end();


	// std::cout << it << std::endl;
	// std::cout << ite << std::endl;

  { // assign
// {std::vector<int> first;
//   std::vector<int> second;
//   std::vector<int> third;

//   first.assign (7,100);             // 7 ints with a value of 100

//   std::vector<int>::iterator it;
//   it=first.begin() + 1;

//   second.assign (it, (first.end() - 1)); // the 5 central values of first

//   int myints[] = {1776,7,4};
//   third.assign (myints, (myints+3));   // assigning from array.

//   std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << "\n \n \n";}

//   ft::Vector<int> first;
//   ft::Vector<int> second;
//   ft::Vector<int> third;

//   first.assign (7,100);             // 7 ints with a value of 100
//   ft::Vector<int>::iterator it;
//   it=first.begin() + 1;

//   second.assign (it, (first.end() - 1)); // the 5 central values of first

//   int myints[] = {1776,7,4};
//   third.assign (myints, (myints+3));   // assigning from array.

//   std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << '\n';
//   return 0;
// }

// {
  // constructors used in the same order as described above:
//   ft::Vector<int> first;                                // empty vector of ints
//   ft::Vector<int> second (4,100);                       // four ints with value 100
//   ft::Vector<int> third (second.begin(),second.end());  // iterating through second
//   ft::Vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
//   int myints[] = {16,2,77,29};
//   ft::Vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (ft::Vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// {
//   std::vector<int> myvector;
//   int myint;

//   std::cout << "Please enter some integers (enter 0 to end):\n";

//   do {
//     std::cin >> myint;
//     myvector.push_back (myint);
//   } while (myint);

//   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

//   return 0;
// }
// std::cout << std::endl;
{
  ft::Vector<int> myvector;
  int myint;

  std::cout << "Please enter some integers (enter 0 to end):\n";

  do {
    std::cin >> myint;
    myvector.push_back (myint);
  } while (myint);

  std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

  return 0;
}

}

} 