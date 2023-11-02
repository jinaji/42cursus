/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:46:33 by jinkim2           #+#    #+#             */
/*   Updated: 2022/03/16 14:46:16 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	chr;
	char	*str;
	int		i;

	str = (char *)s;
	chr = (char)c;
	i = 0;
	if (chr == '\0')
		return (&str[ft_strlen(s)]);
	while (str[i])
	{
		if (str[i] == chr)
			return (&str[i]);
		i++;
	}
	return (0);
}
