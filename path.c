/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:19:08 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/14 20:30:34 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(t_argv *arg, char **envp)
{
	char	*tmp;
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			tmp = ft_strdup(envp[i] + 5);
		i++;
	}
	if (tmp)
		arg->path = ft_split(tmp, ':');
	free (tmp);
}

char	*join_path(char *path, char *cmd)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(path, "/");
	tmp2 = ft_strjoin(tmp, cmd);
	free (tmp);
	return (tmp2);
}
