/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:06:12 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 18:06:12 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	replace_void(t_map *parsing)
{
	int		i;
	int		j;
	char	**dup;

	i = 0;
	while (parsing->array[i])
	{
		j = 0;
		while (parsing->array[i][j])
		{
			if (parsing->array[i][j] == ' ')
			{
				dup = dup_map(parsing->array, parsing->height);
				if (!check_open_wall(dup, i, j))
					parsing->array[i][j] = '0';
				free_split(dup);
			}
			j++;
		}
		i++;
	}
}
