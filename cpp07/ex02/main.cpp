#include "Array.hpp"

void lk()
{
	system("leaks a.out | grep leaked");
}

int main()
{
	unsigned int n = 3;

	{
		Array<int>	test(n);
		size_t i = test.size();
		std::cout << "size: " << i << std::endl;
		try
		{
			for (size_t size = 0; i > size; size++)
			{
				if (test[size] == 0)
					std::cout << "index " << size << ": " << "0" << std::endl;
				else
					std::cout << "index " << size << ": " << test[size] << std::endl;
			}
			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		test[0] = 1;
		test[1] = 2;
		test[2] = 3;
		try
		{
			for (size_t size = 0; i > size; size++)
			{
				if (test[size] == 0)
					std::cout << "index " << size << ": " << "0" << std::endl;
				else
					std::cout << "index " << size << ": " << test[size] << std::endl;
			}
			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << std::endl;

	{
		Array<std::string>	test(n);
		size_t i = test.size();
		std::cout << "size: " << i << std::endl;
		try
		{
			for (size_t size = 0; i > size; size++)
			{
				if (test[size].empty())
					std::cout << "index " << size << ": " << "NULL" << std::endl;
				else
					std::cout << "index " << size << ": " << test[size] << std::endl;
			}
			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		test[0] = "hi";
		test[1] = "hello";
		test[2] = "bye";
		try
		{
			for (size_t size = 0; i > size; size++)
			{
				if (test[size].empty())
					std::cout << "index " << size << ": " << "0" << std::endl;
				else
					std::cout << "index " << size << ": " << test[size] << std::endl;
			}
			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl << std::endl;

	{
		Array<char>	test(n);
		size_t i = test.size();
		std::cout << "size: " << i << std::endl;
		try
		{
			for (size_t size = 0; i > size; size++)
			{
				if (test[size] == 0)
					std::cout << "index " << size << ": " << "0" << std::endl;
				else
					std::cout << "index " << size << ": " << test[size] << std::endl;
			}
			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
		test[0] = 'a';
		test[1] = 'b';
		test[2] = 'c';
		try
		{
			for (size_t size = 0; i > size; size++)
			{
				if (test[size] == 0)
					std::cout << "index " << size << ": " << "0" << std::endl;
				else
					std::cout << "index " << size << ": " << test[size] << std::endl;
			}
			std::cout << "index " << i << ": " << test[i + 1] << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	std::cout << std::endl;
	atexit(lk);
}