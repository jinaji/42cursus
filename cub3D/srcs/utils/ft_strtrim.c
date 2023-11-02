/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:41:04 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 19:18:38 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_char_set(char c, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		index;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while ((s1[start]) && ft_char_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (start < end && ft_char_set(s1[end - 1], set))
		end--;
	str = NULL;
	str = malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (NULL);
	index = 0;
	while (start < end && s1[start] != '\n')
		str[index++] = s1[start++];
	str[index] = '\0';
	return (str);
}
