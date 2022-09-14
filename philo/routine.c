/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:26:42 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/10 20:02:01 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	think(t_philo *ph)
{
	pthread_mutex_lock(ph->write);
	pthread_mutex_lock(ph->m_state);
	ph->state = SLEEPING;
	pthread_mutex_unlock(ph->m_state);
	printf("%ld %d is sleeping\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	ft_time(ph->tts);
	pthread_mutex_lock(ph->m_state);
	ph->state = THINKING; // ㅇㅕ기있으면 write 잡고있는상태라 ???? 
	pthread_mutex_unlock(ph->m_state); // 이거 위로 올리고 usleep 걸어줬떠니 덜밀림
	// usleep (3000);
	pthread_mutex_lock(ph->write);
	printf("%ld %d is thinking\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	return (0);
}

int	odd_eat(t_philo *ph)
{
	hold_rpork(ph);
	hold_lpork(ph);
	pthread_mutex_lock(ph->m_state);
	ph->state = EATING;
	pthread_mutex_unlock(ph->m_state);
	pthread_mutex_lock(ph->write);
	ph->last_eat = get_time();
	printf("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	ph->eat_count++;
	pthread_mutex_unlock(ph->write);
	ft_time (ph->tte);
	put_porks(ph);
	think(ph);
	return (0);
}

int	even_eat(t_philo *ph)
{
	hold_lpork(ph);
	hold_rpork(ph);
	pthread_mutex_lock(ph->m_state);
	ph->state = EATING;
	pthread_mutex_unlock(ph->m_state);
	pthread_mutex_lock(ph->write);
	ph->last_eat = get_time();
	printf("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	ph->eat_count++;
	pthread_mutex_unlock(ph->write);
	ft_time (ph->tte);
	put_porks(ph);
	think(ph);
	return (0);
}
