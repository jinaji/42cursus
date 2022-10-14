#include <iostream>

int main(int ac, char **av)
{
	int	i = 1;
	int	j = 0;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[i])
		{
			j = 0;
			while (av[i][j])
			{
				if (av[i][j] >= 'a' && 'z' >= av[i][j])
					av[i][j] -= 32;
				j++;
			}
			std::cout << av[i];
			i++;
		}
		std::cout << std::endl;
	}
}