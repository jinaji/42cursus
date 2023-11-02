/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:52:16 by jinkim2           #+#    #+#             */
/*   Updated: 2022/05/23 18:49:56 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_putchar(char c);
int		ft_strlen(char *str);
int		ft_putstr(char *str);

int		ft_hexlen(unsigned int n);
int		ft_hexnum(unsigned int n, const char c);

char	*ft_itoa(int n);
char	*ft_us_itoa(unsigned int n);
int		ft_putnbr(int n);
int		ft_us_len(unsigned int n);
int		ft_us_putnbr(unsigned int n);

void	ft_hex_print(unsigned long long ptr);
int		ft_ptrlen(unsigned long long ptr);
int		ft_hexptr(unsigned long long ptr);

int		check_format(va_list *ap, const char c);
int		ft_printf(const char *str, ...);

#endif
