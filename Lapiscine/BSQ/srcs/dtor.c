/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:49:49 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/05 21:49:53 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdlib.h>

void	free_lines(t_file_lines *self)
{
	t_string_chain	*elem;
	t_string_chain	*next;

	if (self == NULL)
		return ;
	elem = self->head;
	while (elem)
	{
		free(elem->str);
		next = elem->next;
		free(elem);
		elem = next;
	}
	self->head = NULL;
	self->tail = NULL;
	free(self);
}

void	bsq_map_free(t_bsq_map *self)
{
	if (self == NULL)
		return ;
	free(self->box);
	self->box = NULL;
	free(self);
}
