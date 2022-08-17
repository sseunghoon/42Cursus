/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:18:59 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/28 23:18:59 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	execute_commands(t_deque *a, t_deque *b, char **commands)
{
	char	**p;

	if (commands == NULL)
		return ;
	p = commands;
	while (*commands)
	{
		if (classify_command(a, b, *commands) == -1)
		{
			ft_print_err("Error\n");
			exit(1);
		}
		free(*commands);
		commands++;
	}
	free(p);
}

void	swap(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = pop_top(x);
	q = pop_top(x);
	if (p == NULL)
		return ;
	add_top(x, p);
	if (q == NULL)
		return ;
	add_top(x, q);
}

void	swap_both(t_deque *x, t_deque *y)
{
	t_node	*p;
	t_node	*q;

	p = pop_top(x);
	q = pop_top(x);
	if (p == NULL)
		return ;
	add_top(x, p);
	if (q == NULL)
		return ;
	add_top(x, q);
	p = pop_top(y);
	q = pop_top(y);
	if (p == NULL)
		return ;
	add_top(y, p);
	if (q == NULL)
		return ;
	add_top(y, q);
}

void	push(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_top(y);
	if (p == NULL)
		return ;
	add_top(x, p);
}
