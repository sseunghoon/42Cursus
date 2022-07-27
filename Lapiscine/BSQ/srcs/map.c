/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:50:59 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/05 21:51:02 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdlib.h>

int	init_map(t_bsq_map *self, t_file_lines *lines)
{
	t_string_chain	*chain;
	int				y;

	chain = lines->head;
	if (!chain || !read_first_line(self, chain->str) || !check_double(self))
		return (FALSE);
	chain = chain->next;
	if (!chain)
		return (FALSE);
	self->width = ft_strlen(chain->str);
	self->box = ft_malloc(sizeof(*self->box) * self->width * self->height);
	y = 0;
	while (chain && *chain->str)
	{
		if (y >= self->height || !cast_line(self, chain->str, y))
			return (FALSE);
		y++;
		chain = chain->next;
	}
	if (!chain || chain->next || y < self->height)
		return (FALSE);
	return (TRUE);
}

int	read_first_line(t_bsq_map *self, char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str) - CHAR_NO;
	if (len <= 0)
		return (FALSE);
	i = 0;
	while (i < len)
	{
		if (str[i] < '0' || str[i] > '9')
			return (FALSE);
		self->height = 10 * self->height + (str[i++] - '0');
	}
	i = 0;
	while (i < CHAR_NO)
	{
		if (!ft_isprintable(str[len + i]))
			return (FALSE);
		self->chars[i] = str[len + i];
		i++;
	}
	return (TRUE);
}

int	check_double(t_bsq_map *self)
{
	int	i;
	int	j;

	if (self->height < 1)
		return (FALSE);
	i = 0;
	while (i < CHAR_NO)
	{
		j = 0;
		while (j < CHAR_NO)
		{
			if (i != j && self->chars[i] == self->chars[j])
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	cast_line(t_bsq_map *self, char *str, int y)
{
	int		x;
	char	value;

	if (self->width != ft_strlen(str))
		return (FALSE);
	x = 0;
	while (str[x])
	{
		if (str[x] == self->chars[EMPTY])
			value = 1;
		else if (str[x] == self->chars[OBSTACLE])
			value = 0;
		else
			return (FALSE);
		*get_at(self, x, y) = value;
		x++;
	}
	return (TRUE);
}

char	*get_at(t_bsq_map *self, int x, int y)
{
	char	*p;

	p = &self->box[x + self->width * y];
	return (p);
}
