/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 10:51:35 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/17 15:33:35 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <sys/param.h>

typedef struct s_key{
	char			*key;
	char			*value;
	struct s_key	*next;
	struct s_key	*head;
	struct s_key	*tail;
}				t_key;

# define FALSE 0
# define TRUE 1

#endif