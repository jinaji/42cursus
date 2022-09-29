/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:56:28 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/29 17:18:47 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	hold(t_philo *ph)
{
	pthread_mutex_lock(ph->l_pork);
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0)
		printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	if (ph->pnum == 1)
		return ;
	pthread_mutex_lock(ph->r_pork);
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0)
		printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
}

static void	put_porks(t_philo *ph)
{
	pthread_mutex_unlock(ph->l_pork);
	pthread_mutex_unlock(ph->r_pork);
}

static void	think(t_philo *ph)
{
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0)
		printf("%ld %d is sleeping\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	ft_time(ph->tts);
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0)
		printf("%ld %d is thinking\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
}

void	eat(t_philo *ph)
{
	if (ph->die == 0)
		hold(ph);
	pthread_mutex_lock(ph->write);
	ph->last_eat = get_time();
	if (ph->ag->die == 0)
		printf ("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	ph->eat_count++;
	if (ph->tme > 0 && ph->tme == ph->eat_count)
		ph->ag->full++;
	pthread_mutex_unlock(ph->write);
	ft_time(ph->tte);
	put_porks(ph);
	think(ph);
}
