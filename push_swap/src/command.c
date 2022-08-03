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

void	swap(t_deque *d)
{
	t_node	*p;
	t_node	*q;

	p = d->top;
	q = d->top->next;
	if (p == NULL || q == NULL)
		return ;
	if (q == d->bot)
	{
		p->next = NULL;
		d->top = q;
		d->bot = p;
	}
	else
		p->next = q->next;
	q->prev = NULL;
	q->next = p;
	p->prev = q;
}

void	push(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop(y);
	if (p == NULL)
		return ;
	add_top(x, p);
}

void	rotate(t_deque *x)
{
	t_node	*p;

	p = pop_top(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_bot(x, p);
}

void	reverse_rotate(t_deque *x)
{
	t_node	*p;

	p = pop_bot(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_top(x, p);
}
