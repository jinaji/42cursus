/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:53:22 by jinkim2           #+#    #+#             */
/*   Updated: 2022/10/01 09:51:25 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_argv *ag, t_philo *ph, int i)
{
	memset(ph, 0, sizeof(t_philo));
	ph->ag = ag;
	ph->id = ++i;
	ph->r = right(i, ph->ag->pnum);
	ph->l = left(i, ph->ag->pnum);
	ph->write = ag->write;
	ph->s_time = get_time();
}

static void	*philo(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	if (ph->ag->pnum == 1)
	{
		hold(ph);
		return (0);
	}
	if (ph->id % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(ph->write);
	while (ph->ag->die == 0 && ph->ag->full != ph->ag->pnum)
	{
		pthread_mutex_unlock(ph->write);
		eat(ph);
		pthread_mutex_lock(ph->write);
	}
	pthread_mutex_unlock(ph->write);
	return (0);
}

void	join_philos(t_philo *ph, pthread_t *phi)
{
	int	i;

	i = 0;
	pthread_mutex_unlock(ph->write);
	while (i < ph->ag->pnum)
	{
		pthread_join(phi[i], 0);
		i++;
	}
	i = 0;
	while (i < ph->ag->pnum)
	{
		pthread_mutex_destroy(ph->ag->pork + i);
		i++;
	}
	pthread_mutex_destroy(ph->write);
	free (phi);
	free (ph->ag->pork);
	free (ph->write);
	free (ph);
}

int	philo_start(t_philo *ph)
{
	int			i;
	pthread_t	*phi;

	i = 0;
	phi = malloc(sizeof(pthread_t) * ph->ag->pnum);
	if (!phi)
		return (1);
	while (i < ph->ag->pnum)
	{
		if (pthread_create(phi + i, 0, philo, (void *)(ph + i)))
			return (1);
		i++;
	}
	while (1)
	{
		if (view_philos(ph))
			break ;
	}
	join_philos(ph, phi);
	return (0);
}

int	main(int ac, char **av)
{
	t_argv	ag;

	if (argv_init(&ag, ac, av))
		return (1);
	return (0);
}
