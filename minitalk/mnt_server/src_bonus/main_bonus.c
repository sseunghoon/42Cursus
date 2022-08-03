/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 16:06:18 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/29 17:28:29 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/server_bonus.h"

int	main(void)
{
	struct sigaction	act;

	ft_printf("Process ID: %d\n", getpid());
	act.sa_sigaction = sig_handler;
	act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &act, NULL) != 0)
	{
		ft_printf("Sigaction Error!\n");
		exit(1);
	}
	if (sigaction(SIGUSR2, &act, NULL) != 0)
	{
		ft_printf("Sigaction Error!\n");
		exit(1);
	}
	while (1)
		pause();
	return (0);
}
