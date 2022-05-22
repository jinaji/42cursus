/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:30:07 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/22 13:11:19 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

t_list	*get_node(t_list **lst, int fd)
{
	t_list	*new;

	// while ((*lst)->next)
	// {
	// 	if ((*lst)->fd == fd)
	// 		return (*lst);
	// 	*lst = (*lst)->next;
	// }
	while (*lst && (*lst)->fd != fd)
		lst = &((*lst)->next);
	// if ((*lst)->next == 0 && (*lst)->fd != fd)
	// {
	// 	new = (t_list *)malloc(sizeof(t_list));
	// 	if (!new)
	// 		return (0);
	// 	new->fd = fd;
	// 	new->next = 0;
	// 	new->str = 0;
	// 	(*lst)->next = new;
	// 	return (new);
	// }
	if (*lst)
		return (*lst);
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->fd = fd;
	new->next = 0;
	new->str = 0;
	*lst = new;
	return (new);
	// return (*lst);
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

void	free_all(t_list **lst, int fd)
{
	t_list	*tmp;

	while (*lst && (*lst)->fd != fd)
		lst = &((*lst)->next);
	if (*lst)
	{
		tmp = (*lst);
		(*lst) = tmp->next;
		free (tmp->str);
		free (tmp);
	}
}

int	make_line(t_list **lst, int fd, char *buff, char **tmp)
{
	int	read_size;

	*lst = get_node(lst, fd);
	while (get_index((*lst)->str) == -1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size == -1 || read_size == 0)
		{
			if (read_size == 0)
			{
				*tmp = get_return(&((*lst)->str));
				free_all (lst, fd);
				return (1);
			}
			free_all (lst, fd);
			return (0);
		}
	buff[read_size] = '\0';
	(*lst)->str = ft_strjoin((*lst)->str, buff);
	}
	return (-1);
}

char	*get_next_line(int fd)
{
	static t_list	*lst;
	char			*tmp;
	char			buff[BUFFER_SIZE + 1];
	int				flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	// if (!(lst))
	// {
	// 	lst = (t_list *)malloc(sizeof(t_list));
	// 	if (!(lst))
	// 		return (0);
	// 	(lst)->next = 0;
	// }
	flag = make_line(&lst, fd, buff, &tmp);
	if (flag == 1)
		return (tmp);
	else if (flag == 0)
		return (0);
	if (get_index(lst->str) != -1)
	{
		tmp = get_return(&(lst->str));
		return (tmp);
	}
	return (0); // return 전에 다 free 들어가야되나 ??? 그럴듯 ... 
}

//leak이 지금 ... 맨 처음 make line 들어가면서 나고 메인에서 호출한 거 한 번 종료될 때 남 ... <- 이건 헤드 프리 안 돼서 그런게 아닐까 ???