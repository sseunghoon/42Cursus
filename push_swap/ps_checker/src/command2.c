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

void	rotate(t_deque *x)
{
	t_node	*p;

	p = pop_top(x);
	if (p == NULL)
		return ;
	add_bot(x, p);
}

void	rotate_both(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_top(x);
	if (p == NULL)
		return ;
	add_bot(x, p);
	p = pop_top(y);
	if (p == NULL)
		return ;
	add_bot(y, p);
}

void	reverse_rotate(t_deque *x)
{
	t_node	*p;

	p = pop_bot(x);
	if (p == NULL)
		return ;
	add_top(x, p);
}

void	reverse_rotate_both(t_deque *x, t_deque *y)
{
	t_node	*p;

	p = pop_bot(x);
	if (p == NULL)
		return ;
	add_top(x, p);
	p = pop_bot(y);
	if (p == NULL)
		return ;
	add_top(y, p);
}
