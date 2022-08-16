/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:44:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/16 13:19:36 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	option_check(char *str, int *op_check)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return ;
		i++;
	}
	*op_check = TRUE;
}

int	main(int ac, char **av)
{
	int	i;
	int	op_check;

	i = 1;
	op_check = FALSE;
	if (ac == 1)
	{
		printf ("\n");
		exit (0);
	}
	if (av[1][0] == '-')
		option_check(av[1], &op_check);
	while (i < ac - 1)
	{
		printf ("%s ", av[i]);
		i++;
	}
	if (op_check)
		printf("%s", av[ac - 1]);
	else
		printf("%s\n", av[ac - 1]);
	exit (0);
}
// $? 되어야??하는거겟지 ??