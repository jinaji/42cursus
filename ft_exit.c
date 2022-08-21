/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:18:41 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/19 16:47:33 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	digit_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		printf ("exit\n");
		return (0);
	}
	else if (!digit_check(av[1]))
	{
		printf ("exit\n");
		printf ("shellname: exit: %s: numeric argument required\n", av[1]);
		// ㅇㅕ기서 종종료료되되는  애애들들은  exit 진짜 박음 되는건가 ???
		return (255);
	}
	else if (ac > 2)
	{
		printf ("exit\n");
		printf ("shellname: exit: too many arguments\n");
		return (1);
	}
	else
	{
		printf ("exit\n");
		exit (ft_atoi(av[1]) % 256);
	}
}
