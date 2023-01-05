/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:42:08 by seunghso          #+#    #+#             */
/*   Updated: 2022/09/01 18:02:07 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_mutex(pthread_mutex_t *mutex)
{
	if (pthread_mutex_init(mutex, NULL) < 0)
	{
		printf("Error to init mutex\n");
		exit(-1);
	}
}

void *life_cycle(void *mutex)
{
	// 임시로 일단 먹기만 + 예외처리
	pthread_mutex_lock((pthread_mutex_t *)mutex);
	printf("Yammy~\n");
	pthread_mutex_unlock((pthread_mutex_t *)mutex);

	return NULL;
}

void	create_philosophers(pthread_t **philosophers, int num_philosophers, pthread_mutex_t *mutex)
{
	*philosophers = malloc(sizeof(pthread_t) * num_philosophers);
	if (*philosophers == NULL)
	{
		printf("Error to create pthread\n");
		exit(-1);
	}
	while (num_philosophers)
	{
		pthread_create(philosophers[num_philosophers-1], NULL, life_cycle, mutex);
		num_philosophers--;
	}
}

int	main(int argc, char **argv)
{
	pthread_t		*philosophers;
	pthread_mutex_t	mutex;

	if (argc != 5 && argc != 6)
	{
		printf("Invalid Input\n");
		exit(0);
	}
	init_mutex(&mutex);
	create_philosophers(&philosophers, ft_atoi(argv[1]), &mutex);
}
