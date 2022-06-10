/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:28:12 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/10 17:00:07 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node_{
	int				fd;
	char			*str;
	struct s_node_	*next;
}				t_node_;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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