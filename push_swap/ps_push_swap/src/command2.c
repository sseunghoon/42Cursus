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
	ft_printf("r%c\n", x->name);
}

void	rotate_both(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_top(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_bot(x, p);
	p = pop_top(y);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_bot(y, p);
	ft_printf("rr\n");
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
	ft_printf("rr%c\n", x->name);
}

void	reverse_rotate_both(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_bot(x);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_top(x, p);
	p = pop_bot(y);
	if (p == NULL)
	{
		ft_printf("Empty deque\n");
		exit(0);
	}
	add_top(y, p);
	ft_printf("rrr\n");
}
