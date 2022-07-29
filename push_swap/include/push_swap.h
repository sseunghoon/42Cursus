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

typedef struct s_deq
{
	t_node	*top;
	t_node	*bot;
	char	name;
}	t_deq;

# endif