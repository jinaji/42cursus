/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:06:29 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/23 18:48:27 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_arg(t_sl *s, char *map)
{
	ft_memset(s, 0, sizeof(t_sl));
	s->mlx = mlx_init();
	s->m = is_valid_map(map, s);
	s->win = mlx_new_window(s->mlx, s->img.width, s->img.height, "so_long");
	init_image(s);
	get_xy(s);
}

int	main(int ac, char **av)
{
	t_sl	s;

	if (ac != 2)
		ft_error("wrong format");
	init_arg(&s, av[1]);
	mlx_hook(s.win, 02, 0, get_move, &s);
	mlx_hook(s.win, 17, 0, exit_game, &s);
	mlx_loop(s.mlx);
}
