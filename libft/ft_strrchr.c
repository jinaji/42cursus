/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:52:32 by jinkim2           #+#    #+#             */
/*   Updated: 2022/03/16 14:47:20 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*str;
	int		i;

	chr = (char)c;
	str = (char *)s;
	i = ft_strlen(s);
	if (chr == '\0')
		return (&str[i]);
	while (i >= 0)
	{
		if (str[i] == chr)
			return (&str[i]);
		i--;
	}
	return (0);
}
