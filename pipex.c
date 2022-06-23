/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:18:02 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/23 22:19:21 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *str)
{
	perror(str);
	exit (1);
}

void	get_path(t_argv **arg, char **envp)
{
	char	**path;
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
	{
		path = ft_split(tmp, ':');
		(*arg)->path = path;
	}
}

void	split_cmd(t_argv **arg, char **av)
{
	char	**tmp;

	if (ft_strchr(av[2], ' '))
	{
		tmp = ft_split(av[2], ' ');
		(*arg)->cmd[0] = ft_strjoin(tmp[0], "/");
		(*arg)->cmd_op[0] = ft_strdup(tmp[1]);
	}
	else
	{
		(*arg)->cmd[0] = ft_strjoin(av[2], "/");
		free ((*arg)->cmd_op[0]);
	}
	if (ft_strchr(av[3], ' '))
	{
		tmp = ft_split(av[3], ' ');
		(*arg)->cmd[1] = ft_strjoin(tmp[1], "/");
		(*arg)->cmd_op[0] = ft_strdup(tmp[2]);
	}
	else
	{
		(*arg)->cmd[1] = ft_strjoin(av[3], "/");
		free ((*arg)->cmd_op[1]);
	}
}

void	arg_init(t_argv **arg, int ac, char **av, char **envp)
{
	*arg = (t_argv *)malloc(sizeof(t_argv));
	if (!arg)
		ft_error ("");
	ft_memset(*arg, 0, sizeof(t_argv));
	(*arg)->cmd = (char **)malloc(sizeof(char *) * (ac - 2));
	if (!(*arg)->cmd)
		ft_error ("");
	(*arg)->cmd_op = (char **)malloc(sizeof(char *) * (ac - 2));
	if (!(*arg)->cmd_op)
		ft_error ("");
	(*arg)->infile = ft_strdup(av[1]);
	(*arg)->outfile = ft_strdup(av[4]);
	split_cmd(arg, av);
	get_path(arg, envp);
	check_valid(arg, envp);
}

void	get_cmd_path(t_argv **arg, char **envp)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*arg)->path[i] && (*arg)->cmd[j])
	{
		tmp = ft_strjoin(tmp, (*arg)->cmd[j]);
		if (access(((*arg)->cmd[j]), F_OK) == 0)
		{
			(*arg)->cmd[j] = tmp;
			j++;
			i = -1;
			free (tmp);
		}
		i++;
		free (tmp);
	}
}

void	check_valid(t_argv **arg, char **envp)
{
	(*arg)->inf_fd = open((*arg)->infile, O_RDWR);
	if ((*arg)->inf_fd == -1)
		ft_error ("no infile");
	(*arg)->out_fd = open((*arg)->outfile, O_CREAT | O_TRUNC | 00700);
	if ((*arg)->out_fd == -1)
		ft_error ("no outfile");
	get_cmd_path(arg, envp);
}

void	first_cmd_exec(t_argv **arg, char **envp, int fd[2])
{
	close(fd[0]);
	execve((*arg)->cmd[0], , envp);
}

void	second_cmd_exec(t_argv **arg, char **envp, int fd[2])
{

}

void	execute_cmd(t_argv **arg, char **envp)
{
	pid_t	pid;
	int		fd[2];

	// only use out | in
	if (pipe(fd) == -1)
		ft_error ("pipe error");
	pid = fork();
	if (pid == 0)
	{
		second_cmd_exec(arg, envp, fd);
	}
	else
	{
		pid = fork();
		if (pid == 0)
			first_cmd_exec(arg, envp, fd);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_argv	*arg;

	if (ac != 5)
		ft_error("wrong format");
	arg_init(&arg, ac, av, envp);
	execute_cmd(arg, envp);
}
