/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:24:24 by jinkim2           #+#    #+#             */
/*   Updated: 2022/04/01 21:39:03 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	int	get_len(long long n)
{
	int	cnt;

	cnt = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		cnt++;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char		*arr;
	int			len;
	int			s;
	long long	num;

	num = (long long)n;
	len = get_len(num);
	s = 0;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	arr[len] = '\0';
	if (num < 0)
	{
		num *= -1;
		s = 1;
	}
	while (len-- > 0)
	{
		arr[len] = (num % 10) + 48;
		num /= 10;
	}
	if (s == 1)
		arr[0] = '-';
	return (arr);
}
