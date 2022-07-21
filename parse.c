/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 15:51:52 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/21 21:58:30 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	*make_map(t_sl *info, int fd)
{
	char	*save;
	char	*temp;
	int		len;

	save = ft_strdup("");
	temp = get_next_line(fd);
	if (!temp || ft_strcmp(temp, "\n"))
		ft_error ("map error 46");
	info->width = ft_strlen(temp) - 1;
	while (temp)
	{
		save = ft_strjoin(save, temp);
		if (ft_strchr(temp, '\n'))
			len = ft_strlen(temp) - 1;
		else
			len = ft_strlen(temp);
		if (len != info->width)
			ft_error("map error 56");
		info->height++;
		temp = get_next_line(fd);
		free (temp);
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

void	check_content(char *str, t_sl *info)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'C')
			info->map.coll++;
		else if (str[i] == 'P')
			info->map.pos++;
		else if (str[i] == 'E')
			info->map.exit++;
		else if (str[i] == '1' || str[i] == '0' || str[i] == '\n')
		{
			i++;
			continue ;
		}
		else
			ft_error("wrong map 107");
		i++;
	}
	if (info->map.pos != 1 || info->map.exit == 0 || info->map.coll == 0)
		ft_error ("map error 111");
}

char	**is_valid_map(char *map, t_sl *info)
{
	char	**tmp;
	char	*save;
	int		fd;

	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_error ("map open error");
	save = make_map(info, fd);
	close(fd);
	check_content(save, info);
	tmp = ft_split(save, '\n');
	check_wall(tmp, info->height, info->width);
	free (save);
	info->img.size = 64;
	info->img.width = (info->width) * 64;
	info->img.height = (info->height) * 64;
	return (tmp);
}

void	put_image(t_sl *info)
{
	int	wid;
	int	hei;

	hei = 0;
	while (info->height > hei)
	{
		wid = 0;
		while (info->width > wid)
		{
			if (info->map.map[hei][wid] == '1')
				mlx_put_image_to_window(info->mlx, \
				info->win, info->img.wall, 64 * wid, 64 * hei);
			else if (info->map.map[hei][wid] == '0')
				mlx_put_image_to_window(info->mlx, \
				info->win, info->img.tile, 64 * wid, 64 * hei);
			else if (info->map.map[hei][wid] == 'C')
				mlx_put_image_to_window(info->mlx, \
				info->win, info->img.collect, 64 * wid, 64 * hei);
			else if (info->map.map[hei][wid] == 'P')
				mlx_put_image_to_window(info->mlx, \
				info->win, info->img.character, 64 * wid, 64 * hei);
			else if (info->map.map[hei][wid] == 'E')
				mlx_put_image_to_window(info->mlx, \
				info->win, info->img.key, 64 * wid, 64 * hei);
			wid++;
		}
		hei++;
	}
}

void	init_image(t_sl *info)
{
	int	width;
	int	height;

	info->img.character = \
	mlx_xpm_file_to_image(info->mlx, "./image/character.xpm", &width, &height);
	info->img.collect = \
	mlx_xpm_file_to_image(info->mlx, "./image/collect.xpm", &width, &height);
	info->img.key = \
	mlx_xpm_file_to_image(info->mlx, "./image/key.xpm", &width, &height);
	info->img.tile = \
	mlx_xpm_file_to_image(info->mlx, "./image/tile.xpm", &width, &height);
	info->img.wall = \
	mlx_xpm_file_to_image(info->mlx, "./image/wall.xpm", &width, &height);
	put_image(info);
}

void	get_xy(t_sl *info)
{
	int	i;
	int	j;

	i = 0;
	while (info->map.map[i])
	{
		j = 0;
		while (info->map.map[i][j])
		{
			if (info->map.map[i][j] == 'P')
			{
				info->loca.x = i;
				info->loca.y = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	init_arg(t_sl *info, char *map)
{
	ft_memset(info, 0, sizeof(t_sl));
	info->mlx = mlx_init();
	info->map.map = is_valid_map(map, info);
	info->win = mlx_new_window(info->mlx, info->img.width, info->img.height, "so_long");
	init_image(info);
	get_xy(info);
}

void	move_w(t_sl *info)
{
	int	x;
	int	y;

	x = info->loca.x;
	y = info->loca.y;
	if (info->map.map[x + 1][y] == 1)
		return ;
	else if (info->map.map[x + 1][y])
}

int	get_move(int key, t_sl *info)
{
	if (key == W_KEY)
		move_w(info);
	else if (key == S_KEY)
		move_s(info);
	else if (key == A_KEY)
		move_a(info);
	else if (key == D_KEY)
		move_d(info);
	else if (key == ESC_KEY)
		exit (1);
	info->loca.move++;
	printf("%d\n", info->loca.move);
	return (0);
}

int	main(int ac, char **av)
{
	t_sl	info;

	if (ac != 2)
		ft_error("wrong format");
	init_arg(&info, av[1]);
	mlx_hook(info.win, 02, 0, get_move, &info);
	mlx_loop(info.mlx);
}
