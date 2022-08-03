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
		new_node->next = NULL;
		x->bot = new_node;
	}
	x->size++;
}

void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv)
{
	char	**p;
	int		i;

	a->top = NULL;
	a->bot = NULL;
	b->top = NULL;
	b->bot = NULL;
	a->size = 0;
	b->size = 0;
	a->name = 'a';
	b->name = 'b';
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
			p++;
		}
	}
	else
	{
		i = 0;
		while (++i < argc)
			append_data(a, ft_atoi(argv[i]));
	}
}

void	divide_3part(t_deque *a, t_deque *b)
{
	int	pivot1;
	int	pivot2;
	int	cnt;

	pivot1 = a->top->data;
	pivot2 = a->bot->data;
	cnt = a->size;
	while (cnt)
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
	{
		push(b, a);
	}
}

void	print_deque(t_deque *x)
{
	t_node	*p;

	p = x->top;
	while (p)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
}

int	find_dest(t_deque *a, t_node *src)
{
	t_node	*p;
	int		dest;

	if (src->data < a->top->data)
		return (0);
	p = a->top->next;
	dest = 1;
	while (p)
	{
		if (p->prev->data < src->data && src->data < p->data)
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

void	greedy(t_deque *a, t_deque *b)
{
	int	dest;
	int	sttp;

	while (b->size)
	{
		get_best_loc(a, b, &dest, &sttp);
	}
}

int	main(int argc, char **argv)
{
	t_deque a;
	t_deque b;

	parse_argument(&a, &b, argc, argv);
	divide_3part(&a, &b);
	greedy(&a, &b);
}
