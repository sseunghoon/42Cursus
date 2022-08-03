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
	a->top = NULL;
	a->bot = NULL;
	b->top = NULL;
	b->bot = NULL;
	a->name = 'a';
	b->name = 'b';
	a->size = 0;
	b->size = 0;
}

void	divide_3part(t_deque *a, t_deque *b)
{
	int	pivot1;
	int	pivot2;

	pivot1 = a->top->data;
	pivot2 = a->bot->data;
	while (a->size)
	{
		if (a->top->data < pivot1)
		{
			push(b, a);
			rotate(b);
		}
		else if (a->top->data < pivot2)
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

int	main(int argc, char **argv)
{
	t_deque a;
	t_deque b;

	parse_argument(&a, &b, argc, argv);
	divide_3part(&a, &b);
	print_deque(&b);
}
