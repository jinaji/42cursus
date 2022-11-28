#include "Array.hpp"

void lk()
{
	system("leaks a.out | grep leaked");
}

// int main()
// {
// 	unsigned int n = 3;

// 	{
// 		std::cout << "int" << std::endl;
// 		Array<int>	test(n);
// 		size_t i = test.size();
// 		std::cout << "size: " << i << std::endl;
// 		try
// 		{
// 			for (size_t size = 0; i > size; size++)
// 			{
// 				if (test[size] == 0)
// 					std::cout << "index " << size << ": " << "0" << std::endl;
// 				else
// 					std::cout << "index " << size << ": " << test[size] << std::endl;
// 			}
// 			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 		test[0] = 1;
// 		test[1] = 2;
// 		test[2] = 3;
// 		try
// 		{
// 			for (size_t size = 0; i > size; size++)
// 			{
// 				if (test[size] == 0)
// 					std::cout << "index " << size << ": " << "0" << std::endl;
// 				else
// 					std::cout << "index " << size << ": " << test[size] << std::endl;
// 			}
// 			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}

// 	std::cout << std::endl << std::endl;

// 	{
// 		std::cout << "string" << std::endl;
// 		Array<std::string>	test(n);
// 		size_t i = test.size();
// 		std::cout << "size: " << i << std::endl;
// 		try
// 		{
// 			for (size_t size = 0; i > size; size++)
// 			{
// 				if (test[size].empty())
// 					std::cout << "index " << size << ": " << "NULL" << std::endl;
// 				else
// 					std::cout << "index " << size << ": " << test[size] << std::endl;
// 			}
// 			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 		test[0] = "hi";
// 		test[1] = "hello";
// 		test[2] = "bye";
// 		try
// 		{
// 			for (size_t size = 0; i > size; size++)
// 			{
// 				if (test[size].empty())
// 					std::cout << "index " << size << ": " << "0" << std::endl;
// 				else
// 					std::cout << "index " << size << ": " << test[size] << std::endl;
// 			}
// 			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}

// 	std::cout << std::endl << std::endl;

// 	{
// 		std::cout << "char" << std::endl;
// 		Array<char>	test(n);
// 		size_t i = test.size();
// 		std::cout << "size: " << i << std::endl;
// 		try
// 		{
// 			for (size_t size = 0; i > size; size++)
// 			{
// 				if (test[size] == 0)
// 					std::cout << "index " << size << ": " << "0" << std::endl;
// 				else
// 					std::cout << "index " << size << ": " << test[size] << std::endl;
// 			}
// 			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 		test[0] = 'a';
// 		test[1] = 'b';
// 		test[2] = 'c';
// 		try
// 		{
// 			for (size_t size = 0; i > size; size++)
// 			{
// 				if (test[size] == 0)
// 					std::cout << "index " << size << ": " << "0" << std::endl;
// 				else
// 					std::cout << "index " << size << ": " << test[size] << std::endl;
// 			}
// 			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
// 		}
// 		catch(const std::exception& e)
// 		{
// 			std::cerr << e.what() << std::endl;
// 		}
// 	}

// 	std::cout << std::endl;
// 	atexit(lk);
// }

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];

    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers; // segfault
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete[] mirror;
	atexit(lk);
    return 0;
}