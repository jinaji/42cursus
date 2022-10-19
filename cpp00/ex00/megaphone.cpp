#include <iostream>

int main(int ac, char **av)
{
	int	i = 1;
	int	j = 0;
	std::string	tmp;

	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (av[i])
		{
			j = 0;
			tmp = av[i];
			while (tmp[j])
			{
				if (tmp[j] >= 'a' && 'z' >= tmp[j])
					tmp[j] = toupper(tmp[j]);
				j++;
			}
			std::cout << tmp;
			i++;
		}
		std::cout << std::endl;
	}
}