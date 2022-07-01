/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/01 21:37:37 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEXX_H
# define PIPEXX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"

# define READ 0
# define WRITE 1
# define BUFFER_SIZE 4096

typedef struct s_node_{
	int					fd;
	char				*str;
	struct s_node_		*next;
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
}				t_argv;


t_node_	*get_node(t_node_ **lst, int fd);
char	*get_return(char **str);
void	free_all(t_node_ **lst, int fd);
int		make_line(t_node_ **lst, int fd, char *buff, char **tmp);
char	*get_next_line(int fd);

int		get_index(char *str);
char	*ft_strndup(char *buff, int idx);
char	*delete_static(char *str);
char	*gnl_strjoin(char *str, char *buff);

#endif

/*
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid
*/