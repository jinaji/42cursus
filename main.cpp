#include <vector>
#include <string>
#include "Vector.hpp"

#define _ratio 1000
#define _vector ft::Vector


// template <typename T>
// std::vector<int> insert_test_2(std::vector<T> vector) 
// {
//     std::vector<int> v;
//     vector.assign(1000, 1);
//     vector.insert(vector.end() - 50, 4200 * _ratio , 2);
// 	std::cout << "size " << vector.size() << " cap " << vector.capacity() << std::endl; 
//     v.push_back(vector[2121]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     return v;
// }

// template <typename T>
// std::vector<int> insert_test_2(ft::Vector<T> vector) {
//     std::vector<int> v;
//     vector.assign(1000, 1);
//     vector.insert(vector.end() - 50, 4200 * _ratio , 2);
// 	std::cout << "size " << vector.size() << " cap " << vector.capacity() << std::endl; 
//     v.push_back(vector[2121]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     return v;
// }

// bool mycomp (char c1, char c2)
// { return std::tolower(c1)<std::tolower(c2); }

// template <typename T>
// std::vector<int> resize_test(std::vector<T> vector) {
//     std::vector<int> v;
//     vector.assign(9900 * _ratio, 1);
//     vector.resize(5000 * _ratio);
//     vector.reserve(5000 * _ratio);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(7000 * _ratio);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(15300 * _ratio, T());
// 	// std::cout << vector.size() << std::endl;
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     v.push_back(vector[65]);
//     return v;
// }

// template <typename T>
// ft::Vector<int> resize_test(ft::Vector<T> vector) {
//     ft::Vector<int> v;
//     vector.assign(9900 * _ratio, 1);
//     vector.resize(5000 * _ratio);
//     vector.reserve(5000 * _ratio);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(7000 * _ratio);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     vector.resize(15300 * _ratio, T());
// 	// std::cout << vector.size() << std::endl;
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());
//     v.push_back(vector[65]);
// 	// std::cout << vector[65] << std::endl;
//     return v;
// }

// template <typename T>
// std::vector<int> insert_std_test(std::vector<T> vector) {
// 	std::vector<int> v;
// 	std::vector<int> tmp;
// 	tmp.assign(2600 * _ratio, 1);
// 	vector.assign(4200 * _ratio, 7);
// 	vector.insert(vector.begin(), tmp.begin(), tmp.end());
// 	// std::cout << vector.size() << " " << vector.capacity() << std::endl;
// 	// for (size_t i = 0; i < tmp.size(); ++i) {
// 	// 	v.push_back(vector[i]);
// 	// }
// 	v.push_back(vector.size());
// 	v.push_back(vector.capacity());
// 	return v;
// }

// template <typename T>
// ft::Vector<int> insert_std_test(ft::Vector<T> vector) {
// 	ft::Vector<int> v;
// 	ft::Vector<int> tmp;
// 	tmp.assign(2600 * _ratio, 1);
// 	vector.assign(4200 * _ratio, 7);
// 	vector.insert(vector.begin(), tmp.begin(), tmp.end());
// 	// std::cout << vector.size() << " " << vector.capacity() << std::endl;
// 	// for (size_t i = 0; i < tmp.size(); ++i) {
// 	// 	v.push_back(vector[i]);
// 	// }
// 	v.push_back(vector.size());
// 	v.push_back(vector.capacity());
// 	return v;
// }

class B {
public:
    char *l;
    int i;
    B():l(nullptr), i(1) {};
    B(const int &ex) {
        this->i = ex;
        this->l = new char('a');
    };
    virtual ~B() {
        delete this->l;
        this->l = nullptr;
    };
};

class A : public B {
public:
    A():B(){};
    A(const B* ex){
        this->l = new char(*(ex->l));
        this->i = ex->i;
        if (ex->i == -1) throw "n";
    }
    ~A() {
        delete this->l;
        this->l = nullptr;
    };
};

template <typename T>
std::vector<int> insert_test_3(std::vector<T> vector) {
    std::vector<int> v;
    std::vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    std::vector<A> vv;
    std::vector<B*> v1;

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}

template <typename T>
std::vector<int> insert_test_3(_vector<T> vector) {
    std::vector<int> v;
    _vector<int> tmp;
    tmp.assign(2600 * _ratio, 1);
    vector.assign(4200 * _ratio, 1);
    vector.insert(vector.end() - 1000 * _ratio, tmp.begin(), tmp.end());
    v.push_back(vector[3]);
    v.push_back(vector.size());
    v.push_back(vector.capacity());

    std::unique_ptr<B> k2(new B(3));
    std::unique_ptr<B> k3(new B(4));
    std::unique_ptr<B> k4(new B(-1));
    _vector<A> vv;
    _vector<B*> v1; // 얘네 둘이 타입 달라서 담기면 안 되는데 담기는 중 

    v1.push_back(&(*k2));
    v1.push_back(&(*k3));
    v1.push_back(&(*k4));
    try { vv.insert(vv.begin(), v1.begin(), v1.end()); }
    catch (...) {
        v.push_back(vv.size());
        v.push_back(vv.capacity());
    }

    return v;
}

int main()
{

	std::vector<int> v;
	std::vector<int> v1;
	ft::Vector<int> v2;
	std::vector<int> v3;

	v1 = insert_test_3(v);

	v3 = insert_test_3(v2);

	std::cout << v1.size() << std::endl;
	std::cout << v1.capacity() << std::endl;

	for (std::vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
		std::cout << *it <<  " " ;
	std::cout << std::endl << std::endl;


	std::cout << v3.size() << std::endl;
	std::cout << v3.capacity() << std::endl;

	for (std::vector<int>::iterator it = v3.begin(); it != v3.end(); it++)
		std::cout << *it <<  " " ;
	std::cout << std::endl;


//   char foo[]="Apple";
//   char bar[]="apartment";

//   std::cout << std::boolalpha;

//   std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

//   std::cout << "Using default comparison (operator<): ";
//   std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
//   std::cout << '\n';

//   std::cout << "Using mycomp as comparison object: ";
//   std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
//   std::cout << '\n';

//   return 0;

	// std::vector<int> a;
	// // std::vector<int> b;
	// ft::Vector<int> c;
	// ft::Vector<int> b;

	// insert_test_2(a);
	// for (std::vector<int>::iterator it = a.begin(); it != a.end(); it++)
	// 	std::cout << *it << std::endl;
	// insert_test_2(b);
	// for (ft::Vector<int>::iterator it = b.begin(); it != b.end(); it++)
	// 	std::cout << *it << std::endl;



	// insert_test_2(b);
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

//   { // assign
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
// }

// {
// //   constructors used in the same order as described above:
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

//   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
//   for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
// 	std::cout << "elements" << *it << std::endl;
//   return 0;
// }
// std::cout << std::endl;
// {
//   ft::Vector<int> myvector;
//   int myint;

//   std::cout << "Please enter some integers (enter 0 to end):\n";

//   do {
//     std::cin >> myint;
//     myvector.push_back (myint);
//   } while (myint);

//   std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
//   for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
// 	std::cout << "elements" << *it << std::endl;

//   return 0;
// }

// {
// std::vector<int>	test(10);
// test.assign(5, 3);
// test.assign(3, 5);
// // std::cout << test.capacity() << std::endl;

// test.assign(7, 4);
// for (std::vector<int>::iterator it = test.begin(); it != test.end();it++)
// {
// 	std::cout << *it << std::endl;
// }
// std::cout << test.size() << " " << test.capacity() << std::endl;
// }

// std::cout << std::endl << std::endl;

// ft::Vector<int>	test(10);
// test.assign(5, 3);
// test.assign(3, 5);

// test.assign(7, 4);
// for (ft::Vector<int>::iterator it = test.begin(); it != test.end();it++)
// {
// 	std::cout << "main " << *it << std::endl;
// }
// std::cout << test.size() << " " << test.capacity() << std::endl;

// {
// 	std::vector<int> v;
// 	std::vector<int> vector;
// 	std::vector<int> tmp;
// 	std::vector<int> tmp2;

// 	vector.assign(3, 3);
//     tmp.assign(4000 * _ratio, 1);
//     tmp2.assign(4 * _ratio, 1);
//     // g_start1 = timer();
//     vector.assign(tmp.begin(), tmp.end());

//     v.push_back(vector[1]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

// 	// for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
// 	// 	std::cout << *it << " ";
// 	// std::cout << std::endl;

//     vector.assign(tmp2.begin(), tmp2.end());
//     // g_end1 = timer();
//     v.push_back(vector[444]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

// 	for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }

// {
// 	ft::Vector<int> v;
// 	ft::Vector<int> vector;
// 	ft::Vector<int> tmp;
// 	ft::Vector<int> tmp2;

// 	vector.assign(3, 3);
//     tmp.assign(4000 * _ratio, 1);
//     tmp2.assign(4 * _ratio, 1);
//     // g_start1 = timer();
//     vector.assign(tmp.begin(), tmp.end());

//     v.push_back(vector[1]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

// 	// for (ft::Vector<int>::iterator it = v.begin(); it != v.end(); it++)
// 	// 	std::cout << *it << " ";
// 	// std::cout << std::endl;

//     vector.assign(tmp2.begin(), tmp2.end());
// 	// std::cout << vector.capacity() << std::endl;
//     // g_end1 = timer();
//     v.push_back(vector[444]);
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

// 	for (ft::Vector<int>::iterator it = v.begin(); it != v.end(); it++)
// 		std::cout << *it << " ";
// 	std::cout << std::endl;
// }




// {
// std::vector<int> resize_test;

// std::cout << "std" << std::endl;
// resize_test.resize(3, 5);
// for (std::vector<int>::iterator it = resize_test.begin(); it != resize_test.end(); it++)
// 	std::cout << *it << " ";
// std::cout << std::endl;
// std::cout << "size " << resize_test.size() << std::endl << std::endl;

// resize_test.resize(5, 1);
// for (std::vector<int>::iterator it = resize_test.begin(); it != resize_test.end(); it++)
// 	std::cout << *it << " ";
// std::cout << std::endl;
// std::cout << "size " << resize_test.size() << std::endl << std::endl;
// }

// std::cout << "ft" << std::endl;

// ft::Vector<int> resize_test;

// resize_test.resize(3, 5);
// for (ft::Vector<int>::iterator it = resize_test.begin(); it != resize_test.end(); it++)
// 	std::cout << *it << " ";
// std::cout << std::endl;
// std::cout << "size " << resize_test.size() << std::endl << std::endl;

// resize_test.resize(5, 1);
// for (ft::Vector<int>::iterator it = resize_test.begin(); it != resize_test.end(); it++)
// 	std::cout << *it << " ";
// std::cout << std::endl;
// std::cout << "size " << resize_test.size() << std::endl << std::endl;


//   ft::Vector<int> myvector;
//   int sum (0);
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   for(ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); it++)
// 	std::cout << *it << std::endl;

//   while (!myvector.empty())
//   {
// 	std::cout << myvector.back() << std::endl;
//     sum+=myvector.back();
//     myvector.pop_back();
//   }

//   std::cout << "The elements of myvector add up to " << sum << '\n';

//   return 0;
//   }


/* 리사이즈리사이즈 */
/* 리사이즈리사이즈 */

//   std::vector<int> myvector;

//   // set some initial content:
//   for (size_t i = 1; i < 10; i++)
//   	myvector.push_back(i);
// //   for (size_t i=0;i<myvector.size();i++)
// //     std::cout << ' ' << myvector[i] << std::endl;

//   myvector.resize(5);
//   myvector.resize(8,100);
//   myvector.resize(12);

//   std::cout << "myvector contains:";
//   for (size_t i=0;i<myvector.size();i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
//   std::cout << myvector.capacity() << std::endl;

//   return 0;

//   ft::Vector<int> myvector (3,100);
//   ft::Vector<int>::iterator it;

//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

  // "it" no longer valid, get a new one:
//   it = myvector.begin();

//   ft::Vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "myvector contains:";
//   for (it=myvector.begin(); it<myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;

//   ft::Vector<int>::size_type sz;

//   ft::Vector<int> foo;
//   sz = foo.capacity();
//   std::cout << "making foo grow:\n";
//   for (int i=0; i<100; ++i) {
//     foo.push_back(i);
//     if (sz!=foo.capacity()) {
//       sz = foo.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//     }
//   }

//   ft::Vector<int> bar;
//   sz = bar.capacity();
//   bar.reserve(100);   // this is the only difference with foo above
//   std::cout << "making bar grow:\n";
//   for (int i=0; i<100; ++i) {
//     bar.push_back(i);
//     if (sz!=bar.capacity()) {
//       sz = bar.capacity();
//       std::cout << "capacity changed: " << sz << '\n';
//   }
// }

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
//   std::vector<int> myvector (5,100);
//   std::vector<int>::iterator it;

//   std::cout << " " << myvector.capacity() << " " << myvector.size() << std::endl;
//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

// //   "it" no longer valid, get a new one:
//   it = myvector.begin();

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "std myvector contains:";
//   std::cout << " " << myvector.capacity() << " " << myvector.size() << std::endl;
//   for (it=myvector.begin(); it < myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

// }

// std::cout << std::endl;

// {
//   ft::Vector<int> myvector (5,100);
//   ft::Vector<int>::iterator it;

//   std::cout << " " << myvector.capacity() << " " << myvector.size() << std::endl;
//   it = myvector.begin();
//   it = myvector.insert ( it , 200 );

//   myvector.insert (it,2,300);

// //   "it" no longer valid, get a new one:
//   it = myvector.begin();

//   std::vector<int> anothervector (2,400);
//   myvector.insert (it+2,anothervector.begin(),anothervector.end());

//   int myarray [] = { 501,502,503 };
//   myvector.insert (myvector.begin(), myarray, myarray+3);

//   std::cout << "ft  myvector contains:";
//   std::cout << " " << myvector.capacity() << " " << myvector.size() << std::endl;
//   for (it=myvector.begin(); it < myvector.end(); it++)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

// }

//erase
// {
//  std::vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
//   myvector.erase (myvector.begin()+3);

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.begin()+3);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';
// }

//  ft::Vector<int> myvector;

//   // set some values (from 1 to 10)
//   for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
//   myvector.erase (myvector.begin()+3);

//   // erase the first 3 elements:
//   myvector.erase (myvector.begin(),myvector.begin()+3);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

// {
//   std::vector<int> foo (3,100);   // three ints with a value of 100
//   std::vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';

// }
// {
//   ft::Vector<int> foo (3,100);   // three ints with a value of 100
//   ft::Vector<int> bar (5,200);   // five ints with a value of 200

//   foo.swap(bar);

//   std::cout << "foo contains:";
//   for (unsigned i=0; i<foo.size(); i++)
//     std::cout << ' ' << foo[i];
//   std::cout << '\n';

//   std::cout << "bar contains:";
//   for (unsigned i=0; i<bar.size(); i++)
//     std::cout << ' ' << bar[i];
//   std::cout << '\n';

// }

// {
//   std::vector<int> myvector;
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   myvector.clear();
//   myvector.push_back (1101);
//   myvector.push_back (2202);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

// }
// {
//   ft::Vector<int> myvector;
//   myvector.push_back (100);
//   myvector.push_back (200);
//   myvector.push_back (300);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//   myvector.clear();
//   myvector.push_back (1101);
//   myvector.push_back (2202);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

// }


// {
//   ft::Vector<int> myvector (5);  // 5 default-constructed ints

//   int i=0;

//   ft::Vector<int>::reverse_iterator rit = myvector.rbegin();
//   for (; rit!= myvector.rend(); ++rit)
//     *rit = ++i;

//   std::cout << "myvector contains:";
//   for (ft::Vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

//   return 0;
// }

// {
//   // constructors used in the same order as described above:
// //   std::vector<int> first;                                // empty vector of ints
//   std::vector<int> second (4,100);                       // four ints with value 100
//   std::vector<int> third (second.begin(),second.end());  // iterating through second
// //   std::vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
// //   int myints[] = {16,2,77,29};
// //   std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (std::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

// }
// {
//   // constructors used in the same order as described above:
// //   ft::Vector<int> first;                                // empty vector of ints
//   ft::Vector<int> second (4,100);                       // four ints with value 100
//   ft::Vector<int> third (second.begin(),second.end());  // iterating through second
// //   ft::Vector<int> fourth (third);                       // a copy of third

//   // the iterator constructor can also be used to construct from arrays:
// //   int myints[] = {16,2,77,29};
// //   std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

//   std::cout << "The contents of fifth are:";
//   for (ft::Vector<int>::iterator it = third.begin(); it != third.end(); ++it)
//     std::cout << ' ' << *it;
//   std::cout << '\n';

// }


// {
//   std::vector<int> myvector (10);   // 10 zero-initialized ints

//   // assign some values:
//   for (unsigned i=0; i<myvector.size(); i++)
//     myvector.at(i)=i;

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector.at(i);
//   std::cout << '\n';

// }
// {
//   ft::Vector<int> myvector (10);   // 10 zero-initialized ints

//   // assign some values:
//   for (unsigned i=0; i<myvector.size(); i++)
//     myvector.at(i)=i;

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); i++)
//     std::cout << ' ' << myvector.at(i);
//   std::cout << '\n';

// }

//   ft::Vector<int> foo (3,100);   // three ints with a value of 100
//   ft::Vector<int> bar (2,200);   // two ints with a value of 200

//   if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
//   if (foo< bar) std::cout << "foo is less than bar\n";
//   if (foo> bar) std::cout << "foo is greater than bar\n";
//   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

//   return 0;


}
