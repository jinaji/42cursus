/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:53:22 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/29 17:17:45 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_argv *ag, t_philo *ph, int i, pthread_mutex_t *pork)
{
	int	r;
	int	l;

	memset(ph, 0, sizeof(t_philo));
	ph->id = ++i;
	ph->ttd = ag->ttd;
	ph->tte = ag->tte;
	ph->tts = ag->tts;
	if (ag->tme)
		ph->tme = ag->tme;
	else
		ph->tme = -1;
	ph->pnum = ag->pnum;
	r = right(i, ph->pnum);
	l = left(i, ph->pnum);
	ph->r_pork = &pork[r];
	ph->l_pork = &pork[l];
	ph->write = ag->write;
	ph->ag = ag;
	ph->s_time = get_time();
}

static void	*philo(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	if (ph->pnum == 1)
	{
		hold(ph);
		return (0);
	}
	if (ph->id % 2 == 0)
		usleep(1000);
	pthread_mutex_lock(ph->write);
	while (ph->ag->die == 0)
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
	while (i < ph->pnum)
	{
		pthread_join(phi[i], 0);
		i++;
	}
	pthread_mutex_destroy(ph->ag->pork);
	pthread_mutex_destroy(ph->write);
	free (ph);
}

int	philo_start(t_argv *ag, t_philo *ph)
{
	int			i;
	pthread_t	*phi;

	i = 0;
	phi = malloc(sizeof(pthread_t) * ph->pnum);
	if (!phi)
		return (1);
	while (i < ph->pnum)
	{
		pthread_create(phi + i, 0, philo, (void *)&ph[i]);
		i++;
	}
	ag->phi = phi;
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
