/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:42:08 by seunghso          #+#    #+#             */
/*   Updated: 2022/08/11 18:30:04 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	sigint_handler(int signo)
{
	ft_printf("Signo: %d\n", signo);
	ft_printf("Press Ctrl + C\n");
}

void	set_signal_handler(void)
{
	signal(SIGINT, sigint_handler);
}

int	main(void)
{
	set_signal_handler();
	while (1)
	{
		get_next_line(0);
	}
}
