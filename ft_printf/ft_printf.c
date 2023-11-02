/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 15:27:57 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/23 18:54:48 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_format(va_list *ap, const char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(*ap, int));
	else if (c == 's')
		len += ft_putstr(va_arg(*ap, char *));
	else if (c == 'p')
		len += ft_hexptr(va_arg(*ap, unsigned long long));
	else if (c == 'x' || c == 'X')
		len += ft_hexnum(va_arg(*ap, unsigned int), c);
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(*ap, int));
	else if (c == 'u')
		len += ft_us_putnbr(va_arg(*ap, unsigned int));
	else if (c == '%')
		len += ft_putchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
			len += check_format(&ap, str[++i]);
		else
			len += ft_putchar(str[i]);
		i++;
	}
	va_end (ap);
	return (len);
}
