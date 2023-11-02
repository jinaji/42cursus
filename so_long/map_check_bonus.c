/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:37:09 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/23 18:37:42 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*make_map(t_sl *s, int fd)
{
	char	*save;
	char	*temp;
	int		len;

	save = ft_strdup("");
	temp = get_next_line(fd);
	if (!temp || ft_strcmp(temp, "\n"))
		ft_error ("map error 46");
	s->width = ft_strlen(temp) - 1;
	while (temp)
	{
		save = ft_strjoin(save, temp);
		if (ft_strchr(temp, '\n'))
			len = ft_strlen(temp) - 1;
		else
			len = ft_strlen(temp);
		if (len != s->width)
			ft_error("map error 56");
		s->height++;
		free (temp);
		temp = get_next_line(fd);
	}
	free (temp);
	return (save);
}

void	check_wall(char	**map, int height, int width)
{
	int	i;

	i = 0;
	height -= 1;
	width -= 1;
	while (map[0][i])
	{
		if (map[0][i] != '1' || map[height][i] != '1')
			ft_error("map error 76");
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][0] != '1' || map[i][width] != '1')
			ft_error("map error 83");
		i++;
	}
}

void	check_content(char *str, t_sl *s)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			s->map.coll++;
		else if (str[i] == 'P')
			s->map.pos++;
		else if (str[i] == 'E')
			s->map.exit++;
		else if (str[i] == '1' || str[i] == '0' || str[i] == '\n')
		{
			i++;
			continue ;
		}
		else
			ft_error("wrong map 107");
		i++;
	}
	if (s->map.pos != 1 || s->map.exit == 0 || s->map.coll == 0)
		ft_error ("map error 111");
}

char	**is_valid_map(char *map, t_sl *s)
{
	char	**tmp;
	char	*save;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error ("map open error");
	save = make_map(s, fd);
	close(fd);
	check_content(save, s);
	tmp = ft_split(save, '\n');
	check_wall(tmp, s->height, s->width);
	free (save);
	s->img.size = 64;
	s->img.width = (s->width) * 64;
	s->img.height = (s->height) * 64;
	return (tmp);
}
