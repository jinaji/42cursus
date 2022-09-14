/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:21 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/10 20:15:59 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_die(t_philo *ph)
{
	if (ph->check == 1)
		return (0);
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

void	*philo(void	*param)
{
	t_philo	*ph;

	ph = (t_philo *)param;
	while (1)
	{
		// if (ph->tme && ph->eat_count >= ph->tme)
		// 	break ;
		if (ph->id % 2)
		{
			pthread_mutex_lock(ph->m_state);
			if (ph->state == THINKING)
			{
				pthread_mutex_unlock(ph->m_state);
				odd_eat(ph);
			}
			pthread_mutex_unlock(ph->m_state);
		}
		else
		{
			pthread_mutex_lock(ph->m_state);
			if (ph->state == THINKING)
			{
				pthread_mutex_unlock(ph->m_state);
				even_eat(ph);
			}
			pthread_mutex_unlock(ph->m_state);
		}
	}
	return (0);
}

int	check_full(t_argv *ag, t_philo *ph)
{
	// printf ("%d %d\n", ag->full, ag->pnum);
	// pthread_mutex_lock(ag->write);
	if (ph->eat_count >= ag->tme )
	{
		ag->full++;

	}
	if (ag->full == ag->pnum)
		return (1);
	// pthread_mutex_unlock(ag->write);
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
			pthread_mutex_lock(ag->state);
			if (ag->tme && (ag->ph + i)->state == THINKING)
			{
				pthread_mutex_unlock(ag->state);
				pthread_mutex_lock(ag->write);
				if (check_full(ag, ag->ph + i))
				{
					// pthread_mutex_lock(ag->write);
					// printf ("all philos are full\n");
					return (1);
				}
				pthread_mutex_unlock(ag->write);
			}
			pthread_mutex_unlock(ag->state);
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
		// pthread_detach(phi[i]);
		i++;
	}
	while (1)
	{
		if (view_philos(&ag))
			return (0);
	}
	while (i)
	{
		pthread_join(*(phi + i), 0);
		i--;
	}
	return (0);
}

/*
먹은 수랑 먹어야되는 수 같으면 다먹은 수 체크되게 했는데 ...
먹으러 못들어가서 집계가 두번되는 애들이 있는 것 같음
ㅠ ㅠ

sleeping이 계속 찍힘 ...
가끔 포크도 들고 ...
먹기도 함 ...
미친넘들 ...
write 뮤텍스를 못잡는 것 같음 모니터링 하는 애가
*/