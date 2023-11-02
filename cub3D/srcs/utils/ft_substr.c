/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 23:55:27 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 14:32:52 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	index;

	if (!s)
		return (NULL);
	if (*s == '\0' || start > ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s) <= len)
		len = ft_strlen(s) - start;
	ptr = malloc(sizeof(char) * len + 1);
	if (!ptr)
		return (NULL);
	index = 0;
	while (s[start] && index < len)
		ptr[index++] = s[start++];
	ptr[index] = '\0';
	return (ptr);
}
