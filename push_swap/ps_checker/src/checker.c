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

char	**read_commands()
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
		push(b, b);
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

void	execute_commands(t_deque *a, t_deque *b, char **commands)
{
	char	*p;

	p = *commands;
	while (*commands)
	{
		classify_command(a, b, *commands);
		commands++;
	}
}

int	check_sorted(t_deque *a, t_deque *b)
{
	int		i;
	t_node	*p;

	if (b->size)
		return (0);
	p = a->top;
	while (i < a->size - 1)
	{
		if (p->data > p->next->data)
			return (0);
		i++;
		p = p->next;
	}
	return (1);
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
	return (0);
}
