/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:55:05 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/05 12:56:31 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

typedef struct s_arg{
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
}			t_arg;

#endif