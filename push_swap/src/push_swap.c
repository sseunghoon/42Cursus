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

void	print_deque(t_deque *x)
{
	t_node	*p;

	p = x->top;
	while (p)
	{
		printf("%d\n", p->data);
		if (p == x->bot)
			break ;
		p = p->next;
	}
	printf("\n");
}

void	append_data(t_deque *x, int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
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

void	quick_sort(int *arr, int left, int right)
{
	int	l;
	int	r;
	int	pivot;
	int	tmp;

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
			tmp = arr[l];
			arr[l] = arr[r];
			arr[r] = tmp;
			l++;
			r--;
		}
	}
	if (left < r)
		quick_sort(arr, left, r);
	if (right > l)
		quick_sort(arr, l, right);
}

int	binary_search(int *arr, int data, int left, int right)
{
	int	mid = (left+ right) / 2;

	if (arr[mid] < data)
		return (binary_search(arr, data, mid + 1, right));
	else if (arr[mid] > data)
		return (binary_search(arr, data, left, mid - 1));
	else
		return (mid);
}

void	change_to_idx(t_deque *a)
{
	int		*arr;
	int		*dup_ck;
	int		i;
	t_node	*p;

	arr = malloc(sizeof(int) * a->size);
	dup_ck = malloc(sizeof(int) * a->size);
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		arr[i] = p->data;
		dup_ck[i] = 0;
		p = p->next;
		i++;
	}
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
			ft_printf("Error\n");
			exit(1);
		}
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

void	receive_input(t_deque *a, int argc, char **argv)
{
	char	**p;
	char	**save_p;
	int		i;

	if (argc == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
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

void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv)
{
	init_deque(a, b);
	receive_input(a, argc, argv);
	change_to_idx(a);
}

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

void	divide_3part(t_deque *a, t_deque *b)
{
	int	pivot1;
	int	pivot2;
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

int	find_dest(t_deque *a, t_node *src)
{
	t_node	*p;
	int		dest;

	p = a->top;
	dest = 0;
	while (p)
	{
		if (p->prev->data > src->data && p->data > src->data && p->prev->data > p->data)
			break ;
		if (p->prev->data < src->data && p->data > src->data && p->prev->data < p->data)
			break ;
		if (p->prev->data < src->data && p->data < src->data && p->prev->data > p->data)
			break ;
		p = p->next;
		dest++;
	}
	if (dest > a->size / 2)
		dest = dest - a->size;
	return (dest);
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

void	best_rotate(t_deque *a, t_deque *b, int dest, int sttp)
{
	if (dest == sttp)
	{
		while (dest > 0)
		{
			rotate_both(a, b);
			dest--;
		}
		while (dest < 0)
		{
			reverse_rotate_both(a, b);
			dest++;
		}
		return ;
	}
	while (dest > 0)
	{
		rotate(a);
		dest--;
	}
	while (dest < 0)
	{
		reverse_rotate(a);
		dest++;
	}
	while (sttp > 0)
	{
		rotate(b);
		sttp--;
	}
	while (sttp < 0)
	{
		reverse_rotate(b);
		sttp++;
	}
}

void	last_rotate(t_deque *a)
{
	int		turning_point;
	t_node *p;

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

void	greedy(t_deque *a, t_deque *b)
{
	int	dest;
	int	sttp;

	while (b->size)
	{
		get_best_loc(a, b, &dest, &sttp);
		best_rotate(a, b, dest, sttp);
		push(a,b);
	}
	last_rotate(a);
}

int	main(int argc, char **argv)
{
	t_deque a;
	t_deque b;

	parse_argument(&a, &b, argc, argv);
	divide_3part(&a, &b);
	// printf("=========\n");
	greedy(&a, &b);
	// print_deque(&a);
}
