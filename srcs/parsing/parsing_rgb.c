/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:31:28 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 18:05:59 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static t_bool	valid_digit(char **split)
{
	int		j;
	int		i;

	i = 0;
	while (split[i])
	{
		if (ft_atoi(split[i]) < 0 || ft_atoi(split[i]) > 255)
			return (FALSE_E);
		j = 0;
		while (split[i][j])
		{
			if (!ft_isdigit(split[i][j]) && !ft_isspace(split[i][j]))
				return (FALSE_E);
			j++;
		}
		i++;
	}
	if (i != 3)
		return (FALSE_E);
	return (TRUE_E);
}

static t_bool	valid_rgb(int *count, char *line, t_map *data, char *str)
{
	char	**split;
	char	*trim;
	int		i;

	i = 0;
	trim = ft_strtrim(line, str);
	split = ft_split(trim, ',');
	free(trim);
	if (valid_digit(split) == FALSE_E)
	{
		free_split(split);
		return (FALSE_E);
	}
	while (split[i])
	{
		if (str[0] == 'F')
			data->floor[i] = ft_atoi(split[i]);
		else
			data->ceil[i] = ft_atoi(split[i]);
		i++;
	}
	(*count)++;
	free_split(split);
	return (TRUE_E);
}

t_bool	valid_floor(t_map *data, char **file)
{
	char	*trim;
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (file && file[i])
	{
		trim = ft_strtrim(file[i], " \t");
		if (!ft_strncmp(trim, "F ", 2))
		{
			if (valid_rgb(&count, trim, data, "F \t") == FALSE_E)
				return (error("RGB format", trim));
		}
		if (!ft_strncmp(trim, "C ", 2))
		{
			if (valid_rgb(&count, trim, data, "C \t") == FALSE_E)
				return (error("RGB format", trim));
		}
		free(trim);
		i++;
	}
	if (count != 2)
		return (error("number color", NULL));
	return (TRUE_E);
}
