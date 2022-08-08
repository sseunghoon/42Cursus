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
	while (l < r)
	{
		while (arr[l] < pivot)
			l++;
		while (arr[r] > pivot)
			r--;
		if (l < r)
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

int	find_idx(int *arr, int data, int left, int right)
{
	int	mid = (left+ right) / 2;
	if (arr[mid] == data)
		return (mid);
}

void	change_to_idx(t_deque *a)
{
	// 중복 발견 시 에러 출력
	// 이진 탐색으로 인덱싱
	int		*arr;
	int		i;
	t_node	*p;

	arr = malloc(sizeof(int) * a->size);
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		arr[i] = p->data;
		p = p->next;
		i++;
	}
	quick_sort(arr, 0, a->size - 1);
	p = a->top;
	i = 0;
	while (i < a->size)
	{
		p->data = binary_search(arr, p->data, 0, a->size - 1);
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
	int		i;

	if (argc == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	if (argc == 2)
	{
		p = ft_split(argv[1], ' ');
		while (*p)
		{
			append_data(a, ft_atoi(*p));
			free(*p);
			p++;
		}
		free(p);
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

	pivot1 = a->top->data;
	pivot2 = a->bot->data;
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
	while (a->size > 3)
		push(b, a);
	sort_just3(a);
	// print_deque(a);
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
		{
			// printf("break1\n");
			break ;
		}
		if (p->prev->data < src->data && p->data > src->data && p->prev->data < p->data)
		{
			// printf("break2\n");
			break ;
		}
		if (p->prev->data < src->data && p->data < src->data && p->prev->data > p->data)
		{
			// printf("prev: %d\n", p->prev->data);
			// printf("next: %d\n", p->next->data);
			// printf("p: %d\n", p->data);
			// printf("src: %d\n", src->data);
			// printf("break3\n");
			break ;
		}
		p = p->next;
		dest++;
		// printf("test: %d\n", p->data);
	}
	// printf("dst: %d\n", dest);
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

void	integrated_rotate(t_deque *a, t_deque *b, int dest, int sttp)
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

void	greedy(t_deque *a, t_deque *b)
{
	int	dest;
	int	sttp;

	while (b->size)
	{
		get_best_loc(a, b, &dest, &sttp);
		integrated_rotate(a, b, dest, sttp);
		push(a,b);
		// print_deque(a); 
	}
	while (a->bot->data < a->top->data)
	{
		reverse_rotate(a);
	}
}

int	main(int argc, char **argv)
{
	t_deque a;
	t_deque b;

	parse_argument(&a, &b, argc, argv);
	divide_3part(&a, &b);
	// 피봇 선택 크기의 3분의 1, 3분의 2 하면 되서 따로 저장할 필요 없음
	greedy(&a, &b);
}
