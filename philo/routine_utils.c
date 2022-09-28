/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:56:46 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/28 21:48:09 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	odd_hold(t_philo *ph)
{
	pthread_mutex_lock(ph->l_pork);
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0)
		printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	if (ph->pnum <= 1)
	{
		pthread_mutex_unlock(ph->write);
		return ;
	}
	pthread_mutex_lock(ph->r_pork);
	if (ph->ag->die == 0)
		printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
}

void	even_hold(t_philo *ph)
{
	pthread_mutex_lock(ph->r_pork);
	pthread_mutex_lock(ph->write);
	if (ph->ag->die == 0)
		printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	if (ph->pnum <= 1)
	{
		pthread_mutex_unlock(ph->write);
		return ;
	}
	pthread_mutex_lock(ph->l_pork);
	if (ph->ag->die == 0)
		printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
}

void	put_porks(t_philo *ph)
{
	pthread_mutex_unlock(ph->l_pork);
	pthread_mutex_unlock(ph->r_pork);
}
