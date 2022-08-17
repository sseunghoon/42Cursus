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

#include "../include/push_swap.h"

void	swap(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = pop_top(x);
	q = pop_top(x);
	add_top(x, p);
	add_top(x, q);
	ft_printf("s%c\n", x->name);
}

void	swap_both(t_deque *x, t_deque *y)
{
	t_node	*p;
	t_node	*q;

	p = pop_top(x);
	q = pop_top(x);
	add_top(x, p);
	add_top(x, q);
	p = pop_top(y);
	q = pop_top(y);
	add_top(y, p);
	add_top(y, q);
	ft_printf("ss\n");
}

void	push(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_top(y);
	if (p == NULL)
		return ;
	add_top(x, p);
	ft_printf("p%c\n", x->name);
}
