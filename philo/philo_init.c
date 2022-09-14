/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:27:46 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/10 19:37:22 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_argv *ag, t_philo *ph, int i, pthread_mutex_t *pork)
{
	int	r;
	int	l;

	memset(ph, 0, sizeof(t_philo));
	ph->id = ++i;
	ph->state = THINKING;
	ph->ttd = ag->ttd;
	ph->tte = ag->tte;
	ph->tts = ag->tts;
	if (ag->tme)
		ph->tme = ag->tme;
	ph->pnum = ag->pnum;
	r = right(i, (ph->pnum));
	l = left(i, (ph->pnum));
	ph->r_pork = &pork[r];
	ph->l_pork = &pork[l];
	ph->write = ag->write;
	ph->m_state = ag->state;
	ph->s_time = get_time();
}

void	pork_mutex_init(pthread_mutex_t *pork, int pnum)
{
	int	i;

	i = 0;
	while (i < pnum)
	{
		pthread_mutex_init(pork + i, 0);
		i++;
	}
}

int	argu_check(t_argv *ag, int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf ("argument error\n");
		return (1);
	}
	ag->pnum = ft_atoi(av[1]);
	if (ag->pnum < 1)
	{
		printf ("argument error\n");
		return (1);
	}
	ag->ph = (t_philo *)malloc(sizeof(t_philo) * (ag->pnum));
	if (!ag->ph)
		return (1);
	ag->ttd = ft_atoi(av[2]);
	ag->tte = ft_atoi(av[3]);
	ag->tts = ft_atoi(av[4]);
	if (ac == 6)
		ag->tme = ft_atoi(av[5]);
	if (ag->ttd < 1 || ag->tte < 1 || ag->tts < 1 || (ac == 6 && ag->tme < 1))
	{
		printf ("argument error\n");
		return (1);
	}
	return (0);
}

int	argv_init(t_argv *ag, int ac, char **av)
{
	pthread_mutex_t	*pork;
	int				i;

	i = 0;
	memset(ag, 0, sizeof(t_argv));
	if (argu_check(ag, ac, av))
		return (1);
	pork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * ag->pnum);
	if (!pork)
		return (1);
	pork_mutex_init(pork, ag->pnum);
	ag->write = malloc(sizeof(pthread_mutex_t));
	ag->state = malloc(sizeof(pthread_mutex_t));
	if (!ag->write || !ag->state)
		return (1);
	pthread_mutex_init(ag->write, 0);
	pthread_mutex_init(ag->state, 0);
	while (i < ag->pnum)
	{
		philo_init(ag, &(ag->ph[i]), i, pork);
		i++;
	}
	return (0);
}
