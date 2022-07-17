/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/17 21:53:34 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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

typedef struct s_node_{
	char			*str;
	int				fd;
	struct s_node_	*next;
}				t_node_;

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

void	make_tmp_file(t_argv *arg);
void	unlink_tmp(int h_flag);

int		get_index(char *str);
char	*ft_strndup(char *buff, int idx);
char	*delete_static(char *str);
char	*gnl_strjoin(char *str, char *buff);

t_node_	*get_node(t_node_ **lst, int fd);
char	*get_return(char **str);
void	free_all(t_node_ **lst, int fd);
int		make_line(t_node_ **lst, int fd, char *buff, char **tmp);
char	*get_next_line(int fd);

#endif