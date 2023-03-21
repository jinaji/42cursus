#include "BitcoinExchange.hpp"
void lk()
{
    system("leaks btc | grep leaked");
}


int main(int ac, char **av)
{
	atexit(lk);
	BitcoinExchange exchanger;

	if (ac == 1)
	{
		std::cout << "Error: could not open file." << std::endl;
		exit (1);
	}
	try
	{
		exchanger.createDb();
		for (int i = 1; i < ac; i++)
		{
			exchanger.createList(av[i]);
			exchanger.displayList();
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}