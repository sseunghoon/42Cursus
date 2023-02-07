/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:42:08 by seunghso          #+#    #+#             */
/*   Updated: 2023/02/07 19:23:46 by seunghso         ###   ########.fr       */
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
	return time.tv_usec;
}

int	join_thread(pthread_t *monitor, t_philo_info *philos, t_simul_info info)
{
	// pthread_join(*monitor, NULL);
	monitor = (void *)monitor;
	printf("philos->number_philo : %d", philos->number_philo);
	int i = info.number_of_philos;
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
	t_simul_info	*info;
	t_philo_info	*philos;

	philos = (t_philo_info *)philosophers;

	info = philos[0].t_simul_info;

	num_philos = info->number_of_philos;
	while (1)
	{
		i = 0;
		while (i < num_philos)
		{
			if (philos[i].last_eat_time + info->time_to_die > get_time())
			{
				printf("%d: Die\n", i+1);
			}
			i++;
		}

	}
	return NULL;
}

int	create_monitor(pthread_t *monitor, t_philo_info *philos)
{
	printf("create monitor %d\n", philos[0].number_philo);
	pthread_create(monitor, NULL, monitoring, philos);

	return 0;
}

int	take_fork(t_philo_info *philo, t_simul_info *simul_info)
{
	printf("right: %d\n", philo->right);
	if (simul_info->forks[philo->right] == NOT_USING)
	{		
		if (simul_info->forks[philo->left] == NOT_USING)
		{
			simul_info->forks[philo->right] = USING;
			simul_info->forks[philo->left] = USING;
		}
		else
		{
			printf("I have right and not have left\n");
			return 0;
		}
		return 1;
	}
	return 0;
}

void	putdown_fork(t_philo_info *philo, t_simul_info *simul_info)
{
	simul_info->forks[philo->right] = NOT_USING;
	simul_info->forks[philo->left] = NOT_USING;
}

void	*life_cycle(void *philosopher)
{
	t_philo_info	*philo;
	t_simul_info	*simul_info;

	philo = (t_philo_info *)philosopher;
	simul_info = philo->t_simul_info;
	while (1)
	{
		pthread_mutex_lock(&simul_info->mutex);
		int success = take_fork(philo, simul_info);
		if (success)
		{
			philo->last_eat_time = get_time();
			printf("%d %d: Eat\n", philo->last_eat_time, philo->number_philo);
			usleep(simul_info->time_to_eat * 1000);
			printf("wake up\n");
			putdown_fork(philo, simul_info);
		}
		pthread_mutex_unlock(&simul_info->mutex);
		printf("%d: Sleep\n", philo->number_philo);
		usleep(simul_info->time_to_sleep * 1000);
		printf("%d: Thinking\n", philo->number_philo);
	}
	
	return NULL;
}

int	create_philosophers(t_simul_info *info, t_philo_info *philos)
{
	int	i;

	i = -1;
	while (++i < info->number_of_philos)
	{
		printf("i:%d\n",i);
		philos[i].number_philo = i;
		philos[i].number_eat = 0;
		philos[i].last_eat_time = 0;
		philos[i].t_simul_info = info;
		philos[i].left = (info->number_of_philos + i - 1) % info->number_of_philos;
		philos[i].right = (info->number_of_philos + i) % info->number_of_philos;
		pthread_create(&philos[i].thread, NULL, life_cycle, &philos[i]);
	}
	return 0;
}

int	init_simul(t_philo_info **philos, t_simul_info *info, int argc, char **argv)
{
	if (pthread_mutex_init(&info->mutex, NULL) < 0)
		return -2;
	info->number_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->number_must_eat = ft_atoi(argv[5]);
	*philos = malloc(sizeof(t_philo_info) * info->number_of_philos);
	info->forks = malloc(sizeof(int) * info->number_of_philos);
	if (*philos == NULL || info->forks == NULL)
		return -1;
	memset(info->forks, NOT_USING, info->number_of_philos * sizeof(int));
	return 0;
}

int	main(int argc, char **argv)
{
	t_philo_info	*philos;
	t_simul_info	simul_info;
	pthread_t		monitor;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid Input\n");
		return -1;
	}
	init_simul(&philos, &simul_info, argc, argv);
	create_philosophers(&simul_info, philos);
	// create_monitor(&monitor, philos);
	join_thread(&monitor, philos, simul_info);

	return 0;
}
