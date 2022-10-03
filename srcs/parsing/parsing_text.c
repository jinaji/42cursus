/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:30:04 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 18:02:57 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

t_bool	valid_arg(int argc, char **argv)
{
	int	fd;

	if (argc != 2)
		return (error("./cub3D <path to map>", NULL));
	if (ft_strncmp(".cub", &argv[1][ft_strlen(argv[1]) - 4], 4))
		return (error("map format", NULL));
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror(argv[1]);
		return (FALSE_E);
	}
	close(fd);
	return (TRUE_E);
}

static t_bool	err_img(t_map *parsing, int j)
{
	int		i;
	int		fd;

	if (!parsing->tex_path[NORTH] || !parsing->tex_path[SOUTH]
		|| !parsing->tex_path[WEST] || !parsing->tex_path[EAST] || j != 4)
		return (error("map number", NULL));
	i = 0;
	while (i < 4)
	{
		fd = open(parsing->tex_path[i], O_RDONLY);
		if (fd == -1)
			return (error("img_ptr path", NULL));
		close(fd);
		i++;
	}
	return (TRUE_E);
}

t_bool	vaild_img(t_map *parsing, char **file)
{
	int		i;
	int		j;
	char	*trim;

	i = -1;
	j = 0;
	while (file && file[++i])
	{
		trim = ft_strtrim(file[i], " \t");
		if (!ft_strncmp(trim, "NO ", 3) || !ft_strncmp(trim, "SO", 2)
			|| !ft_strncmp(trim, "WE ", 3) || !ft_strncmp(trim, "EA", 2))
			j++;
		if (!ft_strncmp(trim, "NO ", 3) && !parsing->tex_path[NORTH])
			parsing->tex_path[NORTH] = ft_strtrim(trim, "NO \t");
		else if (!ft_strncmp(trim, "SO ", 3) && !parsing->tex_path[SOUTH])
			parsing->tex_path[SOUTH] = ft_strtrim(trim, "SO \t");
		else if (!ft_strncmp(trim, "WE ", 3) && !parsing->tex_path[WEST])
			parsing->tex_path[WEST] = ft_strtrim(trim, "WE \t");
		else if (!ft_strncmp(trim, "EA ", 3) && !parsing->tex_path[EAST])
			parsing->tex_path[EAST] = ft_strtrim(trim, "EA \t");
		free(trim);
	}
	if (err_img(parsing, j) == FALSE_E)
		return (FALSE_E);
	return (TRUE_E);
}
