/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinkim2 <jinkim2@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 15:38:28 by jinkim2           #+#    #+#             */
/*   Updated: 2022/08/05 21:24:32 by jinkim2          ###   ########seoul.kr  */
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

typedef struct s_philo{
	int				id;
	int				state;
	int				ttd;
	int				tte;
	int				tts;
	int				tme;
	int				pnum;
	long			s_time;
	long			c_time;
	pthread_mutex_t	r_pork;
	pthread_mutex_t	l_pork;
}				t_philo;

typedef struct s_argv{
	int		pnum;
	int		ttd;
	int		tte;
	int		tts;
	int		tme;
	t_philo	*ph;
}				t_argv;

#endif