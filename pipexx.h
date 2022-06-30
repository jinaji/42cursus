/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/30 23:49:20 by jinkim2          ###   ########seoul.kr  */
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

typedef struct s_cmd
{
	char	***cmd;
	char	cmd_cnt;
	char	curr_cnt;
}				t_cmd;

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
	int		curr_cnt;
}				t_argv;

#endif

/*
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid
*/