#include "so_long.h"

# define W_KEY	13
# define A_KEY	0
# define S_KEY	1
# define D_KEY	2
# define ESC_KEY	53

void	ft_error(char *str)
{
	perror(str);
	exit (1);
}

int	press_key(int key, t_key *loca)
{
	if (key == W_KEY)
		loca->y++;
	else if (key == A_KEY)
		loca->x--;
	else if (key == S_KEY)
		loca->y--;
	else if (key == D_KEY)
		loca->x++;
	else if (key == ESC_KEY)
		exit (0);
	return (0);
}

void	image(void *mlx, void *win)
{
	int	img_width;
	int	img_height;

	void	*img = mlx_xpm_file_to_image(mlx, "./image/sheet.xpm", &img_width, &img_height);
	void	*img2 = mlx_xpm_file_to_image(mlx, "./image/stone.xpm", &img_width, &img_height);
	void	*img3 = mlx_xpm_file_to_image(mlx, "./image/key.xpm", &img_width, &img_height);
	void	*img4 = mlx_xpm_file_to_image(mlx, "./image/chest.xpm", &img_width, &img_height);
	void	*img5 = mlx_xpm_file_to_image(mlx, "./image/character.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 32, 0);
	mlx_put_image_to_window(mlx, win, img3, 64, 0);
	mlx_put_image_to_window(mlx, win, img4, 96, 0);
	mlx_put_image_to_window(mlx, win, img5, 128, 0);
}

void	read_map(char *filename, t_sl *st)
{
	int		fd;
	char	*str;

	fd = open(filename, O_RDONLY);
	str = get_next_line(fd);
}

int	main(int ac, char **av)
{
	void	*mlx;
	void	*win;
	t_sl	st;
	t_key	loca;

	if (ac != 2)
		ft_error("wrong format");
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "so_long");
	read_map(av[1], &st);
	mlx_hook(win, 03, 0, &press_key, &loca);
	mlx_loop(mlx);
}
