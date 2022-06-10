/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 16:28:12 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/10 16:37:35 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>

typedef struct s_list{
	int				fd;
	char			*str;
	struct s_list	*next;
}				t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlen(char *str);
int		get_index(char *str);
char	*ft_strndup(char *buff, int idx);
char	*delete_static(char *str);
char	*ft_strjoin(char *str, char *buff);

t_list	*get_node(t_list **lst, int fd);
char	*get_return(char **str);
void	free_all(t_list **lst, int fd);
int		make_line(t_list **lst, int fd, char *buff, char **tmp);
char	*get_next_line(int fd);

#endif