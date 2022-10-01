/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:56:28 by jinkim2           #+#    #+#             */
/*   Updated: 2022/10/01 11:13:34 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold(t_philo *ph)
{
	pthread_mutex_lock(ph->ag->pork + ph->l);
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0 && ph->ag->full != ph->ag->pnum)
		printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	if (ph->ag->pnum == 1)
		return ;
	pthread_mutex_lock(ph->ag->pork + ph->r);
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0 && ph->ag->full != ph->ag->pnum)
		printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
}

static void	put_porks(t_philo *ph)
{
	pthread_mutex_unlock(ph->ag->pork + ph->l);
	pthread_mutex_unlock(ph->ag->pork + ph->r);
}

static void	think(t_philo *ph)
{
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0 && ph->ag->full != ph->ag->pnum)
		printf("%ld %d is sleeping\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	ft_time(ph->ag->tts);
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0 && ph->ag->full != ph->ag->pnum)
		printf("%ld %d is thinking\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
}

void	eat(t_philo *ph)
{
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0 && ph->ag->full != ph->ag->pnum)
	{
		pthread_mutex_unlock(ph->write);
		hold(ph);
	}
	else
	{
		pthread_mutex_unlock(ph->write);
		return ;
	}
	pthread_mutex_lock(ph->write);
	ph->last_eat = get_time();
	if (ph->ag->die == 0 && ph->ag->full != ph->ag->pnum)
		printf ("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	ph->eat_count++;
	if (ph->ag->tme > 0 && ph->ag->tme == ph->eat_count)
		ph->ag->full++;
	pthread_mutex_unlock(ph->write);
	ft_time(ph->ag->tte);
	put_porks(ph);
	think(ph);
}
