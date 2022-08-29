/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:21 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/29 16:28:47 by jinkim2          ###   ########seoul.kr  */
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

void	ft_sleep(ssize_t time)
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

void	philo_init(t_argv *ag, t_philo *ph, int i, pthread_mutex_t *pork)
{
	int	r;
	int	l;

	memset(ph, 0, sizeof(t_philo));
	ph->id = ++i;
	ph->state = 2;
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
	ph->s_time = get_time();
	ph->write = ag->write;
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
		printf("%ld %d died\n", (get_time() - ph->s_time), ph->id);
		return (1);
	}
	else
		pthread_mutex_unlock(ph->write);
	return (0);
}

int	think(t_philo *ph)
{
	pthread_mutex_lock(ph->write);
	printf("%ld %d is sleeping\n", (get_time() - ph->s_time), ph->id);
	ph->state = SLEEPING;
	pthread_mutex_unlock(ph->write);
	ft_sleep(ph->tts);
	pthread_mutex_lock(ph->write);
	printf("%ld %d is thinking\n", (get_time() - ph->s_time), ph->id);
	ph->state = THINKING;
	pthread_mutex_unlock(ph->write);
	usleep (100);
	return (0);
}

// int	odd_eat(t_philo *ph)
// {
// 	pthread_mutex_lock(ph->r_pork);
// 	// printf("r %p\n", &ph->r_pork);
// 	// printf("l %p\n", &ph->l_pork);
// 	pthread_mutex_lock(ph->write);
// 	// if (check_die(ph))
// 	// 	return (1);
// 	printf("%ld %d has taken a right fork\n", (get_time() - ph->s_time), ph->id);
// 	pthread_mutex_unlock(ph->write);
// 	pthread_mutex_lock(ph->l_pork);
// 	printf("%ld %d has taken a left fork\n", (get_time() - ph->s_time), ph->id);
// 	ph->last_eat = get_time();
// 	pthread_mutex_lock(ph->write);
// 	// if (check_die(ph))
// 	// 	return (1);
// 	printf("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
// 	pthread_mutex_unlock(ph->write);
// 	ph->eat_count++;
// 	// while(gettimeofday(end_time) > ph->tte)
// 	// 	usleep(500); usleep ㅂㅏ로 때때리리는  것것보보다  이이게  나나을을듯  -키팍
// 	ft_sleep(ph->tte);
// 	// usleep (ph->tte * 1000);
// 	pthread_mutex_unlock(ph->r_pork);
// 	pthread_mutex_unlock(ph->l_pork);
// 	return (0);
// }

int	hold_lpork(t_philo *ph)
{
	pthread_mutex_lock(ph->l_pork);
	pthread_mutex_lock(ph->write);
	printf("%ld %d has taken a left fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	return (0);
}

int	hold_rpork(t_philo *ph)
{
	pthread_mutex_lock(ph->r_pork);
	pthread_mutex_lock(ph->write);
	printf("%ld %d has taken a right fork\n", (get_time() - ph->s_time), ph->id);
	pthread_mutex_unlock(ph->write);
	return (0);
}

void	put_porks(t_philo *ph)
{
	pthread_mutex_unlock(ph->l_pork);
	pthread_mutex_unlock(ph->r_pork);
}

int	odd_eat(t_philo *ph)
{
	if (hold_rpork(ph))
		return (1);
	if (hold_lpork(ph))
		return (1);
	pthread_mutex_lock(ph->write);
	ph->last_eat = get_time();
	printf("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	ph->eat_count++;
	pthread_mutex_unlock(ph->write);
	ft_sleep (ph->tte);
	put_porks(ph);
	think(ph);
	return (0);
}

int	even_eat(t_philo *ph)
{
	if (hold_lpork(ph))
		return (1);
	if (hold_rpork(ph))
		return (1);
	pthread_mutex_lock(ph->write);
	ph->last_eat = get_time();
	printf("%ld %d is eating\n", (ph->last_eat - ph->s_time), ph->id);
	ph->eat_count++;
	pthread_mutex_unlock(ph->write);
	// pthread_mutex_unlock(ph->write);
	// ft_sleep(ph->tte * 1000);
	ft_sleep (ph->tte);
	put_porks(ph);
	think(ph);
	return (0);
}

void	*philo(void	*param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	while (1)
	{
		if (ph->id % 2)
		{
			if (odd_eat(ph) && ph->state == THINKING)
				return (0);
		}
		else
		{
			if (even_eat(ph) && ph->state == THINKING)
				return (0);
		}
	}
	return (0);
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
	if (!ag->write)
		return (1);
	pthread_mutex_init(ag->write, 0);
	while (i < ag->pnum)
	{
		philo_init(ag, &(ag->ph[i]), i, pork);
		i++;
	}
	return (0);
}

int	check_full(t_argv *ag, t_philo *ph)
{
	if (ph->eat_count == ag->tme)
		ag->full++;
	if (ag->full == ag->pnum)
		return (1);
	return (0);
}

int	view_philos(t_argv *ag)
{
	int	i;

	i = 0;
	while (1)
	{
		i = 0;
		while (i < ag->ph->pnum)
		{
			if (check_die(ag->ph + i))
				return (1);
			if (ag->tme && check_full(ag, ag->ph + i))
			{
				pthread_mutex_lock(ag->write);
				printf ("all philos are full\n");
				return (1);
			}
			i++;
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	pthread_t		*phi;
	t_argv			ag;
	int				i;

	if (argv_init(&ag, ac, av))
		return (1);
	phi = (pthread_t *)malloc(sizeof(pthread_t) * ag.pnum);
	if (!phi)
		return (0);
	i = 0;
	while (i < ag.pnum)
	{
		pthread_create(phi + i, 0, philo, (void *)&ag.ph[i]);
		i++;
	}
	while (1)
	{
		if (view_philos(&ag))
			return (0);
	}
	// while (i)
	// {
	// 	pthread_join(*(phi + i), 0);
	// 	i--;
	// }
	// pthread_mutex_unlock(ag.write);
	// join 안하면 안 도는데 머임 이거 
	// 포크 드는 순서도 정해줘야됨 ... 
	// 글고 옆에서 죽든말든 걍 밥먹음 
	// 1명일때 포포크  들들어어야야됨  
	return (0);
}
