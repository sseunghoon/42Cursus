/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:40:21 by seunghso          #+#    #+#             */
/*   Updated: 2023/02/07 15:57:13 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define USING 1
# define NOT_USING 0

typedef struct	s_simul_info
{
	int				number_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_must_eat;
	int				*forks;
	pthread_mutex_t	mutex;
}	t_simul_info;

typedef struct	s_philo_info
{
	int				number_philo;
	int				last_eat_time;
	int				number_eat;
	int				left;
	int				right;
	pthread_t		thread;
	t_simul_info	*t_simul_info;
}	t_philo_info;

#endif
