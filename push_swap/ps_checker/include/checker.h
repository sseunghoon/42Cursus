/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 22:29:46 by seunghso          #+#    #+#             */
/*   Updated: 2022/08/09 22:29:46 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/include/get_next_line.h"
# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct t_deque
{
	t_node	*top;
	t_node	*bot;
	char	name;
	int		size;
}	t_deque;

// push_swap.c
void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv);
int		check_sorted(t_deque *a, t_deque *b);
void	init_deque(t_deque *a, t_deque *b);

// command.c
void	execute_commands(t_deque *a, t_deque *b, char **commands);
void	swap(t_deque *d);
void	swap_both(t_deque *x, t_deque *y);
void	push(t_deque *x, t_deque *y);

// command2.c
void	rotate(t_deque *x);
void	rotate_both(t_deque *x, t_deque *y);
void	reverse_rotate(t_deque *x);
void	reverse_rotate_both(t_deque *x, t_deque *y);

// utils.c
void	add_top(t_deque *x, t_node *new_node);
void	add_bot(t_deque *x, t_node *new_node);
t_node	*pop_top(t_deque *x);
t_node	*pop_bot(t_deque *x);

// parse.c
void	receive_input(t_deque *a, int argc, char **argv);
void	append_data(t_deque *x, int data);
char	**read_commands(void);
int		classify_command(t_deque *a, t_deque *b, char *command);

// etc.c
void	ft_swap(int *a, int *b);
void	change_to_idx(t_deque *a);
int		binary_search(int *arr, int data, int left, int right);
void	quick_sort(int *arr, int left, int right);
void	init_arr(int **arr, int **dup_ck, t_deque *a);

#endif