/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:29:40 by jinkim2           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/22 21:45:49 by jinkim2          ###   ########seoul.kr  */
=======
/*   Updated: 2022/05/22 21:36:03 by jinkim2          ###   ########seoul.kr  */
>>>>>>> f7010aa (done)
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
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
char	*get_return(char **str);
void	free_all(t_list **lst, int fd);
int		make_line(t_list **lst, int fd, char *buff, char **tmp);
char	*get_next_line(int fd);

#endif