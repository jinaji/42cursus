/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:59:33 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/23 18:43:21 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int	i;

	i = 0;
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	ft_hexnum(unsigned int n, const char c)
{
	if (n == 0)
		return (write (1, "0", 1));
	if (16 > n && c == 'x')
		write (1, &"0123456789abcdef"[n], 1);
	else if (16 > n && c == 'X')
		write (1, &"0123456789ABCDEF"[n], 1);
	else
	{
		ft_hexnum(n / 16, c);
		ft_hexnum(n % 16, c);
	}
	return (ft_hexlen(n));
}
