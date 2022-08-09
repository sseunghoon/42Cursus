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
#include <stdio.h>

void	get_best_loc(t_deque *a, t_deque *b, int *dest, int *sttp)
{
	int		i;
	int		tmp_dest;
	int		tmp_sttp;
	t_node	*p;

	i = 0;
	p = b->top;
	while (i < b->size)
	{
		tmp_dest = find_dest(a, p);
		tmp_sttp = i;
		if (tmp_sttp > b->size / 2)
			tmp_sttp = i - b->size;
		if (i == 0 || is_better(tmp_dest, tmp_sttp, *dest, *sttp))
		{
			*dest = tmp_dest;
			*sttp = tmp_sttp;
		}
		p = p->next;
		i++;
	}
}

int	is_better(int tmp_dest, int tmp_sttp, int dest, int sttp)
{
	int	cnt;
	int	tmp_cnt;

	tmp_cnt = ft_abs(tmp_dest) + ft_abs(tmp_sttp);
	cnt = ft_abs(dest) + ft_abs(sttp);
	if (tmp_cnt < cnt)
		return (1);
	return (0);
}

void	greedy_rotate(t_deque *a, t_deque *b, int dest, int sttp)
{
	if (dest == sttp)
	{
		while (dest > 0)
		{
			rotate_both(a, b);
			dest--;
		}
		while (dest++ < 0)
			reverse_rotate_both(a, b);
		return ;
	}
	while (dest > 0)
	{
		rotate(a);
		dest--;
	}
	while (dest++ < 0)
		reverse_rotate(a);
	while (sttp > 0)
	{
		rotate(b);
		sttp--;
	}
	while (sttp++ < 0)
		reverse_rotate(b);
}

void	last_rotate(t_deque *a)
{
	int		turning_point;
	t_node	*p;

	turning_point = 1;
	p = a->top;
	while (turning_point < a->size)
	{
		if (p->data > p->next->data)
			break ;
		turning_point++;
		p = p->next;
	}
	if (turning_point >= a->size / 2)
	{
		while (a->bot->data < a->top->data)
			reverse_rotate(a);
	}
	else
	{
		while (a->bot->data < a->top->data)
			rotate(a);
	}
}

int	find_dest(t_deque *a, t_node *src)
{
	t_node	*p;
	int		dest;

	p = a->top;
	dest = 0;
	while (p)
	{
		if (p->prev->data > src->data && \
			p->data > src->data && p->prev->data > p->data)
			break ;
		if (p->prev->data < src->data && \
			p->data > src->data && p->prev->data < p->data)
			break ;
		if (p->prev->data < src->data && \
			p->data < src->data && p->prev->data > p->data)
			break ;
		p = p->next;
		dest++;
	}
	if (dest > a->size / 2)
		dest = dest - a->size;
	return (dest);
}
