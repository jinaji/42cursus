/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:17:19 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/14 20:34:13 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	command_not_found(t_argv *arg)
{
	perror("command not found");
	arg->no_cmd = 0;
}

static int	dp_cnt(char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(str, ' ');
	while (tmp[i])
		i++;
	free_tmp(tmp);
	i += 1;
	return (i);
}

void	get_cmd_path(t_argv *arg)
{
	char	*tmp;
	int		i;
	int		j;

	j = 0;
	while (j < arg->cmd_cnt)
	{
		i = 0;
		arg->no_cmd = 0;
		while (arg->path[i])
		{
			tmp = join_path(arg->path[i], arg->cmd[j][0]);
			if (access(tmp, F_OK) == 0)
			{
				arg->cmd_path[j] = ft_strdup(tmp);
				arg->no_cmd = 1;
			}
			i++;
			free (tmp);
		}
		if (!arg->no_cmd)
			command_not_found(arg);
		j++;
	}
}

static void	split_cmd_op(t_argv *arg, char *cmd, char **tmp, int i)
{
	int	j;

	j = 0;
	if (ft_strcmp(tmp[0], "awk") || ft_strcmp(tmp[0], "sed"))
	{
		arg->cmd[i][0] = ft_strdup(tmp[0]);
		arg->cmd[i][1] = q_ft_strdup(cmd + 4);
		j = 2;
	}
	else
	{
		while (tmp[j])
		{
			arg->cmd[i][j] = ft_strdup(tmp[j]);
			j++;
		}
	}
	arg->cmd[i][j] = 0;
}

void	split_cmd(t_argv *arg, char **av, int ac)
{
	char	**tmp;
	int		h;
	int		i;

	h = 0;
	i = h;
	if (arg->h_flag)
		h = 1;
	while (ac - 3 > h)
	{
		tmp = ft_split(av[h + 2], ' ');
		if (ft_strcmp(tmp[0], "awk") || ft_strcmp(tmp[0], "sed"))
			arg->cmd[i] = (char **)malloc(sizeof(char *) * 3);
		else
			arg->cmd[i] = (char **)malloc(sizeof(char *) * (dp_cnt(av[h + 2])));
		if (!(arg->cmd[i]))
			ft_error("malloc error", 1);
		split_cmd_op(arg, av[h + 2], tmp, i);
		free_tmp(tmp);
		i++;
		h++;
	}
	arg->cmd[i] = 0;
}
