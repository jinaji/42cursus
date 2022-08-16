/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:05:21 by jinkim2           #+#    #+#             */
/*   Updated: 2022/07/25 14:08:38 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	int		len;
	char	*arr;

	i = 0;
	len = ft_strlen(s1);
	if (n > len)
		return (0);
	arr = (char *)malloc(sizeof(char) * (n + 1));
	if (!arr)
		return (0);
	while (n > i)
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
