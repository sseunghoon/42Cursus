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

# ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/libft.h"

typedef struct s_node
{
	int				data;
	struct	s_node	*next;
	struct	s_node	*prev;
}	t_node;

typedef struct t_deque
{
	t_node	*top;
	t_node	*bot;
	char	name;
	int		size;
}	t_deque;

// command.c
void	swap(t_deque *d);
void	push(t_deque *x, t_deque *y);
void	rotate(t_deque *x);
void	reverse_rotate(t_deque *x);

// utils.c
void	add_top(t_deque *x, t_node *new_node);
void	add_bot(t_deque *x, t_node *new_node);
t_node	*pop_top(t_deque *x);
t_node	*pop_bot(t_deque *x);

// push_swap.c
void	append_data(t_deque *x, int data);
void	parse_argument(t_deque *a, t_deque *b, int argc, char **argv);

# endif