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

void	add_top(t_deque *x, t_node *new_node)
{
	t_node	*p;

	p = x->top;
	x->top = new_node;
	new_node->next = p;
	x->size++;
	if (p == NULL)
	{
		x->bot = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
		return ;
	}
	new_node->prev = x->bot;
	p->prev = new_node;
	x->bot->next = x->top;
}

void	add_bot(t_deque *x, t_node *new_node)
{
	t_node	*p;

	p = x->bot;
	x->bot = new_node;
	new_node->prev = p;
	x->size++;
	if (p == NULL)
	{
		x->top = new_node;
		new_node->prev = new_node;
		new_node->next = new_node;
		return ;
	}
	new_node->next = x->top;
	p->next = new_node;
	x->top->prev = x->bot;
}

t_node	*pop_top(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = x->top;
	if (p == NULL)
		return (NULL);
	q = p->next;
	p->prev = NULL;
	p->next = NULL;
	x->top = q;
	x->size--;
	if (q == NULL || p == q)
	{
		x->top = NULL;
		x->bot = NULL;
		return (p);
	}
	q->prev = x->bot;
	x->bot->next = q;
	return (p);
}

t_node	*pop_bot(t_deque *x)
{
	t_node	*p;
	t_node	*q;

	p = x->bot;
	if (p == NULL)
		return (NULL);
	q = p->prev;
	p->prev = NULL;
	p->next = NULL;
	x->bot = q;
	x->size--;
	if (q == NULL || p == q)
	{
		x->top = NULL;
		x->bot = NULL;
		return (p);
	}
	q->next = x->top;
	x->top->prev = q;
	return (p);
}
