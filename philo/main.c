/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:21 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/07 00:24:28 by jinkim2          ###   ########seoul.kr  */
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

ssize_t	get_time()
{
	struct timeval	time;
	ssize_t			usec;

	gettimeofday(&time, 0);
	usec = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (usec);
}

void	philo_init(t_argv *ag, t_philo *ph, int i, pthread_mutex_t *pork)
{
	int	r;
	int	l;

	r = right(i, (ph->pnum));
	l = left(i, ph->pnum);
	ph->id = i;
	ph->state = 2;
	ph->ttd = ag->ttd;
	ph->tte = ag->tte;
	ph->tts = ag->tts;
	if (ag->tme)
		ph->tme = ag->tme;
	ph->pnum = ag->pnum;
	ph->r_pork = pork[r];
	// ph->r_pork = pork[right(i, ph->pnum)];
	// ph->l_pork = pork[left(i, ph->pnum)];
	ph->l_pork = pork[l];
	ph->s_time = get_time();
}

int	check_die(t_philo *ph)
{
	ssize_t	time;

	time = get_time();
	if (ph->eat_count == 0 && (time - ph->s_time) > ph->ttd)
	{
		pthread_mutex_lock(&ph->write);
		printf("%ld %d died\n", (time - ph->s_time), ph->id);
		pthread_mutex_unlock(&ph->write);
		usleep(100);
		return (1);
	}
	else if (ph->eat_count != 0 && (time - ph->last_eat) > ph->ttd)
	{
		pthread_mutex_lock(&ph->write);
		printf("%ld %d died\n", (time - ph->s_time), ph->id);
		pthread_mutex_unlock(&ph->write);
		usleep(100);
		return (1);
	}
	return (0);
}

int	think(t_philo *ph)
{
	pthread_mutex_lock(&ph->write);
	if (check_die(ph))
		return (1);
	printf("%ld %d is sleeping\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(&ph->write);
	usleep(ph->tts * 1000);
	pthread_mutex_lock(&ph->write);
	if (check_die(ph))
		return (1);
	printf("%ld %d is thinking\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(&ph->write);
	return (0);
}

int	eat(t_philo *ph)
{
	pthread_mutex_lock(&ph->r_pork);
	pthread_mutex_lock(&ph->write);
	if (check_die(ph))
		return (1);
	printf("%ld %d has taken a fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(&ph->write);
	pthread_mutex_lock(&ph->l_pork);
	pthread_mutex_lock(&ph->write);
	if (check_die(ph))
		return (1);
	ph->last_eat = get_time();
	printf("%ld %d has taken a fork\n", (ph->last_eat - ph->s_time), ph->id);
	printf("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	pthread_mutex_unlock(&ph->write);
	ph->eat_count++;
	usleep (ph->tte * 1000);
	pthread_mutex_unlock(&ph->r_pork);
	pthread_mutex_unlock(&ph->l_pork);
	return (0);
}

void	*philo(void	*param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	while (1)
	{
		if (eat(ph) || think(ph))
			return (0);
	}
	return (0);
}

void	argv_init(t_argv *ag, int ac, char **av)
{
	pthread_mutex_t	*pork;
	int				i;

	i = 0;
	memset(ag, 0, sizeof(t_argv));
	ag->pnum = ft_atoi(av[1]);
	ag->ph = (t_philo *)malloc(sizeof(t_philo) * (ag->pnum));
	ag->ph->s_time = get_time();
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
	pthread_join(phi[2], 0);
	// join 안하면 안 도는데 머임 이거 
	// 포크 드는 순서도 정해줘야됨 ... 
	// 글고 옆에서 죽든말든 걍 밥먹음 
	return (0);
}
