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

void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf("Error\n");
		exit(1);
	}
	init_deque(a, b);
	receive_input(a, argc, argv);
}

void	init_buff(char *buff)
{
	int	i;

	i = 0;
	while (i < 100)
	{
		buff[i] = '\0';
		i++;
	}
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

void	print_deq(t_deque *a)
{
	int i = 0;
	t_node *p;

	p = a->top;
	while (i < a->size)
	{
		ft_printf("%d\n", p->data);
		p = p->next;
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;
	char	**commands;

	parse_argument(&a, &b, argc, argv);
	commands = read_commands();
	execute_commands(&a, &b, commands);
	if (check_sorted(&a, &b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	// print_deq(&a);
	
	return (0);
}

// 중복