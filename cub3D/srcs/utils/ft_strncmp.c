/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gulee <gulee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 17:49:59 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 14:32:44 by gulee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	size_t	index;

	index = 0;
	if (size == 0)
		return (0);
	while ((index < size - 1) && (str1[index] != '\0') \
		&& (str2[index] != '\0') && str1[index] == str2[index])
		index++;
	return ((unsigned char)str1[index] - (unsigned char)str2[index]);
}
