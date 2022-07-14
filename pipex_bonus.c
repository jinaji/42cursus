/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:21:32 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/14 20:49:41 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_error(char *str, int i)
{
	perror(str);
	if (i)
		exit (1);
}

void	arg_init(t_argv *arg, int ac, char **av, char **envp)
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
	if (ft_strcmp(arg->infile, "here_doc"))
	{
		arg->h_flag = 1;
		arg->limiter = ft_strjoin(av[2], "\n");
		arg->cmd_cnt -= 1;
	}
	split_cmd(arg, av, ac);
	get_path(arg, envp);
	get_cmd_path(arg);
}

void	make_tmp_file(t_argv *arg)
{
	int		fd;
	char	*tmp;

	fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	tmp = get_next_line(0);
	while (!ft_strcmp(tmp, arg->limiter))
	{
		write (fd, tmp, ft_strlen(tmp));
		tmp = get_next_line(0);
	}
	close (fd);
	arg->inf_fd = open (".tmp", O_RDONLY);
	if (arg->inf_fd == -1)
		ft_error ("tmp open error", 1);
}

int	main(int ac, char **av, char **envp)
{
	t_argv	arg;

	if (ac < 5)
		ft_error("wrong format", 1);
	arg_init(&arg, ac, av, envp);
	if (arg.h_flag && ac < 6)
		ft_error("wrong format", 1);
	return (execute_cmd(&arg));
}
