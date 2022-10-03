/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:06:12 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 22:09:33 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	replace_void(t_map *parsing)
{
	int		i;
	int		j;

	i = 0;
	while (parsing->array[i])
	{
		j = 0;
		while (parsing->array[i][j])
		{
			if (parsing->array[i][j] == ' ')
			{
				parsing->array[i][j] = 'B';
			}
			j++;
		}
		i++;
	}
}

t_bool	check_player_pos(t_map *parsing, t_i_vec play)
{
	int	hei;
	int	wid;
	int	x;
	int	y;

	hei = parsing->height;
	wid = parsing->width;
	x = play.x;
	y = play.y;
	if (x == 0 || x >= wid || y == 0 || y >= hei)
		return (FALSE_E);
	if (parsing->array[y][x - 1] == 'B' || parsing->array[y][x + 1] == 'B' || \
		parsing->array[y - 1][x] == 'B' || parsing->array[y + 1][x] == 'B')
		return (FALSE_E);
	else
		return (TRUE_E);
}
