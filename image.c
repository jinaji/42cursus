/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:27:02 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/23 18:29:01 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_to_window(t_sl *s, int w, int h)
{
	if (s->m[h][w] == '1')
		mlx_put_image_to_window(s->mlx, \
		s->win, s->img.wall, 64 * w, 64 * h);
	else if (s->m[h][w] == '0')
		mlx_put_image_to_window(s->mlx, \
		s->win, s->img.tile, 64 * w, 64 * h);
	else if (s->m[h][w] == 'C')
		mlx_put_image_to_window(s->mlx, \
		s->win, s->img.col, 64 * w, 64 * h);
	else if (s->m[h][w] == 'P')
		mlx_put_image_to_window(s->mlx, \
		s->win, s->img.cha, 64 * w, 64 * h);
	else if (s->m[h][w] == 'E')
		mlx_put_image_to_window(s->mlx, \
		s->win, s->img.key, 64 * w, 64 * h);
}

void	put_image(t_sl *s)
{
	int	w;
	int	h;

	h = 0;
	while (s->height > h)
	{
		w = 0;
		while (s->width > w)
		{
			image_to_window(s, w, h);
			w++;
		}
		h++;
	}
}

void	init_image(t_sl *s)
{
	int	width;
	int	height;

	s->img.cha = \
	mlx_xpm_file_to_image(s->mlx, "./image/character1.xpm", &width, &height);
	s->img.col = \
	mlx_xpm_file_to_image(s->mlx, "./image/collect.xpm", &width, &height);
	s->img.key = \
	mlx_xpm_file_to_image(s->mlx, "./image/key.xpm", &width, &height);
	s->img.tile = \
	mlx_xpm_file_to_image(s->mlx, "./image/tile.xpm", &width, &height);
	s->img.wall = \
	mlx_xpm_file_to_image(s->mlx, "./image/wall.xpm", &width, &height);
	put_image(s);
}
