/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:14:02 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/23 18:46:21 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hex_print(unsigned long long ptr)
{
	if (16 > ptr)
		write (1, &"0123456789abcdef"[ptr], 1);
	else
	{
		ft_hex_print(ptr / 16);
		ft_hex_print(ptr % 16);
	}
}

int	ft_ptrlen(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (1);
	while (ptr)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

int	ft_hexptr(unsigned long long ptr)
{
	int		len;

	len = ft_ptrlen(ptr);
	len = ft_putstr("0x");
	len += ft_ptrlen(ptr);
	ft_hex_print(ptr);
	return (len);
}
