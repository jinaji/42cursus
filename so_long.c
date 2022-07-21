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

	void	*img = mlx_xpm_file_to_image(mlx, "./image/tile.xpm", &img_width, &img_height);
	void	*img2 = mlx_xpm_file_to_image(mlx, "./image/collect.xpm", &img_width, &img_height);
	void	*img3 = mlx_xpm_file_to_image(mlx, "./image/key.xpm", &img_width, &img_height);
	void	*img4 = mlx_xpm_file_to_image(mlx, "./image/wall.xpm", &img_width, &img_height);
	void	*img5 = mlx_xpm_file_to_image(mlx, "./image/character.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_put_image_to_window(mlx, win, img2, 64, 0);
	mlx_put_image_to_window(mlx, win, img3, 128, 0);
	mlx_put_image_to_window(mlx, win, img4, 192, 0);
	mlx_put_image_to_window(mlx, win, img5, 256, 0);
}

// void	read_map(char *filename, t_sl *st)
// {
// 	int		fd;
// 	char	*str;

// 	fd = open(filename, O_RDONLY);
// 	str = get_next_line(fd);
// }

char	*make_map(t_sl *info, int fd)
{
	char	*save;
	char	*temp;

	save = ft_strdup("");
	temp = get_next_line(fd);
	if (!temp || ft_strncmp(temp, "\n", 1))
		ft_error ("map error");
	info->width = ft_strlen(temp);
	info->height = 1;
	while (temp)
	{
		save = ft_strjoin(save, temp);
		free (temp);
		temp = get_next_line(fd);
		if ((ft_strlen(temp)) != info->width)
			ft_error("map error");
		info->height++;
	}
	free (temp);
	return (save);
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
	tmp = ft_split(save, '\n');
	free (save);
	return (tmp);
}

void	parse_arg(t_sl *info, char *map)
{
	ft_memset(info, 0, sizeof(t_sl));
	info->map.map = is_valid_map(map, info);	
}

void	init_mlx(t_sl *info)
{
	// info->mlx = mlx_init();
	// info->win = mlx_new_window(info->mlx, info->width, info->height, "so long");
}

int	main(int ac, char **av)
{
	t_sl	info;
	// t_key	loca;

	(void)ac;
	(void)av;
	// if (ac != 2)
	// 	ft_error("wrong format");
	parse_arg(&info, av[1]);
	// mlx_init(&info);
	// read_map(av[1], &st);
	// image(info.mlx, info.win);
	// mlx_hook(win, 03, 0, &press_key, &loca);
	// mlx_loop(info.mlx);
}
