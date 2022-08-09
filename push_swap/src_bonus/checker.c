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

#include "../include_bonus/checker.h"

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

int	main(int argc, char **argv)
{
	t_deque	a;
	t_deque	b;
	char	**commands;

	parse_argument(&a, &b, argc, argv);
	commands = read_commands();
	execute_commands(&a, &b, commands);
	check_sorted(&a, &b);
	// 100 buffer 씩 계속 읽는다
	// 읽은 버퍼들을 전부 저장한다. (합친다)
	// read 반환 값이 0 이 되면 멈춘다.
	// 지금까지 읽은 것들을 ft_split('\n')한다.
	// 명령 하나하나 실행하고
	// 끝났을 때, 정렬이 잘 되어있는지 확인한다.
}
