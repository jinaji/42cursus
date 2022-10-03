/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 01:16:20 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 14:32:33 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

static size_t	count_words(const char *str, char c)
{
	size_t	index;
	size_t	count;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (str[index] && str[index] == c)
			index++;
		if (str[index])
			count++;
		while (str[index] && str[index] != c)
			index++;
	}
	return (count);
}

static size_t	count_len(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (str[count] && str[count] != c)
		count++;
	return (count);
}

static char	**all_free(char **str, size_t count)
{
	size_t	index;

	index = 0;
	while (index < count)
	{
		free(str[index]);
		str[index] = NULL;
		index++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

static char	**fill_str(char **new, const char *str, char c, size_t count)
{
	size_t	len;
	size_t	size;
	size_t	index;

	index = 0;
	size = 0;
	while (size < count)
	{
		while (str[index] == c)
			index++;
		len = count_len(str + index, c);
		new[size] = ft_substr(str, index, len);
		if (!new[size])
			return (all_free(new, size));
		while (str[index] && str[index] != c)
			index++;
		size++;
	}
	new[size] = NULL;
	return (new);
}

char	**ft_split(const char *str, char c)
{
	size_t	count;
	char	**new;

	if (!str)
		return (NULL);
	count = count_words(str, c);
	new = (char **)malloc((count + 1) * sizeof(*new));
	if (!new)
		return (NULL);
	return (fill_str(new, str, c, count));
}
