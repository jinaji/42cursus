/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/17 22:21:51 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <string.h>
# include <errno.h>

# define READ 0
# define WRITE 1
# define BUFFER_SIZE 4096

typedef struct s_argv{
	char	**path;
	char	*infile;
	char	*outfile;
	char	**envp;
	int		inf_fd;
	int		out_fd;
	char	***cmd;
	char	**cmd_path;
	int		cmd_cnt;
	int		h_flag;
	char	*limiter;
	int		no_cmd;
}				t_argv;

void	get_cmd_path(t_argv *arg);
void	split_cmd(t_argv *arg, char **av, int ac);

int		execute_cmd(t_argv *arg);

void	get_path(t_argv *arg, char **envp);
char	*join_path(char *path, char *cmd);

void	ft_error(char *str, int i);

char	*q_ft_strdup(char *str);
void	free_tmp(char **tmp);
int		ft_strcmp(char *str, char *str2);
int		**fd_init(int **fd, int cmd_cnt);
void	close_fd(int **fd, int *i);

#endif