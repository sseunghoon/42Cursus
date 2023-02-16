/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:28:55 by songseunghu       #+#    #+#             */
/*   Updated: 2023/02/16 01:28:55 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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

int	init_info(t_simul_info *info, int argc, char **argv)
{
	info->num_of_philos = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->must_eat = -1;
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat <= 0)
			return (1);
	}
	if (info->num_of_philos <= 0 || info->time_to_die <= 0
		|| info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (1);
	info->status = CONTINUE;
	info->start_time = 0;
	info->forks = malloc(sizeof(int) * info->num_of_philos);
	if (info->forks == NULL)
		return (1);
	memset(info->forks, NOT_USING, info->num_of_philos * sizeof(int));
	return (0);
}
