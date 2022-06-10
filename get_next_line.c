/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:30:07 by jinkim2           #+#    #+#             */
/*   Updated: 2022/06/10 17:00:32 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "push_swap_bonus.h"

t_node_	*get_node(t_node_ **lst, int fd)
{
	t_node_	*new;

	while (*lst && (*lst)->fd != fd)
		lst = &((*lst)->next);
	if (*lst)
		return (*lst);
	new = (t_node_ *)malloc(sizeof(t_node_));
	if (!new)
		return (0);
	new->fd = fd;
	new->next = 0;
	new->str = 0;
	*lst = new;
	return (new);
}

char	*get_return(char **str)
{
	char	*tmp;
	int		idx;

	if (!*str)
		return (0);
	idx = get_index(*str);
	if (idx == -1)
		tmp = ft_strndup(*str, ft_strlen(*str));
	else
		tmp = ft_strndup(*str, idx);
	*str = delete_static(*str);
	if (*tmp == 0)
	{
		free (tmp);
		return (0);
	}
	return (tmp);
}

void	free_all(t_node_ **lst, int fd)
{
	t_node_	*tmp;

	while (*lst && (*lst)->fd != fd)
		lst = &((*lst)->next);
	if (*lst)
	{
		tmp = (*lst);
		(*lst) = (*lst)->next;
		free (tmp->str);
		free (tmp);
	}
}

int	make_line(t_node_ **lst, int fd, char *buff, char **tmp)
{
	int		read_size;
	t_node_	*curr;

	curr = get_node(lst, fd);
	while (get_index(curr->str) == -1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1 || read_size == 0)
		{
			if (read_size == 0)
			{
				*tmp = get_return(&(curr->str));
				free_all (lst, fd);
				return (1);
			}
			free_all (lst, fd);
			return (0);
		}
	buff[read_size] = '\0';
	curr->str = gnl_strjoin(curr->str, buff);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static t_node_	*lst;
	t_node_			*curr;
	char			*tmp;
	char			buff[BUFFER_SIZE + 1];
	int				flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	flag = make_line(&lst, fd, buff, &tmp);
	if (flag == 1)
		return (tmp);
	else if (flag == 0)
		return (0);
	curr = lst;
	if (get_index(get_node(&curr, fd)->str) != -1)
	{
		tmp = get_return(&(get_node(&curr, fd)->str));
		return (tmp);
	}
	return (0);
}
