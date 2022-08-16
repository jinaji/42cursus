/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:18:41 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/16 11:28:43 by jinkim2          ###   ########seoul.kr  */
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
		exit (0);
	}
	else if (!digit_check(av[1]))
	{
		printf ("exit\n");
		printf ("shellname: exit: %s: numeric argument required\n", av[1]);
		exit (255);
	}
	else if (ac > 2)
	{
		printf ("exit\n");
		printf ("shellname: exit: too many arguments\n");
		// 종료 안 되는데 exit 코드는 1로 바뀜 어케함
	}
	else
	{
		printf ("exit\n");
		exit (ft_atoi(av[1]) % 256);
	}
}
