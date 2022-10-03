/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 02:01:57 by gulee             #+#    #+#             */
/*   Updated: 2022/10/03 21:59:09 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

int	ft_atoi(const char *str)
{
	size_t	index;
	size_t	result;
	int		negative;

	index = 0;
	result = 0;
	negative = 1;
	while (str[index] != '\0' && (ft_isspace(str[index])))
		index++;
	if (str[index] != '\0' && (str[index] == '-' || str[index] == '+'))
	{
		if (str[index] == '-')
			negative = -1;
		index++;
	}
	while (str[index] != '\0' && ft_isdigit(str[index]))
	{
		result = (result * 10) + (str[index] - '0');
		index++;
	}
	if (str[index] != '\0')
		return (256);
	return ((int)(result * negative));
}
