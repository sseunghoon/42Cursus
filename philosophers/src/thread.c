/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:29:15 by songseunghu       #+#    #+#             */
/*   Updated: 2023/02/16 01:29:15 by songseunghu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	philo_eat(t_simul_info *simul_info, t_philo *philo)
{
	philo->last_eat = get_time(simul_info);
	mtx_printf(simul_info, philo->number + 1, "is eating");
	philo->eat_cnt++;
	ft_usleep(simul_info, simul_info->time_to_eat);
	putdown_fork(philo, simul_info);
}

void	philo_sleep(t_simul_info *simul_info, t_philo *philo)
{
	if (simul_info->status == CONTINUE)
	{
		mtx_printf(simul_info, philo->number + 1, "is sleeping");
		ft_usleep(simul_info, simul_info->time_to_sleep);
	}
}

void	philo_think(t_simul_info *simul_info, t_philo *philo)
{
	if (simul_info->status == CONTINUE)
	{
		mtx_printf(simul_info, philo->number + 1, "is thinking");
		usleep(3000);
	}
}

void	*life_cycle(void *philosopher)
{
	long			current_time;
	t_philo			*philo;
	t_simul_info	*simul_info;

	philo = (t_philo *)philosopher;
	simul_info = philo->t_simul_info;
	philo->last_eat = get_time(simul_info);
	while (simul_info->status == CONTINUE)
	{
		current_time = get_time(simul_info);
		if (philo->last_eat + simul_info->time_to_die < current_time)
		{
			simul_info->status = END;
			printf("%ld %d %s\n", current_time, philo->number + 1, "died");
		}
		if (take_fork(philo, simul_info))
		{
			philo_eat(simul_info, philo);
			philo_sleep(simul_info, philo);
			philo_think(simul_info, philo);
		}
		usleep(100);
	}
	return (NULL);
}
