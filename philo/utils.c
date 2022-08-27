/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 16:08:38 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/08 16:08:59 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	while ((str[i] >= 9 && 13 >= str[i]) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		i++;
	}
	while ('9' >= str[i] && str[i] >= '0')
	{
		r *= 10;
		r += (str[i] - 48);
		i++;
	}
	return (s * r);
}

int	left(int i, int pnum)
{
	return ((i + pnum - 1) % pnum);
}

int	right(int i, int pnum)
{
	return ((i % pnum) + 1);
}

ssize_t	get_time(void)
{
	struct timeval	time;
	ssize_t			usec;

	gettimeofday(&time, 0);
	usec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (usec);
}
