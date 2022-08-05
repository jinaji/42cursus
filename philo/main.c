/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:21 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/05 21:35:38 by jinkim2          ###   ########seoul.kr  */
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
		r *= 10;
		r += (str[i] - 48);
		i++;
	}
	return (s * r);
}

int	left(int i, int pnum)
{
	return ((i + pnum - 1) % pnum);
}

int	right(int i, int pnum)
{
	return ((i + 1) % pnum);
}

void	philo_init(t_argv *ag, t_philo *ph, int i, pthread_mutex_t *pork)
{
	ph->id = i;
	ph->state = 2;
	ph->ttd = ag->ttd;
	ph->tte = ag->tte;
	ph->tts = ag->tts;
	if (ag->tme)
		ph->tme = ag->tme;
	ph->pnum = ag->pnum;
	ph->r_pork = pork[right(i, ph->pnum)];
	ph->l_pork = pork[left(i, ph->pnum)];
}

long	get_time(t_philo *ph)
{
	struct timeval	st_time;
	struct timeval	en_time;
	long			diff_sec;

	ph->s_time = gettimeofday(&st_time, 0);
	usleep(5000);
	ph->c_time = gettimeofday(&en_time, 0);
	diff_sec = en_time.tv_usec - st_time.tv_usec;
	return (diff_sec % 1000);
}

void	*philo(void	*param)
{
	printf("philo\n");
	t_philo	*ph;

	ph = (t_philo *)param;
	while (1)
		printf("%ld %d \n", ph->c_time, ph->id);
	return (0);
}

void	argv_init(t_argv *ag, int ac, char **av)
{
	pthread_mutex_t	*pork;
	struct timeval	s_time;
	int				i;

	i = 0;
	ag->pnum = ft_atoi(av[1]);
	ag->ph = (t_philo *)malloc(sizeof(t_philo) * (ag->pnum));
	gettimeofday(&s_time, 0);
	ag->ph->s_time = s_time.tv_usec;
	if (!ag->ph)
		return ;
	ag->ttd = ft_atoi(av[2]);
	ag->tte = ft_atoi(av[3]);
	ag->tts = ft_atoi(av[4]);
	if (ac == 6)
		ag->tme = ft_atoi(av[5]);
	pork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * ag->pnum);
	if (!pork)
		return ;
	while (i < ag->pnum)
	{
		philo_init(ag, &(ag->ph[i]), i, pork);
		i++;
	}
}

int	main(int ac, char **av)
{
	pthread_t		*phi;
	t_argv			ag;
	int				i;

	if (ac != 5)
		return (0);
	argv_init(&ag, ac, av);
	phi = (pthread_t *)malloc(sizeof(pthread_t) * ag.pnum);
	if (!phi)
		return (0);
	i = 0;
	while (i < ag.pnum)
	{
		pthread_create(&phi[i], 0, philo, (void *)&ag.ph[i]);
		i++;
	}
	pthread_join(phi[0], 0);
	pthread_join(phi[1], 0);
	return (0);
}
