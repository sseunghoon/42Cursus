/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:04:12 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/29 17:24:17 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/client_bonus.h"

int	parse_arg(int argc, char **argv, char **str)
{
	if (argc != 3)
	{
		ft_printf("Error: Invalid argument!\n");
		exit(1);
	}
	*str = argv[2];
	return (ft_atoi(argv[1]));
}

int	main(int argc, char **argv)
{
	char				*str;
	int					pid;
	struct sigaction	act;

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
	pid = parse_arg(argc, argv, &str);
	send_message(str, pid);
	while (1)
		pause();
	return (0);
}
