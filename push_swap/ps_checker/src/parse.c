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

#include "../include/checker.h"

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
