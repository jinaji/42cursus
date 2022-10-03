/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:20:49 by jinkim2           #+#    #+#             */
/*   Updated: 2022/10/03 20:17:12 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	parser_start(t_map *parsing)
{
	int	i;

	i = -1;
	while (++i < 4)
		parsing->tex_path[i] = NULL;
	parsing->array = NULL;
}

void	parser_free(t_map *parsing)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (parsing->tex_path[i])
			free(parsing->tex_path[i]);
		i++;
	}
	if (parsing->array)
		free_split(parsing->array);
}

t_bool	parser(int argc, char **argv, t_map *parsing)
{
	char	**file;

	file = NULL;
	if (valid_arg(argc, argv) == FALSE_E)
		return (FALSE_E);
	file = dup_start(argv, file);
	if (!file)
		return (FALSE_E);
	if (vaild_img(parsing, file) == FALSE_E)
		return (free_split(file));
	if (valid_floor(parsing, file) == FALSE_E)
		return (free_split(file));
	if (valid_map(parsing, file) == FALSE_E)
		return (free_split(file));
	free_split(file);
	return (TRUE_E);
}
