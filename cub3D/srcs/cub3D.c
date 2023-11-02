/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:43:06 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 17:57:10 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	player_angle(t_map *map, t_table *table, int x, int y)
{
	if (map->array[y][x] == 'S')
		table->player.angle = M_PI * 0.5;
	else if (map->array[y][x] == 'N')
		table->player.angle = M_PI * 1.5;
	else if (map->array[y][x] == 'E')
		table->player.angle = 0.0;
	else if (map->array[y][x] == 'W')
		table->player.angle = M_PI;
}

static void	ft_player_pos(t_map *map, t_table *table)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->array[y][x] == 'N' || map->array[y][x] == 'S'
				|| map->array[y][x] == 'E' || map->array[y][x] == 'W')
			{
				table->player.pos.x = x + 0.5;
				table->player.pos.y = y + 0.5;
				player_angle(map, table, x, y);
				break ;
			}
			x++;
		}
		y++;
	}
}

static t_bool	start_init(t_map *map, t_table *table, t_img *text)
{
	table->mlx = mlx_init();
	table->win = mlx_new_window(table->mlx, WIDTH, HEIGHT, "cub3D");
	text = malloc(sizeof(t_img) * 4);
	table->img_ptr = text;
	table->map = map;
	xpm_to_image(table);
	table->img = mlx_new_image(table->mlx, WIDTH, HEIGHT);
	if (!table->img)
		return (FALSE_E);
	table->data_addr = mlx_get_data_addr(table->img, &table->bpp,
			&table->size_line, &table->endian);
	if (!table->data_addr)
		return (FALSE_E);
	return (TRUE_E);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_table	table;
	t_img	*text;

	text = NULL;
	parser_start(&map);
	if (parser(argc, argv, &map) == FALSE_E)
	{
		parser_free(&map);
		exit(1);
	}
	if (start_init(&map, &table, text) == FALSE_E)
		exit(1);
	mlx_hook(table.win, 17, 1L << 17, close_win, NULL);
	mlx_hook(table.win, 2, 1L << 0, key_down, &table);
	mlx_hook(table.win, 3, 1L << 1, key_up, &table);
	ft_player_pos(&map, &table);
	ft_memset(&table.keys, 0, sizeof(t_keys));
	table.prev_x = 0;
	mlx_loop_hook(table.mlx, game_update, &table);
	mlx_loop(table.mlx);
	free(table.img_ptr);
}
