/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:42:08 by seunghso          #+#    #+#             */
/*   Updated: 2023/02/08 17:19:54 by seunghso         ###   ########.fr       */
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

long	get_time()
{
	struct	timeval time;

	gettimeofday(&time, NULL);
	return (size_t)time.tv_sec * 1000 + ((size_t)time.tv_usec / 1000);
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
			long current_time = get_time();
			if (philos[i].last_eat + info->time_to_die < current_time)
			{
				info->status = END;
				printf("%ld %d died\n", current_time, philos[i].number+1);
				break;
			}
			i++;
		}
		usleep(1000);
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
	pthread_mutex_lock(&simul_info->mutex);
	if (simul_info->forks[philo->right] == NOT_USING)
	{
		simul_info->forks[philo->right] = USING;
		if (simul_info->forks[philo->left] == NOT_USING)
		{
			simul_info->forks[philo->left] = USING;
			pthread_mutex_unlock(&simul_info->mutex);
			return 1;
		}
		simul_info->forks[philo->right] = NOT_USING;
	}
	pthread_mutex_unlock(&simul_info->mutex);
	return 0;
}

void	putdown_fork(t_philo *philo, t_simul_info *simul_info)
{
	pthread_mutex_lock(&simul_info->mutex);
	simul_info->forks[philo->right] = NOT_USING;
	simul_info->forks[philo->left] = NOT_USING;
	pthread_mutex_unlock(&simul_info->mutex);
}

void	*life_cycle(void *philosopher)
{
	t_philo			*philo;
	t_simul_info	*simul_info;

	philo = (t_philo *)philosopher;
	simul_info = philo->t_simul_info;
	while (simul_info->status == CONTINUE)
	{
		if (take_fork(philo, simul_info))
		{
			philo->last_eat = get_time();
			printf("%ld %d is eating\n", philo->last_eat, philo->number+1);
			usleep(simul_info->time_to_eat * 1000);
			putdown_fork(philo, simul_info);
			if (simul_info->status == CONTINUE)
			{
				printf("%ld %d is sleeping\n", get_time(), philo->number+1);
				usleep(simul_info->time_to_sleep * 1000);
			}
			if (simul_info->status == CONTINUE)
			{
				printf("%ld %d is thinking\n", get_time(), philo->number+1);
				usleep(1000);
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
		philos[i].last_eat = get_time();
		philos[i].t_simul_info = info;
		philos[i].left = (info->num_of_philos + i - 1) % info->num_of_philos;
		philos[i].right = (info->num_of_philos + i) % info->num_of_philos;
		pthread_create(&(philos[i].thread), NULL, life_cycle, &philos[i]);
	}
	return 0;
}

int	init_simul(t_philo **philos, t_simul_info *info, int argc, char **argv)
{
	if (pthread_mutex_init(&info->mutex, NULL) < 0)
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
