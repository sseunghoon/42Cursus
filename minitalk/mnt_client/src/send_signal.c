/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_signal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:04:12 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/29 17:19:14 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/client.h"

void	put_end(int pid)
{
	unsigned char	uc;

	uc = 127;
	while (uc)
	{
		if (uc % 2 == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		uc /= 2;
		usleep(1000);
	}
}

void	send_message(char *str, int pid)
{
	int				i;
	int				bit_cnt;
	unsigned char	uc;

	i = 0;
	while (str[i])
	{
		uc = (unsigned char)str[i];
		bit_cnt = 8;
		while (bit_cnt--)
		{
			if (uc == 0 || uc % 2 == 0)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			uc /= 2;
			usleep(1000);
		}
		i++;
	}
	put_end(pid);
}
