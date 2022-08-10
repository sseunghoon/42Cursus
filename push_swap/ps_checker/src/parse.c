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

char	**read_commands(void)
{
	char	*commands;
	char	*tmp;
	char	buff[100];
	char	**result;
	int		read_val;

	tmp = malloc(sizeof(char));
	*tmp = '\0';
	read_val = 1;
	while (read_val)
	{
		init_buff(buff);
		read_val = read(1, buff, 100);
		if (read_val == -1)
		{
			ft_printf("Error\n");
			exit(1);
		}
		commands = ft_strjoin(tmp, buff);
		free(tmp);
		tmp = commands;
	}
	result = ft_split(commands, '\n');
	free(commands);
	return (result);
}

void	classify_command(t_deque *a, t_deque *b, char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		swap(a);
	if (ft_strcmp(command, "sb") == 0)
		swap(b);
	if (ft_strcmp(command, "ss") == 0)
		swap_both(a, b);
	if (ft_strcmp(command, "pa") == 0)
		push(a, b);
	if (ft_strcmp(command, "pb") == 0)
		push(b, a);
	if (ft_strcmp(command, "ra") == 0)
		rotate(a);
	if (ft_strcmp(command, "rb") == 0)
		rotate(b);
	if (ft_strcmp(command, "rr") == 0)
		rotate_both(a, b);
	if (ft_strcmp(command, "rra") == 0)
		reverse_rotate(a);
	if (ft_strcmp(command, "rrb") == 0)
		reverse_rotate(b);
	if (ft_strcmp(command, "rrr") == 0)
		reverse_rotate_both(a, b);
}
