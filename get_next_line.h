/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:29:40 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/20 18:46:29 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif

# include <stdlib.h>

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

size_t	ft_strlen(char *str);
int		get_index(char *str);
char	*ft_strndup(char *buff, int idx);
char	*delete_static(char *buff);
char	*ft_strjoin(char *str, char *buff);

t_list	*get_node(t_list **lst, int fd);
int		make_line(t_list **lst, int fd, char *buff, char **tmp);
char	*get_return(char *str);
char	*get_next_line(int fd);

#endif