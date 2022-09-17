/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:53:22 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/17 20:47:54 by jinkim2          ###   ########seoul.kr  */
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
		r = (r * 10 + (str[i] - 48));
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	return (s * r);
}

ssize_t	get_time(void)
{
	struct timeval	time;
	ssize_t			usec;

	gettimeofday(&time, 0);
	usec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (usec);
}

void	ft_time(ssize_t time)
{
	ssize_t	in_time;

	in_time = get_time();
	while (get_time() - in_time < time)
		usleep (100);
}

int	left(int i, int pnum)
{
	return ((i + pnum - 1) % pnum);
}

int	right(int i, int pnum)
{
	return ((i % pnum - 1) + 1);
}

int	check_full(t_philo *ph)
{
	int	i;

	i = 0;
	if (ph->tme == -1)
		return (0);
	pthread_mutex_lock(ph->write);
	if (ph->eat_count == ph->tme)
	{
		ph->full++;
		if (ph->full >= ph->pnum)
		{
			printf("All philos are full\n");
			return (1);
		}
	}
	pthread_mutex_unlock(ph->write);
	return (0);
}

int	argu_error(void)
{
	printf ("argument error\n");
	return (1);
}

void	hold_lpork(t_philo *ph)
{
	pthread_mutex_lock(ph->l_pork);
	pthread_mutex_lock(ph->write);
	printf("%ld %d has taken a left fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
}

void	hold_rpork(t_philo *ph)
{
	pthread_mutex_lock(ph->r_pork);
	pthread_mutex_lock(ph->write);
	printf("%ld %d has taken a right fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
}

void	put_porks(t_philo *ph)
{
	pthread_mutex_unlock(ph->l_pork);
	pthread_mutex_unlock(ph->r_pork);
}

int	argu_check(t_argv *ag, int ac, char **av, t_philo **ph)
{
	if (ac != 5 && ac != 6)
		return (argu_error());
	ag->pnum = ft_atoi(av[1]);
	if (ag->pnum < 1)
		return (argu_error());
	*ph = (t_philo *)malloc(sizeof(t_philo) * ag->pnum);
	if (!*ph)
		return (1);
	ag->ttd = ft_atoi(av[2]);
	ag->tte = ft_atoi(av[3]);
	ag->tts = ft_atoi(av[4]);
	if (ac == 6)
		ag->tme = ft_atoi(av[5]);
	if (ag->ttd < 1 || ag->tte < 1 || ag->tts < 1 || (ac == 6 && ag->tme < 1))
		return (argu_error());
	return (0);
}

pthread_mutex_t	*pork_mutex_init(int pnum)
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

void	philo_init(t_argv *ag, t_philo *ph, int i, pthread_mutex_t *pork)
{
	int	r;
	int	l;

	// memset(ph, 0, sizeof(t_philo));
	ph->id = ++i;
	ph->state = THINKING;
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
	ph->m_state = ag->state;
	ph->ag = ag;
	ph->s_time = get_time();
}

int	think(t_philo *ph)
{
	pthread_mutex_lock(ph->write);
	printf("%ld %d is sleeping\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	ft_time(ph->tts);
	pthread_mutex_lock(ph->write);
	printf("%ld %d is thinking\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	return (0);
}

int	even_eat(t_philo *ph)
{
	hold_lpork(ph);
	hold_rpork(ph);
	pthread_mutex_lock(ph->write);
	ph->last_eat = get_time();
	printf("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	ph->eat_count++;
	pthread_mutex_unlock(ph->write);
	ft_time(ph->tte);
	put_porks(ph);
	think(ph);
	return (0);
}

int	odd_eat(t_philo *ph)
{
	hold_rpork(ph);
	hold_lpork(ph);
	pthread_mutex_lock(ph->write);
	ph->last_eat = get_time();
	printf ("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	ph->eat_count++;
	pthread_mutex_unlock(ph->write);
	ft_time (ph->tte);
	put_porks(ph);
	check_full(ph);
	think(ph);
	return (0);
}

void	*philo(void *param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	// pthread_mutex_lock(ph->write);
	while (ph->tme != ph->eat_count)
	{
		if (ph->id % 2)
		{
			usleep (100);
			odd_eat (ph);
		}
		else
		{
			even_eat(ph);
		}
		usleep (100);
	}
	return (0);
}

void	philo_start(t_argv *ag, t_philo *ph)
{
	int			i;
	pthread_t	*phi;

	i = 0;
	phi = malloc(sizeof(pthread_t) * ph->pnum);
	if (!phi)
		return ;
	while (i < ph->pnum)
	{
		pthread_create(phi + i, 0, philo, (void *)&ph[i]);
		i++;
	}
	ag->phi = phi;
}

int	argv_init(t_argv *ag, int ac, char **av, t_philo **ph)
{
	pthread_mutex_t	*pork;
	int				i;

	i = 0;
	memset(ag, 0, sizeof(t_argv));
	if (argu_check(ag, ac, av, ph))
		return (1);
	pork = pork_mutex_init(ag->pnum);
	ag->write = malloc(sizeof(pthread_mutex_t));
	ag->state = malloc(sizeof(pthread_mutex_t));
	if (!ag->write || !ag->state)
		return (1);
	pthread_mutex_init(ag->write, 0);
	pthread_mutex_init(ag->state, 0);
	while (i < ag->pnum)
	{
		philo_init(ag, *(ph + i), i, pork);
		i++;
	}
	philo_start(ag, *ph);
	return (0);
}

void	join_philos(t_argv ag)
{
	int	i;

	i = 0;
	while (ag.pnum > i)
	{
		pthread_join(*(ag.phi + i), 0);
		i++;
	}
}

int	check_die(t_philo *ph)
{
	pthread_mutex_lock(ph->write);
	if (ph->eat_count == 0 && (get_time() - ph->s_time) > ph->ttd)
	{
		printf("%ld %d died\n", (get_time() - ph->s_time), ph->id);
		return (1);
	}
	else if (ph->eat_count != 0 && (get_time() - ph->last_eat) > ph->ttd)
	{
		printf ("%ld %d died\n", (get_time() - ph->s_time), ph->id);
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
		while (i < ph->pnum)
		{
			if (check_die(ph + i))
				return (1);
			i++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo	*ph;
	t_argv	ag;

	if (argv_init(&ag, ac, av, &ph))
		return (1);
	join_philos(ag);
	while (1)
	{
		view_philos(ph);
		break ;
	}
	return (0);
	// pthread_mutex_unlock(ag.write);
	// while (1);
}

/*
	체체크하는거 먹먹는 함수 안에서 하기루
	philo 안에 ag 넣었으니까 이거 좀 정리 ...
	하면될듯 ????????
*/