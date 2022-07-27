/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:48:54 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/05 21:49:00 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdlib.h>

void	*ft_malloc(unsigned int size)
{
	void	*result;

	result = malloc(size);
	if (result == NULL)
		exit(EXIT_FAILURE);
	return (result);
}

t_file_lines	*malloc_lines(void)
{
	t_file_lines	*self;

	self = ft_malloc(sizeof(t_file_lines));
	self->head = NULL;
	self->tail = NULL;
	return (self);
}

t_bsq_map	*bsq_map_malloc(void)
{
	t_bsq_map	*self;
	int			i;

	self = ft_malloc(sizeof(t_bsq_map));
	self->box = NULL;
	self->width = 0;
	self->height = 0;
	i = 0;
	while (i < CHAR_NO)
		self->chars[i++] = '\0';
	return (self);
}
