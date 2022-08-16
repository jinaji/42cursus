/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:32:35 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/06 18:06:48 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (dst < src)
	{
		while (len > i)
		{
			dest[i] = source[i];
			i++;
		}
	}
	if (dst > src)
	{
		while (len > i)
		{
			dest[len - 1] = source[len - 1];
			len--;
		}
	}
	return (dst);
}
