/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:55:25 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/28 21:07:20 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_mutex_t	*pork_mutex_init(int pnum)
{
	pthread_mutex_t	*pork;
	int				i;

	i = 0;
	pork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * pnum);
	if (!pork)
		return (0);
	while (i < pnum)
	{
		pthread_mutex_init(pork + i, 0);
		i++;
	}
	return (pork);
}

static int	argu_error(void)
{
	printf ("argument error\n");
	return (1);
}

static int	argu_check(t_argv *ag, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (argu_error());
	ag->pnum = ft_atoi(av[1]);
	if (ag->pnum < 1)
		return (argu_error());
	ag->ttd = ft_atoi(av[2]);
	ag->tte = ft_atoi(av[3]);
	ag->tts = ft_atoi(av[4]);
	if (ac == 6)
		ag->tme = ft_atoi(av[5]);
	if (ag->ttd < 1 || ag->tte < 1 || ag->tts < 1 || (ac == 6 && ag->tme < 1))
		return (argu_error());
	return (0);
}

int	argv_init(t_argv *ag, int ac, char **av)
{
	t_philo			*ph;
	pthread_mutex_t	*pork;
	int				i;

	memset(ag, 0, sizeof(t_argv));
	if (argu_check(ag, ac, av))
		return (1);
	pork = pork_mutex_init(ag->pnum);
	ag->pork = pork;
	ag->write = malloc(sizeof(pthread_mutex_t));
	ph = malloc(sizeof(t_philo) * ag->pnum);
	if (!(ag->write) || !(ph))
		return (1);
	pthread_mutex_init(ag->write, 0);
	i = 0;
	while (i < ag->pnum)
	{
		philo_init(ag, (ph) + i, i, pork);
		i++;
	}
	if (philo_start(ag, ph))
		return (1);
	return (0);
}
