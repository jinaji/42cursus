/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:08:18 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/04 13:09:19 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/minishell.h"

static char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*str;
	int		i;

	chr = (char)c;
	str = (char *)s;
	i = ft_strlen(s);
	if (chr == '\0')
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == chr)
			return (&str[i]);
		i--;
	}
	return (0);
}

static char	*ft_strcpy(char const *str, char *arr, int start, int end)
{
	int	i;

	i = 0;
	while (end >= start)
		arr[i++] = str[start++];
	arr[i] = '\0';
	free ((char *)str);
	return (arr);
}

static int	get_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (ft_strlen(s1) > i)
	{
		while (ft_strchr(set, s1[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	get_end(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strrchr(set, s1[i]) == 0)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*arr;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup((char *)s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start > end)
		return (ft_strdup(""));
	arr = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!arr)
		return (0);
	return (ft_strcpy(s1, arr, start, end));
}
