/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:40:21 by seunghso          #+#    #+#             */
/*   Updated: 2023/02/08 17:48:40 by seunghso         ###   ########.fr       */
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

# define NOT_USING 0
# define USING 1
# define END 0
# define CONTINUE 1
# define HUNGRY 0
# define FULL 1

typedef struct	s_simul_info
{
	int				num_of_philos;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	int				must_eat;
	int				*forks;
	int				status;
	long			start_time;
	pthread_mutex_t	fork_mutex;
	pthread_mutex_t	print_mutex;
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
