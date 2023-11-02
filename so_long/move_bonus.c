/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 18:38:20 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/23 18:40:19 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_w(t_sl *s)
{
	int		x;
	int		y;
	char	tmp;
	char	*move;

	x = s->loc.x;
	y = s->loc.y;
	if (s->m[x - 1][y] == '1')
		return ;
	else if (s->m[x - 1][y] == 'C')
		s->map.curc++;
	else if ((s->m[x - 1][y] == 'E') && (s->map.coll == s->map.curc))
		game_clear();
	tmp = s->m[x - 1][y];
	if (s->m[x][y] != 'E')
		s->m[x][y] = '0';
	s->m[x - 1][y] = 'P';
	s->loc.x -= 1;
	put_image(s);
	move = ft_itoa(++(s->loc.move));
	mlx_string_put(s->mlx, s->win, 20, 20, 0xFFFFFF, move);
	if (tmp == 'E')
		s->m[x - 1][y] = 'E';
	free (move);
}

void	move_s(t_sl *s)
{
	int		x;
	int		y;
	char	tmp;
	char	*move;

	x = s->loc.x;
	y = s->loc.y;
	if (s->m[x + 1][y] == '1')
		return ;
	else if (s->m[x + 1][y] == 'C')
		s->map.curc++;
	else if ((s->m[x + 1][y] == 'E') && (s->map.coll == s->map.curc))
		game_clear();
	tmp = s->m[x + 1][y];
	if (s->m[x][y] != 'E')
		s->m[x][y] = '0';
	s->m[x + 1][y] = 'P';
	s->loc.x += 1;
	put_image(s);
	move = ft_itoa(++(s->loc.move));
	mlx_string_put(s->mlx, s->win, 20, 20, 0xFFFFFF, move);
	if (tmp == 'E')
		s->m[x + 1][y] = 'E';
	free (move);
}

void	move_a(t_sl *s)
{
	int		x;
	int		y;
	char	tmp;
	char	*move;

	x = s->loc.x;
	y = s->loc.y;
	if (s->m[x][y - 1] == '1')
		return ;
	else if (s->m[x][y - 1] == 'C')
		s->map.curc++;
	else if ((s->m[x][y - 1] == 'E') && (s->map.coll == s->map.curc))
		game_clear();
	tmp = s->m[x][y - 1];
	if (s->m[x][y] != 'E')
		s->m[x][y] = '0';
	s->m[x][y - 1] = 'P';
	s->loc.y -= 1;
	put_image(s);
	move = ft_itoa(++(s->loc.move));
	mlx_string_put(s->mlx, s->win, 20, 20, 0xFFFFFF, move);
	if (tmp == 'E')
		s->m[x][y - 1] = 'E';
	free (move);
}

void	move_d(t_sl *s)
{
	int		x;
	int		y;
	char	tmp;
	char	*move;

	x = s->loc.x;
	y = s->loc.y;
	if (s->m[x][y + 1] == '1')
		return ;
	else if (s->m[x][y + 1] == 'C')
		s->map.curc++;
	else if ((s->m[x][y + 1] == 'E') && (s->map.coll == s->map.curc))
		game_clear();
	tmp = s->m[x][y + 1];
	if (s->m[x][y] != 'E')
		s->m[x][y] = '0';
	s->m[x][y + 1] = 'P';
	s->loc.y += 1;
	put_image(s);
	move = ft_itoa(++(s->loc.move));
	mlx_string_put(s->mlx, s->win, 20, 20, 0xFFFFFF, move);
	if (tmp == 'E')
		s->m[x][y + 1] = 'E';
	free (move);
}

int	get_move(int key, t_sl *s)
{
	if (key == W_KEY)
		move_w(s);
	else if (key == S_KEY)
		move_s(s);
	else if (key == A_KEY)
		move_a(s);
	else if (key == D_KEY)
		move_d(s);
	else if (key == ESC_KEY)
		exit (1);
	return (0);
}
