/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:29 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/13 16:14:27 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "pipexx.h"

void	ft_error(char *str, int i)
{
	perror(str);
	if (i)
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

int	dp_cnt(char *str)
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

void	split_cmd_op(t_argv *arg, char *cmd, char **tmp, int i)
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
	tmp2= ft_strjoin(tmp, cmd);
	free (tmp);
	return (tmp2);
}

void	command_not_found(t_argv *arg)
{
	perror("command not found");
	arg->no_cmd = 0;
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
	char	*tmp;

	arg->inf_fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	tmp = get_next_line(0);
	while (!ft_strcmp(tmp, arg->limiter))
	{
		write (arg->inf_fd, tmp, ft_strlen(tmp));
		tmp = get_next_line(0);
	}
	close (arg->inf_fd);
	arg->inf_fd = open (".tmp", O_RDONLY);
	if (arg->inf_fd == -1)
		ft_error ("tmp open error", 1);
	dup2(arg->inf_fd, STDIN_FILENO);
	close (arg->inf_fd);
}

void	first_cmd_exec(t_argv *arg, int **fd, int i)
{
	if (arg->h_flag)
		make_tmp_file(arg);
	else
		arg->inf_fd = open(arg->infile, O_RDONLY);
	if (arg->inf_fd < 0)
		ft_error("infile open error", 0);
	close(fd[i][READ]);
	dup2(arg->inf_fd, STDIN_FILENO);
	dup2(fd[i][WRITE], STDOUT_FILENO);
	close(fd[i][WRITE]);
	execve(arg->cmd_path[i], arg->cmd[i], arg->envp);
}

void	middle_cmd_exec(t_argv *arg, int **fd, int i)
{
	int	j;

	j = i - 1;
	close(fd[j][WRITE]);
	dup2(fd[j][READ], STDIN_FILENO);
	close(fd[j][READ]);
	dup2(fd[i][WRITE], STDOUT_FILENO);
	close(fd[i][WRITE]);
	execve(arg->cmd_path[i], arg->cmd[i], arg->envp);
}

void	last_cmd_exec(t_argv *arg, int **fd, int i)
{
	// printf ("%d %s last\n", i, arg->cmd[i][0]);
	// if (i % 2)
	// {
	// 	// close(fd2[READ]);
	// 	dup2(fd[READ], STDIN_FILENO);
	// 	close(fd[READ]);
	// }
	// else
	// {
	// 	close(fd[READ]);
	// 	// dup2(fd2[READ], STDIN_FILENO);
	// 	// close(fd2[READ]);
	// }
	int	j;

	j = i - 1;
	if (arg->h_flag)
		arg->out_fd = open(arg->outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		arg->out_fd = open(arg->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arg->out_fd < 0)
		ft_error("outfile open error", 0);
	close(fd[j][WRITE]);
	dup2(fd[j][READ], STDIN_FILENO);
	close(fd[j][READ]);
	dup2 (arg->out_fd, STDOUT_FILENO);
	// if (arg->h_flag)
	// 	unlink(".tmp");
	execve(arg->cmd_path[i], arg->cmd[i], arg->envp);
}

void	execute_cmds(t_argv *arg, int **fd, int i)
{
	if (i == 0)
		first_cmd_exec(arg, fd, i);
	if (arg->cmd_cnt - 1 > i)
		middle_cmd_exec(arg, fd, i);
	else
		last_cmd_exec(arg, fd, i);
}

int	**fd_init(int **fd, int cmd_cnt)
{
	int	i;

	i = 0;
	fd = (int **)malloc(sizeof(int *) * (cmd_cnt - 1));
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

void	execute_cmd(t_argv *arg)
{
	pid_t	pid;	
	int		status;
	int		**fd;
	int		i;

	i = 0;
	fd = 0;
	fd = fd_init(fd, arg->cmd_cnt);
	// fd = (int **)malloc(sizeof(int *) * arg->cmd_cnt - 1);
	// while (arg->cmd_cnt > i)
	// {
	// 	fd[i] = (int *)malloc(sizeof(int) * 2);
	// 	i++;
	// }
	// i = 0;
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
	execute_cmds(arg, fd, i);
	waitpid(pid, &status, 0);
	i = 0;
	if (arg->h_flag)
		unlink(".tmp");
	while (i++ < arg->cmd_cnt)
		waitpid(0, &status, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_argv	arg;

	if (ac < 5)
		ft_error("wrong format", 1);
	arg_init(&arg, ac, av, envp);
	if (arg.h_flag && ac < 6)
		ft_error("wrong format", 1);
	execute_cmd(&arg);
}
