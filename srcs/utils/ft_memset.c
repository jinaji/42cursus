/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:33:15 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 14:32:28 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	unsigned char	*arr;
	size_t			count;

	arr = (unsigned char *)ptr;
	count = 0;
	while (count < num)
	{
		arr[count] = value;
		count++;
	}
	ptr = arr;
	return (ptr);
}
