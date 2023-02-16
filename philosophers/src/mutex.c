/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:29:05 by songseunghu       #+#    #+#             */
/*   Updated: 2023/02/16 01:29:05 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
			return (1);
		}
		simul_info->forks[philo->right] = NOT_USING;
	}
	pthread_mutex_unlock(&simul_info->fork_mutex);
	return (0);
}

void	putdown_fork(t_philo *philo, t_simul_info *simul_info)
{
	pthread_mutex_lock(&simul_info->fork_mutex);
	simul_info->forks[philo->right] = NOT_USING;
	simul_info->forks[philo->left] = NOT_USING;
	pthread_mutex_unlock(&simul_info->fork_mutex);
}

void	mtx_printf(t_simul_info *info, int i, char *str)
{
	long	current_time;

	pthread_mutex_lock(&info->print_mutex);
	if (info->status == CONTINUE)
	{
		current_time = get_time(info);
		printf("%ld %d %s\n", current_time, i, str);
	}
	pthread_mutex_unlock(&info->print_mutex);
}
