/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipexx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:35:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/29 21:02:40 by jinkim2          ###   ########seoul.kr  */
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

typedef struct s_argv{
	char	**path;
	char	*infile;
	char	*outfile;
	char	***cmd;
	int		cmd_cnt;
	int		curr_cmd;
	int		inf_fd;
	int		out_fd;
}				t_argv;

#endif

/*
open, close, read, write,
malloc, free, perror,
strerror, access, dup, dup2,
execve, exit, fork, pipe,
unlink, wait, waitpid
*/