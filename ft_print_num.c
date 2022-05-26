/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:58:24 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/23 18:45:08 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
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

char	*ft_us_itoa(unsigned int n)
{
	char	*arr;
	int		len;

	len = get_len(n);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	arr[len] = '\0';
	while (len-- > 0)
	{
		arr[len] = (n % 10) + 48;
		n /= 10;
	}
	return (arr);
}

int	ft_putnbr(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	write(1, str, len);
	free (str);
	return (len);
}

int	ft_us_putnbr(unsigned int n)
{
	char	*str;
	int		len;

	str = ft_us_itoa(n);
	len = get_len(n);
	write (1, str, len);
	free (str);
	return (len);
}
