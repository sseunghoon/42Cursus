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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	init_arr(int **arr, int **dup_ck, t_deque *a)
{
	t_node	*p;
	int		i;

	*arr = malloc(sizeof(int) * a->size);
	*dup_ck = malloc(sizeof(int) * a->size);
	if (arr == NULL || dup_ck == NULL)
		exit(1);
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		(*arr)[i] = p->data;
		(*dup_ck)[i] = 0;
		p = p->next;
		i++;
	}
}

void	init_deque(t_deque *a, t_deque *b)
{
	a->top = NULL;
	a->bot = NULL;
	b->top = NULL;
	b->bot = NULL;
	a->size = 0;
	b->size = 0;
	a->name = 'a';
	b->name = 'b';
}

int	check_sorted(t_deque *a, t_deque *b)
{
	int		i;
	t_node	*p;

	if (b->size)
		return (0);
	p = a->top;
	i = 0;
	while (i < a->size - 1)
	{
		if (p->data > p->next->data)
			return (0);
		i++;
		p = p->next;
	}
	return (1);
}
