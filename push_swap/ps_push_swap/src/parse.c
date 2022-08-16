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

void	change_to_idx(t_deque *a)
{
	int		*arr;
	int		*dup_ck;
	int		i;
	t_node	*p;

	init_arr(&arr, &dup_ck, a);
	quick_sort(arr, 0, a->size - 1);
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		p->data = binary_search(arr, p->data, 0, a->size - 1);
		if (dup_ck[p->data] == 0)
			dup_ck[p->data] = 1;
		else
		{
			ft_print_err("Error\n");
			exit(1);
		}
		p = p->next;
		i++;
	}
	free(arr);
	free(dup_ck);
}

void	receive_input(t_deque *a, int argc, char **argv)
{
	char	**p;
	char	**save_p;
	int		i;

	if (argc == 2)
	{
		p = ft_split(argv[1], ' ');
		save_p = p;
		while (*p)
		{
			append_data(a, ft_atoi(*p));
			free(*p);
			p++;
		}
		free(save_p);
	}
	else
	{
		i = 0;
		while (++i < argc)
			append_data(a, ft_atoi(argv[i]));
	}
}

void	append_data(t_deque *x, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (new_node == NULL)
		exit(1);
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->data = data;
	if (!(x->top))
	{
		x->top = new_node;
		x->bot = new_node;
	}
	else
	{
		x->bot->next = new_node;
		new_node->prev = x->bot;
		new_node->next = x->top;
		x->top->prev = new_node;
		x->bot = new_node;
	}
	x->size++;
}

int	binary_search(int *arr, int data, int left, int right)
{
	int	mid;

	mid = (left + right) / 2;
	if (arr[mid] < data)
		return (binary_search(arr, data, mid + 1, right));
	else if (arr[mid] > data)
		return (binary_search(arr, data, left, mid - 1));
	else
		return (mid);
}

void	quick_sort(int *arr, int left, int right)
{
	int	l;
	int	r;
	int	pivot;

	l = left;
	r = right;
	pivot = arr[(left + right) / 2];
	while (l <= r)
	{
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l <= r)
		{
			ft_swap(arr + l, arr + r);
			l++;
			r--;
		}
	}
	if (left < r)
		quick_sort(arr, left, r);
	if (right > l)
		quick_sort(arr, l, right);
}
