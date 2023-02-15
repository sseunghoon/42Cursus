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

int	wait_philosophers(t_philo *philos, t_simul_info info)
{
	int	i;

	i = info.num_of_philos;
	while (i)
		if (pthread_join(philos[i--].thread, NULL))
			return (1);
	return (0);
}

void	monitoring(t_philo *philos, t_simul_info *info)
{
	int	i;
	int	full_cnt;

	full_cnt = 0;
	while (info->status == CONTINUE)
	{
		i = 0;
		while (i < info->num_of_philos)
		{
			long current_time = get_time(info);
			if (philos[i].last_eat + info->time_to_die < current_time)
			{
				info->status = END;
				mtx_printf(info, i+1, "died");
				break;
			}
			if (philos[i].status == HUNGRY && philos[i].eat_cnt >= info->must_eat)
			{
				philos[i].status = FULL;
				full_cnt++;
				if (full_cnt >= info->num_of_philos)
				{
					info->status = END;
					break;
				}
			}
			i++;
		}
	}
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
			philo->eat_cnt++;
			ft_usleep(simul_info, simul_info->time_to_eat);
			putdown_fork(philo, simul_info);
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

int	init_philos(t_simul_info *info, t_philo *philos)
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
		philos[i].status = FULL;
		if (info->must_eat >= 0)
			philos[i].status = HUNGRY;
	}
	return (0);
}

int init_info(t_simul_info *info, int argc, char **argv)
{
	info->num_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat = -1;
	if (argc == 6)
		info->must_eat = ft_atoi(argv[5]);
	if (info->num_of_philos <= 0 || info->time_to_die <= 0 || info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (1);
	info->status = CONTINUE;	
	info->start_time = 0;
	info->forks = malloc(sizeof(int) * info->num_of_philos);
	if (info->forks == NULL)
		return (1);
	memset(info->forks, NOT_USING, info->num_of_philos * sizeof(int));
}

int	create_philosophers(t_philo **philos, t_simul_info *info)
{
	if (pthread_mutex_init(&info->fork_mutex, NULL) || pthread_mutex_init(&info->print_mutex, NULL))
		return (1);
	*philos = malloc(sizeof(t_philo) * info->num_of_philos);
	if (*philos == NULL)
		return (1);
	if (init_philos(info, *philos))
	{
		free(*philos);
		free(info->forks);
		return (1);
	}
	if (pthread_create(&((*philos)[i].thread), NULL, life_cycle, &((*philos)[i])))
		return (1);
	return 0;
}

int	main(int argc, char **argv)
{
	t_philo			*philos;
	t_simul_info	simul_info;

	if (argc != 5 && argc != 6)
		return (1);
	if (init_info(&simul_info, argc, argv))
		return (2);
	if (create_philosophers(&philos, &simul_info))
		return (3);
	monitoring(philos, &simul_info);
	wait_philosophers(philos, simul_info)
	free(philos);
	free(simul_info.forks);
	return (0);
}
