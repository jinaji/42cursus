/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:18:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/14 20:22:30 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*q_ft_strdup(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (!tmp)
		ft_error("malloc error", 1);
	while (str[i])
	{
		if (str[i] == '\'')
			i++;
		tmp[j] = str[i];
		j++;
		i++;
	}
	tmp[j] = 0;
	return (tmp);
}

void	free_tmp(char **tmp)
{
	int	i;

	i = 0;
	while (tmp[i])
	{
		free (tmp[i]);
		i++;
	}
	free (tmp);
}

int	ft_strcmp(char *str, char *str2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != str2[i])
			return (0);
		i++;
	}
	if (str2[i])
		return (0);
	return (1);
}

int	**fd_init(int **fd, int cmd_cnt)
{
	int	i;

	i = 0;
	fd = (int **)malloc(sizeof(int *) * (cmd_cnt));
	if (!fd)
		ft_error("malloc error", 1);
	while (cmd_cnt > i)
	{
		fd[i] = (int *)malloc(sizeof(int) * 2);
		if (!fd[i])
			ft_error("malloc error", 1);
		i++;
	}
	return (fd);
}
