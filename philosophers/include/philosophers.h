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
# define CONTINUE 0
# define END 1
# define HUNGRY 0
# define FULL 1

typedef struct s_simul_info
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

typedef struct s_philo
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

// main.c (in main thread)
void	monitoring(t_philo *philos, t_simul_info *info);
int		end_check(t_philo *philos, t_simul_info *info, int *full_cnt, int idx);
int		create_philosophers(t_philo **philos, t_simul_info *info);
int		wait_philosophers(t_philo *philos, t_simul_info info);

// thread.c (in philosophers)
void	*life_cycle(void *philosopher);
void	philo_think(t_simul_info *simul_info, t_philo *philo);
void	philo_sleep(t_simul_info *simul_info, t_philo *philo);
void	philo_eat(t_simul_info *simul_info, t_philo *philo);

// mutex.c
int		take_fork(t_philo *philo, t_simul_info *simul_info);
void	putdown_fork(t_philo *philo, t_simul_info *simul_info);
void	mtx_printf(t_simul_info *info, int i, char *str);

// utils.c
int		ft_atoi(const char *str);
long	get_time(t_simul_info *info);
int		ft_usleep(t_simul_info *info, long time);

// init.c
int		init_info(t_simul_info *info, int argc, char **argv);
int		init_philos(t_simul_info *info, t_philo *philos);

#endif
