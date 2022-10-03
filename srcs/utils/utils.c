#include "../cub3D.h"

void	ft_return_error(const char *err_msg, int systeme)
{
	if (!systeme)
	{
		write(STDERR_FILENO, &err_msg, ft_strlen(err_msg));
		write(STDERR_FILENO, "\n", 1);
	}
	else
		perror(err_msg);
	exit(-1);
}

double	ft_abs(double a)
{
	if (a < 0.0)
		return (-a);
	return (a);
}

double	bound_angle(double angle)
{
	if (angle < 0)
		return (angle + 2.0 * M_PI);
	else if (angle > 2.0 * M_PI)
		return (angle - 2.0 * M_PI);
	return (angle);
}

void	xpm_to_image(t_table *table)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		table->img_ptr[i].img = mlx_xpm_file_to_image(table->mlx,
				table->map->tex_path[i], &table->img_ptr[i].width,
				&table->img_ptr[i].height);
		if (!table->img_ptr[i].img)
		{
			write(STDERR_FILENO, "Error\n\t : ", 10);
			write(STDERR_FILENO, "xmp file\n", 9);
			exit(1);
		}
		table->img_ptr[i].data_addr = mlx_get_data_addr(table->img_ptr[i].img,
				&table->img_ptr[i].bpp, &table->img_ptr[i].size_line,
				&table->img_ptr[i].endian);
		i++;
	}
}
