/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:29:40 by jinkim2           #+#    #+#             */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
/*   Updated: 2022/05/22 21:46:01 by jinkim2          ###   ########seoul.kr  */
=======
/*   Updated: 2022/05/22 21:38:31 by jinkim2          ###   ########seoul.kr  */
>>>>>>> 517b373 (done)
=======
/*   Updated: 2022/05/23 13:55:04 by jinkim2          ###   ########seoul.kr  */
>>>>>>> 929b455 (realdone)
=======
/*   Updated: 2022/05/23 00:09:10 by jinkim2          ###   ########seoul.kr  */
>>>>>>> 0ac63f4 (donedonedone)
=======
/*   Updated: 2022/05/24 17:18:30 by jinkim2          ###   ########seoul.kr  */
>>>>>>> 0e8a025 (TTT)
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	int				fd;
	char			*str;
	struct s_list	*next;
}	t_list;

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