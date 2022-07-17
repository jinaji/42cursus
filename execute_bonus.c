/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 20:40:47 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/17 23:26:06 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	first_cmd_exec(t_argv *arg, int **fd, int i)
{
	if (arg->h_flag)
		make_tmp_file(arg);
	else
		arg->inf_fd = open(arg->infile, O_RDONLY);
	if (arg->inf_fd < 0)
		ft_error("infile open error", 1);
	close(fd[i][READ]);
	dup2(arg->inf_fd, STDIN_FILENO);
	dup2(fd[i][WRITE], STDOUT_FILENO);
	close(fd[i][WRITE]);
	execve(arg->cmd_path[i], arg->cmd[i], arg->envp);
}

static void	middle_cmd_exec(t_argv *arg, int **fd, int i)
{
	int	j;

	j = i - 1;
	close(fd[j][WRITE]);
	dup2(fd[j][READ], STDIN_FILENO);
	close(fd[j][READ]);
	dup2(fd[i][WRITE], STDOUT_FILENO);
	close(fd[i][WRITE]);
	close(fd[i][READ]);
	execve(arg->cmd_path[i], arg->cmd[i], arg->envp);
}

static void	last_cmd_exec(t_argv *arg, int **fd, int i)
{
	int	j;

	j = i - 1;
	if (arg->h_flag)
		arg->out_fd = open(arg->outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		arg->out_fd = open(arg->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->out_fd < 0)
		ft_error("outfile open error", 1);
	close(fd[j][WRITE]);
	dup2(fd[j][READ], STDIN_FILENO);
	close(fd[j][READ]);
	dup2 (arg->out_fd, STDOUT_FILENO);
	execve(arg->cmd_path[i], arg->cmd[i], arg->envp);
}

static void	execute_cmds(t_argv *arg, int **fd, int i, pid_t pid)
{
	if (pid == 0)
	{
		if (i == 0)
			first_cmd_exec(arg, fd, i);
		if (arg->cmd_cnt - 1 > i)
			middle_cmd_exec(arg, fd, i);
		else
			last_cmd_exec(arg, fd, i);
	}
}

int	execute_cmd(t_argv *arg)
{
	pid_t	pid;	
	int		status;
	int		**fd;
	int		i;

	i = 0;
	fd = 0;
	fd = fd_init(fd, arg->cmd_cnt);
	while (arg->cmd_cnt > i)
	{
		if (pipe(fd[i]) == -1)
			ft_error("pipe error", 1);
		pid = fork();
		if (pid == 0)
			break ;
		close(fd[i][WRITE]);
		i++;
	}
	waitpid(pid, &status, 0);
	execute_cmds(arg, fd, i, pid);
	close_fd(fd, &i);
	while (i++ < arg->cmd_cnt - 1)
		wait(&status);
	unlink_tmp(arg->h_flag);
	return (status >> 8 & 0x000000ff);
}
