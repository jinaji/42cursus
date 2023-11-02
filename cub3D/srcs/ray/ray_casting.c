/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:08:16 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 18:11:03 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	init_ray(t_table *table, t_ray *r, double angle)
{
	r->dir.x = cos(angle);
	r->dir.y = sin(angle);
	r->step_size.x = sqrt(1.0 + pow(r->dir.y / r->dir.x, 2));
	r->step_size.y = sqrt(1.0 + pow(r->dir.x / r->dir.y, 2));
	r->start = table->player.pos;
	r->map.x = (int)r->start.x;
	r->map.y = (int)r->start.y;
	r->tile_found = FALSE_E;
	r->vertical = FALSE_E;
	if (r->dir.x < 0)
		r->len.x = (r->start.x - (double)r->map.x) * r->step_size.x;
	else
		r->len.x = ((double)(r->map.x + 1) - r->start.x) * r->step_size.x;
	r->step.x = 1 - (r->dir.x < 0) * 2;
	if (r->dir.y < 0)
		r->len.y = (r->start.y - (double)r->map.y) * r->step_size.y;
	else
		r->len.y = ((double)(r->map.y + 1) - r->start.y) * r->step_size.y;
	r->step.y = 1 - (r->dir.y < 0) * 2;
}

static void	ray_loop(t_table *table, t_ray *r)
{
	double	max_dist;

	max_dist = (double)ft_max(table->map->height, table->map->width);
	while (!r->tile_found && r->dist < max_dist)
	{
		if (r->len.x < r->len.y)
		{
			r->map.x += r->step.x;
			r->dist = r->len.x;
			r->vertical = TRUE_E;
			r->len.x += r->step_size.x;
		}
		else
		{
			r->map.y += r->step.y;
			r->dist = r->len.y;
			r->vertical = FALSE_E;
			r->len.y += r->step_size.y;
		}
		if (r->map.x >= 0 && r->map.x < table->map->width
			&& r->map.y >= 0 && r->map.y < table->map->height
			&& table->map->array[r->map.y][r->map.x] == '1')
			r->tile_found = TRUE_E;
	}
}

double	get_ray_len(t_table *table, double angle, t_ray *r)
{
	double	len;

	init_ray(table, r, angle);
	ray_loop(table, r);
	if (r->tile_found)
	{
		r->inter.x = r->dir.x * r->dist + r->start.x;
		r->inter.y = r->dir.y * r->dist + r->start.y;
	}
	len = sqrt(pow(r->inter.x - r->start.x, 2)
			+ pow(r->inter.y - r->start.y, 2));
	return (len);
}
