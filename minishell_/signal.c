/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 15:37:15 by yehyun            #+#    #+#             */
/*   Updated: 2022/09/15 10:38:59 by yehyun           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_exit_code;

void	signal_handler(int sig)
{
	if (sig == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
		g_exit_code = 1;
	}
}

void	signal_handler2(int signal)
{
	if (signal == SIGINT)
	{
		g_exit_code = 130;
		write(1, "\n", 1);
	}
	else if (signal == SIGQUIT)
	{
		g_exit_code = 131;
		write(1, "Quit: 3\n", 8);
	}
}

void	set_signal_handler(int flag)
{
	if (!flag)
	{
		signal(SIGQUIT, SIG_IGN);
		signal(SIGINT, signal_handler);
	}
	else
	{
		signal(SIGQUIT, signal_handler2);
		signal(SIGINT, signal_handler2);
	}
}

void	hd_sig(int signal)
{
	exit(1);
}

void	set_terminal(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}
