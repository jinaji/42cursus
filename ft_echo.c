/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:44:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/21 15:03:50 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	option_check(char **str, int *op_check)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		if (str[i][j] == '-')
		{
			j++;
			while (str[i][j])
			{
				if (str[i][j] != 'n')
					break ;
				j++;
			}
		}
		if (j == ft_strlen(str[i]))
			*op_check += 1;
		else
			return ;
		i++;
	}
}

void	print_echo(int op_check, int i, int ac, char **av)
{
	while (op_check + i < ac - 1)
	{
		write (1, av[op_check + i], ft_strlen(av[op_check + i]));
		write (1, " ", 1);
		i++;
	}
	if (op_check)
		write (1, av[op_check + i], ft_strlen(av[op_check + i]));
	else
	{
		write (1, av[op_check + i], ft_strlen(av[op_check + i]));
		write (1, "\n", 1);
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	op_check;

	i = 1;
	op_check = 0;
	if (ac == 1)
	{
		printf ("\n");
		exit (0);
	}
	if (av[1][0] == '-')
		option_check(av, &op_check);
	print_echo(op_check, i, ac, av);
}
