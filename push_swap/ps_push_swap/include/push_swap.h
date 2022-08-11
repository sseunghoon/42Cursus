/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 23:29:53 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/28 23:29:53 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
void	divide_3part(t_deque *a, t_deque *b, int pivot1, int pivot2);
void	sort_just3(t_deque *a);
void	greedy(t_deque *a, t_deque *b);

// command.c
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

// greedy.c
void	get_best_loc(t_deque *a, t_deque *b, int *dest, int *sttp);
int		is_better(int tmp_dest, int tmp_sttp, int dest, int sttp);
void	greedy_rotate(t_deque *a, t_deque *b, int dest, int sttp);
void	last_rotate(t_deque *a);
int		find_dest(t_deque *a, t_node *src);

// parse.c
void	change_to_idx(t_deque *a);
void	receive_input(t_deque *a, int argc, char **argv);
void	append_data(t_deque *x, int data);
int		binary_search(int *arr, int data, int left, int right);
void	quick_sort(int *arr, int left, int right);

// etc.c
void	ft_swap(int *a, int *b);
void	init_arr(int **arr, int **dup_ck, t_deque *a);
void	init_deque(t_deque *a, t_deque *b);
int		check_sorted(t_deque *a, t_deque *b);

#endif