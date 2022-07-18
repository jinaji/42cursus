/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:29 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/18 21:17:04 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str, int i)
{
	perror(str);
	if (i)
		exit (1);
}

static void	arg_init(t_argv *arg, int ac, char **av, char **envp)
{
	ft_memset(arg, 0, sizeof(t_argv));
	arg->cmd_cnt = ac - 3;
	arg->cmd = (char ***)malloc(sizeof(char **) * (ac - 2));
	if (!(arg->cmd))
		ft_error("malloc error", 1);
	arg->cmd_path = (char **)malloc(sizeof(char *) * (ac - 2));
	arg->infile = ft_strdup(av[1]);
	arg->outfile = ft_strdup(av[ac - 1]);
	arg->envp = envp;
	split_cmd(arg, av, ac);
	get_path(arg, envp);
	get_cmd_path(arg);
}

int	main(int ac, char **av, char **envp)
{
	t_argv	arg;

	if (ac != 5)
		ft_error("wrong format", 1);
	arg_init(&arg, ac, av, envp);
	return (execute_cmd(&arg));
}
