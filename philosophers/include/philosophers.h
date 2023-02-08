/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:40:21 by seunghso          #+#    #+#             */
/*   Updated: 2023/02/08 16:36:03 by seunghso         ###   ########.fr       */
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
# define LIVE 0
# define DIE 1

typedef struct	s_simul_info
{
	int				num_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	int				*forks;
	pthread_mutex_t	mutex;
}	t_simul_info;

typedef struct	s_philo
{
	int				number;
	long			last_eat;
	int				eat_cnt;
	int				left;
	int				right;
	int				status;
	pthread_t		thread;
	t_simul_info	*t_simul_info;
}	t_philo;

#endif
