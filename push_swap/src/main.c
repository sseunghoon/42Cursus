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

void	swap(t_deq *d)
{
	t_node	*p;
	t_node	*q;

	p = d->top;
	q = d->top->next;
	if (p == NULL || q == NULL)
		return ;
	if (q == d->bot)
	{
		p->next = NULL;
		d->top = q;
		d->bot = p;
	}
	else
		p->next = q->next;
	q->prev = NULL;
	q->next = p;
	p->prev = q;
	ft_printf("s%c\n", d->name);
}

void	push(t_deq *x, t_deq *y)
{
	if (y->top == NULL)
		return ;
	
	
}

void	add_deq(t_deq *x, int data)
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
}

t_node	*pop_deq(t_deq *x)
{
	t_node	*p;

	p = x->top;
	if (p == NULL)
		return (NULL);
	
}

// 1번 ./push_swap 1 4 9 -25 13 //  각 인자는 하나의 수를 나타냄
// 2번 ./push_swap "1 5 2 3"   // 공백으로 수가 구분된 하나의 문자열 인자
// 3번 ./push_swap "3 2" 42 11 "21 -2 7" "5"  // 1번과 2번의 혼합
// 1번까지만 하고 bash 와 zsh 에서의 $ARG의 차이를 설명하여 디펜스하거나
// split하고, ft_atoi를 조금 개조해서 
// (+/- 하나까지만 봐주고, 이후부터는 ft_isdigit으로 검사(false면 exit)하면서 변환)
void	parse_argument(t_deq *a, t_deq *b, int argc, char **argv)
{
	char	**p;
	int		i;

	if (argc == 2)
	{
		p = ft_split(argv[1], ' ');
		while (*p)
		{
			add_deq(a, ft_atoi(*p));
			p++;
		}
	}
	else
	{
		i = 0;
		while (++i < argc)
			add_deq(a, ft_atoi(argv[i]));
	}
	a->top == NULL;
	a->bot == NULL;
	b->top == NULL;
	b->bot == NULL;
	a->name = 'a';
	b->name = 'b';
}

int	main(int argc, char **argv)
{
	t_deq a;
	t_deq b;

	parse_argument(&a, argc, argv);
}