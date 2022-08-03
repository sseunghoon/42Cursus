/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:06:18 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/29 17:20:23 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/server.h"

void	fill_buff(unsigned char *buff, int signum, int *idx, int *cnt_bit)
{
	if (signum == SIGUSR1)
		buff[*idx] |= (1 << *cnt_bit);
	if (signum == SIGUSR2)
		buff[*idx] &= ~(1 << *cnt_bit);
	(*cnt_bit)++;
	if (*cnt_bit > 7)
	{
		*cnt_bit = 0;
		(*idx)++;
	}
}

void	reset_buff(unsigned char *buff, siginfo_t *info, int *idx, int *cnt_bit)
{
	int	i;

	write(1, buff, *idx);
	if (buff[*idx] == 127)
	{
		write(1, "\n", 1);
		send_message("OK", info->si_pid);
	}
	*idx = 0;
	*cnt_bit = 0;
	i = 0;
	while (i < 100)
		buff[i++] &= 0;
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	buff[BUFF_SIZE];
	static int				i;
	static int				cnt_bit;

	(void)context;
	fill_buff(buff, signum, &i, &cnt_bit);
	if (buff[i] == 127 || i == BUFF_SIZE)
		reset_buff(buff, info, &i, &cnt_bit);
}
