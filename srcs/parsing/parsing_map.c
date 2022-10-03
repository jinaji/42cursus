#include "../cub3D.h"

static int	fill_array(char **file, t_map *parsing, int mapbeg)
{
	int	j;

	j = 0;
	parsing->width = get_max_len(file, mapbeg);
	if (parser_space(parsing))
		return (-1);
	while (file && file[mapbeg])
	{
		replace_space(j, parsing, file[mapbeg]);
		mapbeg++;
		j++;
	}
	replace_void(parsing);
	return (0);
}

int	check_open_wall(char **array, int y, int x)
{
	if (y < 0 || x < 0 || !array[y] || (array[y] && !array[y][x]))
		return (1);
	else if (array[y][x] == '1')
		return (0);
	array[y][x] = '1';
	return (check_open_wall(array, y - 1, x)
		+ check_open_wall(array, y + 1, x)
		+ check_open_wall(array, y, x - 1)
		+ check_open_wall(array, y, x + 1));
}

static int	get_player(t_i_vec *player, char **array)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == 'N' || array[i][j] == 'S'
				|| array[i][j] == 'W' || array[i][j] == 'E')
			{
				player->x = j;
				player->y = i;
				count++;
			}
			j++;
		}
		i++;
	}
	if (count != 1)
		return (-1);
	return (0);
}

int	open_wall(char **dup)
{
	int	i;
	int	j;

	i = 0;
	while (dup[i])
	{
		j = 0;
		while (dup[i][j])
		{
			if (dup[i][j] == '0' && check_open_wall(dup, i, j))
			{
				free_split(dup);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free_split(dup);
	return (0);
}

t_bool	valid_map(t_map *parsing, char **file)
{
	t_i_vec	player;
	char	**dup;
	int		mapbeg;

	mapbeg = 0;
	parsing->height = get_height(&mapbeg, file);
	if (valid_char(file, mapbeg))
	{
		return (error("valid char", NULL));
	}
	if (fill_array(file, parsing, mapbeg))
		return (FALSE_E);
	dup = dup_map(parsing->array, parsing->height);
	if (!dup)
		return (FALSE_E);
	if (get_player(&player, dup))
	{
		free_split(dup);
		return (error("get player", NULL));
	}
	if (open_wall(dup))
		return (error("open wall", NULL));
	return (TRUE_E);
}
