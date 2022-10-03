#include "../cub3D.h"

static char	**dup_util(int len, char **argv, char **ret)
{
	int		fd;
	int		i;
	char	*line;

	ret = malloc(sizeof(char *) * (len + 1));
	fd = open(argv[1], O_RDONLY);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		ret[i++] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
	}
	ret[i] = NULL;
	close(fd);
	return (ret);
}

char	**dup_start(char **argv, char **ret)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(argv[1], O_RDONLY);
	i = 0;
    line = NULL;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
	return (dup_util(i, argv, ret));
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	error(char *msg, char *free_ptr)
{
	if (free_ptr)
		free(free_ptr);
	write(STDERR_FILENO, "Error\n", 6);
	write(STDERR_FILENO, "\t: ", 4);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, "\n", 1);
	return (FALSE_E);
}

char	**dup_map(char **array, int height)
{
	char	**tmp;
	int		z;

	tmp = malloc(sizeof(char *) * (height + 1));
	if (!tmp)
		return (NULL);
	z = 0;
	while (z < height)
	{
		tmp[z] = ft_strdup(array[z]);
		z++;
	}
	tmp[z] = NULL;
	return (tmp);
}
