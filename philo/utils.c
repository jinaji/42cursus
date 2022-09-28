/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:54:50 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/28 14:58:08 by jinkim2          ###   ########seoul.kr  */
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
		r = (r * 10 + (str[i] - 48));
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (s * r);
}

ssize_t	get_time(void)
{
	struct timeval	time;
	ssize_t			usec;

	gettimeofday(&time, 0);
	usec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (usec);
}

void	ft_time(ssize_t time)
{
	ssize_t	in_time;

	in_time = get_time();
	while (get_time() - in_time < time)
		usleep (100);
}

int	right(int i, int pnum)
{
	return ((i + pnum - 1) % pnum);
}

int	left(int i, int pnum)
{
	return ((i % pnum - 1) + 1);
}
