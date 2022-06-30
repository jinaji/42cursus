/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:29 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/01 01:49:33 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipexx.h"

void	ft_error(char *str)
{
	perror(str);
	exit (1);
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

int	dp_cnt(char *str)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split(str, ' ');
	while (tmp[i])
		i++;
	free_tmp(tmp);
	return (i);
}

void	split_cmd(t_argv *arg, char **av, int ac)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (ac - 3 > i)
	{
		j = 1;
		tmp = ft_split(av[i + 2], ' ');
		arg->cmd[i] = (char **)malloc(sizeof(char *) * (dp_cnt(av[i + 2]) + 1));
		if (!(arg->cmd[i]))
			ft_error("malloc error");
		if (tmp[0])
			arg->cmd[i][0] = ft_strdup(tmp[0]);
		while (tmp[j])
		{
			arg->cmd[i][j] = ft_strdup(tmp[j]);
			j++;
		}
		arg->cmd[i][j] = 0;
		free_tmp(tmp);
		i++;
	}
}

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

void	get_cmd_path(t_argv *arg)
{
	char	*tmp;
	int		i;
	int		j;
	int		err_check;

	i = 0;
	j = 0;
	err_check = 0;
	while (arg->path[err_check])
		err_check++;
	while (arg->path[i] && j < arg->cmd_cnt)
	{
		tmp = ft_strjoin(arg->path[i], "/");
		tmp = ft_strjoin(tmp, arg->cmd[j][0]);
		if (access(tmp, F_OK) == 0)
		{
			arg->cmd_path[j] = ft_strdup(tmp);
			j++;
			i = -1;
		}
		i++;
	}
	if (i == err_check + 1)
		ft_error ("command not found");
	free (tmp);
}

void	check_valid(t_argv *arg)
{
	arg->inf_fd = open(arg->infile, O_RDONLY);
	if (arg->inf_fd == -1)
		ft_error("infile open error");
	arg->out_fd = open(arg->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->out_fd == -1)
		ft_error("outfile open error");
	get_cmd_path(arg);
}

void	arg_init(t_argv *arg, int ac, char **av, char **envp)
{
	ft_memset(arg, 0, sizeof(t_argv));
	arg->cmd_cnt = ac - 3;
	arg->cmd = (char ***)malloc(sizeof(char **) * (ac - 2));
	if (!(arg->cmd))
		ft_error("malloc error");
	arg->cmd_path = (char **)malloc(sizeof(char *) * (ac - 2));
	arg->infile = ft_strdup(av[1]);
	arg->outfile = ft_strdup(av[ac - 1]);
	arg->envp = envp;
	split_cmd(arg, av, ac);
	get_path(arg, envp);
	check_valid(arg);
}

void	first_cmd_exec(t_argv *arg, int fd[2])
{
	printf("first\n");
	close(fd[READ]);
	dup2(arg->inf_fd, STDIN_FILENO);
	dup2(fd[WRITE], STDOUT_FILENO);
	close(fd[WRITE]);
	execve(arg->cmd_path[0], arg->cmd[0], arg->envp);
}

void	middle_cmd_exec(t_argv *arg, int fd[2], int fd2[2], int i)
{
	printf("middle %d\n", i);
	// printf("%s\n", arg->cmd_path[i]);
	// for (int k = 0; arg->cmd[i][k]; k++)
	// 	printf("%s\n", arg->cmd[i][k]);
	if (i % 2) // a read b write
	{
		close(fd[WRITE]);
		close(fd2[READ]);
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
		dup2(fd2[WRITE], STDOUT_FILENO);
		close(fd2[WRITE]);
	}
	else
	{
		close(fd[READ]);
		close(fd2[WRITE]);
		dup2(fd2[READ], STDIN_FILENO);
		close(fd2[READ]);
		dup2(fd[WRITE], STDOUT_FILENO);
		close(fd[WRITE]);
	}
	execve(arg->cmd_path[i], arg->cmd[i], arg->envp);
}

void	last_cmd_exec(t_argv *arg, int fd[2], int fd2[2], int i)
{
	printf ("last %d \n", i);
	if (arg->cmd_cnt != i + 1)
		ft_error ("command count error");
	if (i % 2)
	{
		close(fd[WRITE]);
		close(fd2[READ]);
		close(fd2[WRITE]);
		dup2(arg->out_fd, STDOUT_FILENO);
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
	}
	else
	{
		close(fd[READ]);
		close(fd[WRITE]);
		close(fd2[WRITE]);
		dup2(arg->out_fd, STDOUT_FILENO);
		dup2(fd[READ], STDIN_FILENO);
		close(fd[READ]);
	}
	execve(arg->cmd_path[i], arg->cmd[i], arg->envp);
}

void	execute_cmd(t_argv *arg)
{
	pid_t	pid;	
	int		status;
	int		fd[2];
	int		fd2[2];
	int		i;

	i = 1;
	if (pipe(fd) == -1 || pipe(fd2) == -1)
		ft_error ("pipe error");
	pid = fork();
	if (pid == 0)
		first_cmd_exec(arg, fd);
	else
	{
		waitpid(pid, &status, 0);
		while (arg->cmd_cnt - 1 > i)
		{
			pid = fork();
			if (pid == 0)
				middle_cmd_exec(arg, fd, fd2, i);
			else
			{
				waitpid(pid, &status, 0);
				i++;
			}
		}
		last_cmd_exec(arg, fd, fd2, i);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_argv	arg;

	if (ac < 5)
		ft_error("wrong format");
	arg_init(&arg, ac, av, envp);
	execute_cmd(&arg);
}
