/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: songseunghun <songseunghun@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:29:20 by songseunghu       #+#    #+#             */
/*   Updated: 2023/02/16 01:29:20 by songseunghu      ###   ########.fr       */
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
	struct timeval	time;

	gettimeofday(&time, NULL);
	if (info->start_time == 0)
		info->start_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (time.tv_sec * 1000 + time.tv_usec / 1000 - info->start_time);
}

int	ft_usleep(t_simul_info *info, long time)
{
	long	start_time;

	start_time = get_time(info);
	while (get_time(info) < start_time + time)
		usleep(100);
	return (0);
}
