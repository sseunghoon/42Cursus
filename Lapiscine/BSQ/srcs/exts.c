/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:50:12 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/06 22:27:02 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <unistd.h>
#include <fcntl.h>

int	read_lines_from_path(t_file_lines *self, char *path)
{
	int	fd;
	int	result;

	if (path != NULL)
	{
		fd = open(path, O_RDONLY);
		if (fd == -1)
			return (FALSE);
	}
	else
		fd = STDIN_FILENO;
	result = read_lines(self, fd);
	if (fd != STDIN_FILENO)
		close(fd);
	return (result);
}

char	min(char a, char b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

t_bsq_map	*calc_map(t_bsq_map *self)
{
	int	x;
	int	y;
	int	r;

	y = 1;
	while (y < self->height)
	{
		x = 1;
		while (x < self->width)
		{
			if (*get_at(self, x, y))
			{
				r = min(*get_at(self, x - 1, y - 1), *get_at(self, x, y - 1));
				r = min(*get_at(self, x - 1, y), r);
				*get_at(self, x, y) = 1 + r;
			}
			x++;
		}
		y++;
	}
	return (self);
}

t_resolve	find_max(t_bsq_map *self)
{
	t_resolve	max;
	int			x;
	int			y;
	int			r;

	max.r = 0;
	y = 0;
	while (y < self->height)
	{
		x = 0;
		while (x < self->width)
		{
			r = *get_at(self, x, y);
			if (r > max.r)
			{
				max.x = x;
				max.y = y;
				max.r = r;
			}
			x++;
		}
		y++;
	}
	return (max);
}

int	ft_boundary(t_resolve *sol, int x, int y)
{
	int	left;
	int	right;
	int	top;
	int	bottom;

	left = sol->x - sol->r;
	right = sol->x;
	top = sol->y - sol->r;
	bottom = sol->y;
	if (x <= left || x > right)
		return (0);
	if (y <= top || y > bottom)
		return (0);
	return (1);
}
