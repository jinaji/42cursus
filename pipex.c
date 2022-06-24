/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 14:18:02 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/25 02:55:55 by jinkim2          ###   ########seoul.kr  */
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
		(*arg)->path = ft_split(tmp, ':');
	free (tmp);
}

void	split_cmd(t_argv **arg, char **av, int ac)
{
	char	**tmp;
	int		i;

	i = 0;

	while (ac - 3 > i)
	{
		tmp = ft_split(av[i + 2], ' ');
		(*arg)->cmd[i] = (char **)malloc(sizeof(char *) * (ac - 3) + 1);
		if (tmp[1])
		{
			(*arg)->cmd[i][0] = ft_strdup(tmp[0]);
			(*arg)->cmd[i][1] = ft_strdup(tmp[1]);
		}
		else
			(*arg)->cmd[i][0] = ft_strdup(av[i + 2]);
		i++;
	}
	free (tmp[0]);
	free (tmp[1]);
	free (tmp);
}

void	get_cmd_path(t_argv **arg)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*arg)->path[i] && j < (*arg)->cmd_cnt)
	{
		tmp = ft_strjoin((*arg)->path[i], "/");
		tmp = ft_strjoin(tmp, (*arg)->cmd[j][0]);
		if (access(tmp, F_OK) == 0)
		{
			(*arg)->cmd[j][0] = ft_strdup(tmp);
			j++;
			i = -1;
		}
		i++;
	}
	free (tmp);
}

void	check_valid(t_argv **arg, char **envp)
{
	(*arg)->inf_fd = open((*arg)->infile, O_RDWR);
	if ((*arg)->inf_fd == -1)
		ft_error ("infile open error");
	(*arg)->out_fd = open((*arg)->outfile, O_RDWR | O_CREAT | O_TRUNC, 00700);
	if ((*arg)->out_fd == -1)
		ft_error ("outfile open error");
	get_cmd_path(arg);
	(void)envp;
}

void	arg_init(t_argv **arg, int ac, char **av, char **envp)
{
	*arg = (t_argv *)malloc(sizeof(t_argv));
	if (!arg)
		ft_error ("err");
	ft_memset(*arg, 0, sizeof(t_argv));
	(*arg)->cmd_cnt = ac - 3;
	(*arg)->cmd = (char ***)malloc(sizeof(char **) * ((*arg)->cmd_cnt) + 1);
	if (!(*arg)->cmd)
		ft_error ("malloc err");
	(*arg)->infile = ft_strdup(av[1]);
	(*arg)->outfile = ft_strdup(av[4]);
	split_cmd(arg, av, ac);
	get_path(arg, envp);
	check_valid(arg, envp);
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
	len = len - last;
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		ft_error ("malloc error");
	last += 1;
	while (cmd[last])
		tmp[i++] = cmd[last++];
	return (tmp);
}

void	first_cmd_exec(t_argv **arg, char **envp, int fd[2])
{
	char	*path;
// only write
	path = (*arg)->cmd[0][0];
	if (ft_strchr((*arg)->cmd[0][0], '/'))
		(*arg)->cmd[0][0] = get_cmd((*arg)->cmd[0][0]);
	close(fd[0]);
	dup2((*arg)->inf_fd, STDIN_FILENO); // ???
	dup2(fd[1], STDOUT_FILENO); // 이거 지우니까 inf 출력되고 cmd2 넘어가서 거기거 기록됨
	close(fd[1]);
	execve(path, (*arg)->cmd[0], envp);
	// 이거 출력되면 안되는 것 같은데 출력됨 !!! 헐 고쳤다
}

/*
./pipex infile "wc -l" ls outfile 
wc: stdin: read: Bad file descriptor
ㅇㅂㅇ??
*/

/*	아기1 입력 infile fd 
아기2 출력 outfile fd	??
0 read 1 write			*/

void	second_cmd_exec(t_argv **arg, char **envp, int fd[2])
{
	char	*path;
// only read
	path = (*arg)->cmd[1][0];
	if (ft_strchr((*arg)->cmd[1][0], '/'))
		(*arg)->cmd[1][0] = get_cmd((*arg)->cmd[1][0]);
	close(fd[1]);
	dup2((*arg)->out_fd, STDOUT_FILENO); // ??
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	execve(path, (*arg)->cmd[1], envp);
}

void	execute_cmd(t_argv **arg, char **av, char **envp)
{
	pid_t	pid;
	int		ret;
	int		fd[2];

	// only use out | in
	if (pipe(fd) == -1)
		ft_error ("pipe error");
	pid = fork();
	if (pid == 0)
	{
		first_cmd_exec(arg, envp, fd);
	}
	else
	{
		waitpid(pid, &ret, 0);
		second_cmd_exec(arg, envp, fd);
	}
	(void)av;
}

int	main(int ac, char **av, char **envp)
{
	t_argv	*arg;

	if (ac != 5)
		ft_error("wrong format");
	arg_init(&arg, ac, av, envp);
	execute_cmd(&arg, av, envp);
}
