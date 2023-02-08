/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:42:08 by seunghso          #+#    #+#             */
/*   Updated: 2023/02/08 19:07:14 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0') * sign;
		str++;
	}
	return (result);
}

long	get_time(t_simul_info *info)
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	if (info->start_time == 0)
		info->start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return time.tv_sec * 1000 + time.tv_usec / 1000 - info->start_time;
}

void	mtx_printf(t_simul_info *info, int i, char *str)
{
	pthread_mutex_lock(&info->print_mutex);
	printf("%ld %d %s\n", get_time(info), i, str);
	pthread_mutex_unlock(&info->print_mutex);
}

int ft_usleep(t_simul_info *info, long time)
{
	long	start_time;

	start_time = get_time(info);
	while (get_time(info) < start_time + time)
		usleep(100);
	return (0);
}

int	join_thread(pthread_t *monitor, t_philo *philos, t_simul_info info)
{
	pthread_join(*monitor, NULL);
	monitor = (void *)monitor;
	int i = info.num_of_philos;
	while (i)
	{
		pthread_join(philos[i].thread, NULL);
		i--;
	}
	return (0);
}

void	*monitoring(void *philosophers)
{
	int				i;
	int				num_philos;
	t_philo			*philos;
	t_simul_info	*info;

	philos = (t_philo *)philosophers;
	info = philos[0].t_simul_info;
	num_philos = info->num_of_philos;
	while (info->status == CONTINUE)
	{
		i = 0;
		while (i < num_philos)
		{
			long current_time = get_time(info);
			if (philos[i].last_eat + info->time_to_die < current_time)
			{
				info->status = END;
				mtx_printf(info, i+1, "died");
				break;
			}
			i++;
		}
	}
	return NULL;
}

int	create_monitor(pthread_t *monitor, t_philo *philos)
{
	pthread_create(monitor, NULL, monitoring, philos);
	return 0;
}

int	take_fork(t_philo *philo, t_simul_info *simul_info)
{
	pthread_mutex_lock(&simul_info->fork_mutex);
	if (simul_info->forks[philo->right] == NOT_USING)
	{
		simul_info->forks[philo->right] = USING;
		if (simul_info->forks[philo->left] == NOT_USING)
		{
			simul_info->forks[philo->left] = USING;
			pthread_mutex_unlock(&simul_info->fork_mutex);
			return 1;
		}
		simul_info->forks[philo->right] = NOT_USING;
	}
	pthread_mutex_unlock(&simul_info->fork_mutex);
	return 0;
}

void	putdown_fork(t_philo *philo, t_simul_info *simul_info)
{
	pthread_mutex_lock(&simul_info->fork_mutex);
	simul_info->forks[philo->right] = NOT_USING;
	simul_info->forks[philo->left] = NOT_USING;
	pthread_mutex_unlock(&simul_info->fork_mutex);
}

void	*life_cycle(void *philosopher)
{
	t_philo			*philo;
	t_simul_info	*simul_info;

	philo = (t_philo *)philosopher;
	simul_info = philo->t_simul_info;
	philo->last_eat = get_time(simul_info);
	while (simul_info->status == CONTINUE)
	{
		if (take_fork(philo, simul_info))
		{
			philo->last_eat = get_time(simul_info);
			mtx_printf(simul_info, philo->number+1, "is eating");
			ft_usleep(simul_info, simul_info->time_to_eat);
			putdown_fork(philo, simul_info);
			philo->eat_cnt++;
			if (simul_info->status == CONTINUE)
			{
				mtx_printf(simul_info, philo->number+1, "is sleeping");
				ft_usleep(simul_info, simul_info->time_to_sleep);
			}
			if (simul_info->status == CONTINUE)
			{
				mtx_printf(simul_info, philo->number+1, "is thinking");
				usleep(200);
			}
		}
	}
	return NULL;
}

int	create_philosophers(t_simul_info *info, t_philo *philos)
{
	int	i;

	i = -1;
	while (++i < info->num_of_philos)
	{
		philos[i].number = i;
		philos[i].eat_cnt = 0;
		philos[i].t_simul_info = info;
		philos[i].left = (info->num_of_philos + i - 1) % info->num_of_philos;
		philos[i].right = (info->num_of_philos + i) % info->num_of_philos;
		pthread_create(&(philos[i].thread), NULL, life_cycle, &philos[i]);
	}
	return 0;
}

int	init_simul(t_philo **philos, t_simul_info *info, int argc, char **argv)
{
	if (pthread_mutex_init(&info->fork_mutex, NULL) < 0)
		return -2;
	if (pthread_mutex_init(&info->print_mutex, NULL) < 0)
		return -2;
	info->status = CONTINUE;
	info->num_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	*philos = malloc(sizeof(t_philo) * info->num_of_philos);
	info->forks = malloc(sizeof(int) * info->num_of_philos);
	if (*philos == NULL || info->forks == NULL)
		return -1;
	memset(info->forks, NOT_USING, info->num_of_philos * sizeof(int));
	info->start_time = 0;
	
	return 0;
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_simul_info	simul_info;
	pthread_t		monitor;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid Input\n");
		return -1;
	}
	init_simul(&philos, &simul_info, argc, argv);
	create_philosophers(&simul_info, philos);
	create_monitor(&monitor, philos);
	join_thread(&monitor, philos, simul_info);
	return 0;
}

/**
 * To Do List
 * eat_cnt_mutex 구현
 * pthread, pthrad_mutex 함수 에러처리
 * destroy() 자원할당해제 함수 구현 [free, destroy]
 * NORM
 * 
 * Complete
 * start_time 초기화해서 타임스탬프 이쁘게
 * usleep() 쪼개서 실행해서 철학자 잘 안 죽게 만들기
 * print_mutex구현
 */