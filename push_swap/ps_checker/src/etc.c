/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:34:23 by seunghso          #+#    #+#             */
/*   Updated: 2022/08/09 22:34:23 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
