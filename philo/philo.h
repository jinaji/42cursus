/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:28 by jinkim2           #+#    #+#             */
/*   Updated: 2022/09/17 18:35:59 by jinkim2          ###   ########seoul.kr  */
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

# define SLEEPING 0
# define EATING	1
# define THINKING 2

typedef struct s_argv{
	int				pnum;
	int				ttd;
	int				tte;
	int				tts;
	int				tme;
	int				full;
	int				die;
	pthread_t		*phi;
	pthread_mutex_t	*write;
	pthread_mutex_t	*state;
}				t_argv;

typedef struct s_philo{
	int				id;
	int				state;
	int				eat_count;
	int				ttd;
	int				tte;
	int				tts;
	int				tme;
	int				pnum;
	int				check;
	int				full;
	ssize_t			s_time;
	ssize_t			last_eat;
	pthread_mutex_t	*r_pork;
	pthread_mutex_t	*l_pork;
	pthread_mutex_t	*write;
	pthread_mutex_t	*m_state;
	t_argv			*ag;
}				t_philo;


// int		check_die(t_philo *ph);
// void	hold_lpork(t_philo *ph);
// void	hold_rpork(t_philo *ph);
// void	put_porks(t_philo *ph);
// void	*philo(void *param);
// int		check_full(t_argv *ag, t_philo *ph);
// int		view_philos(t_argv *ag);

// void	philo_init(t_argv *ag, t_philo *ph, int i, pthread_mutex_t *pork);
// void	pork_mutex_init(pthread_mutex_t *pork, int pnum);
// int		argu_check(t_argv *ag, int ac, char **av);
// int		argv_init(t_argv *ag, int ac, char **av);

// int		think(t_philo *ph);
// int		odd_eat(t_philo *ph);
// int		even_eat(t_philo *ph);

// int		ft_atoi(const char *str);
// ssize_t	get_time(void);
// void	ft_time(ssize_t time);
// int		left(int i, int pnum);
// int		right(int i, int pnum);

#endif