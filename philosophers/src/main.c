/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:42:08 by seunghso          #+#    #+#             */
/*   Updated: 2023/02/06 20:26:18 by seunghso         ###   ########.fr       */
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

void *life_cycle(void *info)
{
	t_simul_info	*simul_info;

	simul_info = (t_simul_info *)info;
	while (1)
	{
		pthread_mutex_lock(&simul_info->mutex);
		write(1, "life_cycle\n", 11);
		sleep(3);
		write(1, "unlock\n", 7);
		pthread_mutex_unlock(&simul_info->mutex);
	}
	
	return NULL;
}

int	create_philosophers(t_simul_info *info)
{
	int				num_philo;
	t_philo_info	*philos;

	if (pthread_mutex_init(&info->mutex, NULL) < 0)
		return -2;
	num_philo = info->number_of_philosophers;
	info->philos = malloc(sizeof(t_philo_info) * num_philo);
	philos = info->philos;
	if (philos->thread == NULL)
	{
		printf("Error to create pthread\n");
		return -1;
	}
	while (num_philo > 0)
	{
		philos[num_philo-1].mutex = &info->mutex;
		pthread_create(&philos[num_philo-1].thread, NULL, life_cycle, info);
		
		num_philo--;
	}
	return 0;
}

int	init_simul_info(t_simul_info *info, int argc, char **argv)
{
	int	i;
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->number_must_eat = ft_atoi(argv[5]);
	info->forks = malloc(sizeof(int) * info->number_of_philosophers);
	if (info->forks == NULL)
		return -1;
	i = 0;
	while (i < info->number_of_philosophers)
		info->forks[i++] = NOT_USING;
	return create_philosophers(info);
}

int	detach_join(t_simul_info *info)
{
	// 에러 처리 할 것
	int				i;
	t_philo_info	*philos;

	philos = info->philos;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_join(philos[i].thread, NULL);
	}
	return 0;
}

int	main(int argc, char **argv)
{
	t_simul_info	simul_info;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid Input\n");
		return -1;
	}
	if (init_simul_info(&simul_info, argc, argv) != 0)
		return -1;
	detach_join(&simul_info);

	return 0;
}
