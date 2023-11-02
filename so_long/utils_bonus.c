/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:25:57 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/23 18:49:50 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_error(char *str)
{
	write (2, "Error\n", 6);
	perror(str);
	exit (1);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	if (str2[i])
		return (0);
	return (1);
}

void	get_xy(t_sl *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->m[i])
	{
		j = 0;
		while (s->m[i][j])
		{
			if (s->m[i][j] == 'P')
			{
				s->loc.x = i;
				s->loc.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	game_clear(void)
{
	printf("game clear!\n");
	exit (0);
}

int	exit_game(void)
{
	exit (0);
	return (0);
}
