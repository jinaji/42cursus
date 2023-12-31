/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 12:30:14 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/23 18:36:07 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	get_index(char	*str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (++i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *buff, int idx)
{
	int		i;
	char	*new;

	i = 0;
	if (!buff)
		return (0);
	new = (char *)malloc(sizeof(char) * idx + 1);
	if (!new)
		return (0);
	while (idx > i)
	{
		new[i] = buff[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*delete_static(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	if (!str)
		return (0);
	if (get_index(str) == -1)
		return (str);
	i = get_index(str) - 1;
	j = 0;
	len = ft_strlen(str) - i;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	i += 1;
	while (str[i])
		new[j++] = str[i++];
	new[j] = '\0';
	free (str);
	return (new);
}

char	*gnl_strjoin(char *str, char *buff)
{
	int		i;
	int		j;
	int		len;
	char	*new;

	if (!str)
		return (ft_strndup(buff, ft_strlen(buff)));
	len = ft_strlen(str) + ft_strlen(buff);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	j = 0;
	while (buff[j])
		new[i++] = buff[j++];
	new[i] = '\0';
	free (str);
	return (new);
}
