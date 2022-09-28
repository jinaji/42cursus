/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:28 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/28 21:43:40 by jinkim2          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_argv{
	int				pnum;
	int				ttd;
	int				tte;
	int				tts;
	int				tme;
	int				full;
	int				die;
	pthread_mutex_t	*pork;
	pthread_t		*phi;
	pthread_mutex_t	*write;
}				t_argv;

typedef struct s_philo{
	int				id;
	int				eat_count;
	int				ttd;
	int				tte;
	int				tts;
	int				tme;
	int				pnum;
	int				check;
	int				full;
	int				die;
	ssize_t			s_time;
	ssize_t			last_eat;
	pthread_mutex_t	*r_pork;
	pthread_mutex_t	*l_pork;
	pthread_mutex_t	*write;
	t_argv			*ag;
}				t_philo;

int		argv_init(t_argv *ag, int ac, char **av);
int		view_philos(t_philo *ph);
void	philo_init(t_argv *ag, t_philo *ph, int i, pthread_mutex_t *pork);
int		philo_start(t_argv *ag, t_philo *ph);
void	even_hold(t_philo *ph);
void	odd_hold(t_philo *ph);
void	put_porks(t_philo *ph);
void	even_eat(t_philo *ph);
void	odd_eat(t_philo *ph);
int		ft_atoi(const char *str);
ssize_t	get_time(void);
void	ft_time(ssize_t time);
int		right(int i, int pnum);
int		left(int i, int pnum);

#endif