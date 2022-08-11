/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:34:40 by seunghso          #+#    #+#             */
/*   Updated: 2022/08/09 22:34:40 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_just3(t_deque *a)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = a->top->data;
	n2 = a->top->next->data;
	n3 = a->bot->data;
	if (n1 > n2 && n2 < n3 && n1 < n3)
		swap(a);
	if (n1 > n2 && n2 > n3 && n1 > n3)
	{
		swap(a);
		reverse_rotate(a);
	}
	if (n1 > n2 && n2 < n3 && n1 > n3)
		rotate(a);
	if (n1 < n2 && n2 > n3 && n1 < n3)
	{
		swap(a);
		rotate(a);
	}
	if (n1 < n2 && n2 > n3 && n1 > n3)
		reverse_rotate(a);
}

void	divide_3part(t_deque *a, t_deque *b, int pivot1, int pivot2)
{
	int	cnt;

	if (a->size > 10)
	{
		pivot1 = a->size / 3 * 1;
		pivot2 = a->size / 3 * 2;
		cnt = a->size;
		while (cnt && a->size > 3)
		{
			if (a->top->data <= pivot1)
			{
				push(b, a);
				rotate(b);
			}
			else if (a->top->data <= pivot2)
				push(b, a);
			else
				rotate(a);
			cnt--;
		}
	}
	while (a->size > 3)
		push(b, a);
	if (a->size == 3)
		sort_just3(a);
}

void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	init_deque(a, b);
	receive_input(a, argc, argv);
	change_to_idx(a);
	if (check_sorted(a, b))
		exit(0);
}

void	greedy(t_deque *a, t_deque *b)
{
	int	dest;
	int	sttp;

	while (b->size)
	{
		get_best_loc(a, b, &dest, &sttp);
		greedy_rotate(a, b, dest, sttp);
		push(a, b);
	}
	last_rotate(a);
}

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;

	parse_argument(&a, &b, argc, argv);
	divide_3part(&a, &b, a.size / 3 * 1, a.size / 3 * 2);
	greedy(&a, &b);
}
