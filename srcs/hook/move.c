#include "../cub3D.h"

void	left(t_table *table)
{
	t_ray	r;
	double	angle;
	double	straight;
	t_d_vec	len;
	t_d_vec	comp;

	angle = bound_angle(table->player.angle - (M_PI / 2.0));
	len.x = get_ray_len(table, (cos(angle) < 0) * M_PI, &r);
	len.y = get_ray_len(table, (sin(angle) < 0) * M_PI + (M_PI / 2.0), &r);
	straight = get_ray_len(table, angle, &r);
	comp.x = ft_abs(cos(angle)) * straight;
	comp.y = ft_abs(sin(angle)) * straight;
	if (len.x > SPEED_MOVE * 5.0 && (!r.vertical || comp.x > SPEED_MOVE * 5.0))
		table->player.pos.x += cos(angle) * SPEED_MOVE;
	if (len.y > SPEED_MOVE * 5.0 && (r.vertical || comp.y > SPEED_MOVE * 5.0))
		table->player.pos.y += sin(angle) * SPEED_MOVE;
}

void	right(t_table *table)
{
	t_ray	r;
	double	angle;
	double	straight;
	t_d_vec	len;
	t_d_vec	comp;

	angle = bound_angle(table->player.angle + (M_PI / 2.0));
	len.x = get_ray_len(table, (cos(angle) < 0) * M_PI, &r);
	len.y = get_ray_len(table, (sin(angle) < 0) * M_PI + (M_PI / 2.0), &r);
	straight = get_ray_len(table, angle, &r);
	comp.x = ft_abs(cos(angle)) * straight;
	comp.y = ft_abs(sin(angle)) * straight;
	if (len.x > SPEED_MOVE * 5.0 && (!r.vertical || comp.x > SPEED_MOVE * 5.0))
		table->player.pos.x += cos(angle) * SPEED_MOVE;
	if (len.y > SPEED_MOVE * 5.0 && (r.vertical || comp.y > SPEED_MOVE * 5.0))
		table->player.pos.y += sin(angle) * SPEED_MOVE;
}

void	forward(t_table *table)
{
	t_ray	r;
	double	angle;
	double	straight;
	t_d_vec	len;
	t_d_vec	comp;

	angle = table->player.angle;
	len.x = get_ray_len(table, (cos(angle) < 0) * M_PI, &r);
	len.y = get_ray_len(table,
			(sin(angle) < 0) * M_PI + (M_PI / 2.0), &r);
	straight = get_ray_len(table, angle, &r);
	comp.x = ft_abs(cos(angle)) * straight;
	comp.y = ft_abs(sin(angle)) * straight;
	if (len.x > SPEED_MOVE * 5.0 && (!r.vertical || comp.x > SPEED_MOVE * 5.0))
		table->player.pos.x += cos(angle) * SPEED_MOVE;
	if (len.y > SPEED_MOVE * 5.0 && (r.vertical || comp.y > SPEED_MOVE * 5.0))
		table->player.pos.y += sin(angle) * SPEED_MOVE;
}

void	backward(t_table *table)
{
	t_ray	r;
	double	angle;
	double	straight;
	t_d_vec	len;
	t_d_vec	comp;

	angle = bound_angle(table->player.angle + M_PI);
	len.x = get_ray_len(table, (cos(angle) < 0) * M_PI, &r);
	len.y = get_ray_len(table, (sin(angle) < 0) * M_PI + (M_PI / 2.0), &r);
	straight = get_ray_len(table, angle, &r);
	comp.x = ft_abs(cos(angle)) * straight;
	comp.y = ft_abs(sin(angle)) * straight;
	if (len.x > SPEED_MOVE * 5.0 && (!r.vertical || comp.x > SPEED_MOVE * 5.0))
		table->player.pos.x += cos(angle) * SPEED_MOVE;
	if (len.y > SPEED_MOVE * 5.0 && (r.vertical || comp.y > SPEED_MOVE * 5.0))
		table->player.pos.y += sin(angle) * SPEED_MOVE;
}
