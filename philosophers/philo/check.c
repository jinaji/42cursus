/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:57:47 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/30 21:57:25 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_full(t_argv *ag)
{
	if (ag->tme == 0)
		return (0);
	pthread_mutex_lock(ag->write);
	if (ag->full == ag->pnum)
		return (1);
	else
		pthread_mutex_unlock(ag->write);
	return (0);
}

static int	check_die(t_philo *ph)
{
	pthread_mutex_lock(ph->write);
	if (ph->eat_count == 0 && (get_time() - ph->s_time) > ph->ag->ttd)
	{
		printf("%ld %d died\n", (get_time() - ph->s_time), ph->id);
		ph->ag->die = 1;
		return (1);
	}
	else if (ph->last_eat && (get_time() - ph->last_eat) > ph->ag->ttd)
	{
		printf ("%ld %d died\n", (get_time() - ph->s_time), ph->id);
		ph->ag->die = 1;
		return (1);
	}
	else
		pthread_mutex_unlock(ph->write);
	return (0);
}

int	view_philos(t_philo *ph)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < ph->ag->pnum)
		{
			if (check_full(ph->ag))
				return (1);
			if (check_die(ph + i))
				return (1);
			i++;
		}
	}
	return (0);
}
