/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:29 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/29 21:22:20 by jinkim2          ###   ########seoul.kr  */
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

void	split_cmd(t_argv *arg, char **av, int ac)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	while (ac - 3 > i)
	{
		j = 0;
		tmp = ft_split(av[i + 2], ' ');
		arg->cmd[i] = (char **)malloc(sizeof(char *) * (ac - 2));
		if (!(arg->cmd[i]))
			ft_error("malloc error");
		if (tmp[i])
			arg->cmd[i][0] = ft_strdup(tmp[i]);
		while (tmp[j + 1])
		{
			arg->cmd[i][j + 1] = ft_strdup(tmp[j + 1]);
			j++;
		}
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
			arg->cmd[j][0] = ft_strdup(tmp);
			j++;
			i = -1;
		}
		if (i + 1 == err_check)
			ft_error ("anjdla");
		i++;
	}
	free (tmp);
}

void	check_valid(t_argv *arg)
{
	arg->inf_fd = open(arg->infile, O_RDONLY);
	if (arg->inf_fd == -1)
		ft_error("infile open error");
	arg->out_fd = open(arg->outfile, O_RDWR | O_CREAT | O_TRUNC, 00700);
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
	arg->infile = ft_strdup(av[1]);
	arg->outfile = ft_strdup(av[ac - 1]);
	split_cmd(arg, av, ac);
	get_path(arg, envp);
	check_valid(arg);
}

char	*get_cmd(char *cmd)
{
	char	*tmp;
	int		last;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(cmd);
	last = len - 1;
	while (cmd[last] != '/')
		last--;
	len -= last;
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		ft_error("malloc error");
	last += 1;
	while (cmd[last])
		tmp[i++] = cmd[last++];
	return (tmp);
}

void	first_cmd_exec(t_argv *arg, char **envp, int fd[2])
{
	char	*path;

	path = ft_strdup(arg->cmd[0][0]);
	if (ft_strchr((arg->cmd[0][0]), '/'))
		arg->cmd[0][0] = get_cmd(arg->cmd[0][0]);
	close(fd[0]);
	dup2(arg->inf_fd, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	arg->curr_cmd += 1;
	execve(path, arg->cmd[0], envp);
}

void	middle_cmd_exec(t_argv *arg, char **envp, int fd[2])
{
	char	*path;
	int		i;

	i = arg->curr_cmd;
	path = ft_strdup(arg->cmd[i][0]);
	if (ft_strchr(arg->cmd[i][0], '/'))
		arg->cmd[i][0] = get_cmd(arg->cmd[i][0]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	arg->curr_cmd += 1;
	execve(path, arg->cmd[i], envp);
}

void	last_cmd_exec(t_argv *arg, char **envp, int fd[2])
{
	char	*path;
	int		i;

	if (arg->cmd_cnt != arg->curr_cmd)
		ft_error ("command count error");
	i = arg->curr_cmd;
	path = ft_strdup(arg->cmd[i][0]);
	if (ft_strchr(arg->cmd[i][0], '/'))
		arg->cmd[i][0] = get_cmd(arg->cmd[i][0]);
	close(fd[1]);
	dup2(arg->out_fd, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	execve(path, arg->cmd[i], envp);
}

void	execute_cmd(t_argv *arg, char **envp)
{
	pid_t	pid;
	int		ret;
	int		fd[2];

	if (pipe(fd) == -1)
		ft_error ("pipe error");
	pid = fork();
	if (pid == 0)
		first_cmd_exec(arg, envp, fd);
	else
	{
		waitpid(pid, &ret, 0);
		while (arg->cmd_cnt > 1)
		{
			pid = fork();
			if (pid == 0)
				middle_cmd_exec(arg, envp, fd);
			arg->cmd_cnt--;
		}
		last_cmd_exec(arg, envp, fd);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_argv	arg;

	if (ac < 5)
		ft_error("wrong format");
	arg_init(&arg, ac, av, envp);
	execute_cmd(&arg, envp);
}
