#include "../cub3D.h"

static int	get_dir(t_table *table, t_ray *ray, int *col, double angle)
{
	int	tex_idx;

	tex_idx = 0;
	if (ray->vertical && cos(angle) < 0)
		tex_idx = WEST;
	else if (ray->vertical)
		tex_idx = EAST;
	else if (!ray->vertical && sin(angle) < 0)
		tex_idx = NORTH;
	else
		tex_idx = SOUTH;
	if (ray->vertical && cos(angle) < 0)
		*col = (int)((1.0 - (ray->inter.y - (int)ray->inter.y))
				* (double)table->img_ptr[tex_idx].width);
	else if (ray->vertical)
		*col = (int)((ray->inter.y - (int)ray->inter.y)
				* (double)table->img_ptr[tex_idx].width);
	else if (!ray->vertical && sin(angle) < 0)
		*col = (int)((ray->inter.x - (int)ray->inter.x)
				* (double)table->img_ptr[tex_idx].width);
	else
		*col = (int)((1.0 - (ray->inter.x - (int)ray->inter.x))
				* (double)table->img_ptr[tex_idx].width);
	return (tex_idx);
}

static void	draw_floor(t_table *table, int j, int size)
{
	while (j < HEIGHT)
	{
		ft_put_pixel(table, size, j, (table->map->floor[0] << 16
				| table->map->floor[1] << 8 | table->map->floor[2]));
		j++;
	}
}

static void	draw_ceil(t_table *table, int j, int size)
{
	int	index;

	index = 0;
	while (index < j && j >= 0)
	{
		ft_put_pixel(table, size, index, (table->map->ceil[0] << 16
				| table->map->ceil[1] << 8 | table->map->ceil[2]));
		index++;
	}
}

static void	draw_img_mapped(t_table *table, double angle, t_ray *ray, int size)
{
	double	index;
	int		tmp;
	int		tex_idx;
	double	step;
	int		col;

	tex_idx = get_dir(table, ray, &col, angle);
	index = 0.0;
	tmp = (int)(HEIGHT / 2.0 - (ray->line_len / 2.0));
	draw_ceil(table, tmp, size);
	step = table->img_ptr[tex_idx].height / (double)ray->line_len;
	while (tmp < (int)(HEIGHT / 2.0 + (ray->line_len / 2.0)))
	{
		if (tmp <= HEIGHT && tmp >= 0)
			ft_put_pixel(table, size, tmp, \
				ft_get_pixel(&table->img_ptr[tex_idx], col, (int)index));
		tmp++;
		index += step;
	}
	draw_floor(table, tmp, size);
}

void	ft_draw(t_table *table)
{
	int		x;
	int		line_len;
	t_draw	draw;
	t_ray	ray;

	x = 0 - WIDTH / 2;
	while (x++ < WIDTH / 2)
	{
		draw.angle = bound_angle(table->player.angle + (double)x
				* ((double)FOV / WIDTH) * (M_PI / 180.0));
		draw.ca = bound_angle((double)x
				* ((double)FOV / WIDTH) * (M_PI / 180.0));
		draw.len = get_ray_len(table, draw.angle, &ray);
		draw.len *= cos(draw.ca);
		line_len = (int)(atan2(0.5, draw.len) * (180.0 / M_PI)
				/ ((double)FOV / WIDTH) * 2.0);
		ray.line_len = line_len;
		draw_img_mapped(table, draw.angle, &ray, x + WIDTH / 2);
	}
	mlx_put_image_to_window(table->mlx, table->win, table->img, 0, 0);
}
