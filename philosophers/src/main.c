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

int	wait_philosophers(t_philo *philos, t_simul_info info)
{
	int	i;

	i = info.num_of_philos;
	while (i)
		if (pthread_join(philos[i--].thread, NULL))
			return (1);
	return (0);
}

int	end_check(t_philo *philos, t_simul_info *info, int *full_cnt, int idx)
{
	if (philos[idx].status == HUNGRY && philos[idx].eat_cnt >= info->must_eat)
	{
		philos[idx].status = FULL;
		(*full_cnt)++;
		if (*full_cnt >= info->num_of_philos)
			info->status = END;
	}
	return (info->status);
}

void	monitoring(t_philo *philos, t_simul_info *info)
{
	int	i;
	int	full_cnt;

	full_cnt = 0;
	while (info->status == CONTINUE)
	{
		i = -1;
		while (++i < info->num_of_philos)
		{
			if (end_check(philos, info, &full_cnt, i))
				break ;
		}
	}
}

int	create_philosophers(t_philo **philos, t_simul_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->fork_mutex, NULL)
		|| pthread_mutex_init(&info->print_mutex, NULL))
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
	i = -1;
	while (++i < info->num_of_philos)
		if (pthread_create(&(*philos)[i].thread, 0, life_cycle, &(*philos)[i]))
			return (1);
	return (0);
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
	usleep(100);
	monitoring(philos, &simul_info);
	wait_philosophers(philos, simul_info);
	free(philos);
	free(simul_info.forks);
	return (0);
}
