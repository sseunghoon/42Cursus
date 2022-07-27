/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   app.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 11:15:25 by seunghso          #+#    #+#             */
/*   Updated: 2022/06/05 17:31:38 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

#include <stdlib.h>
#include <unistd.h>

void	write_map(char *rst_map, t_bsq_map *map, t_resolve *sol)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (ft_boundary(sol, x, y))
				rst_map = ft_insert_char(rst_map, map->chars[FULL]);
			else if (*get_at(map, x, y))
				rst_map = ft_insert_char(rst_map, map->chars[EMPTY]);
			else
				rst_map = ft_insert_char(rst_map, map->chars[OBSTACLE]);
			x++;
		}
		rst_map = ft_insert_char(rst_map, '\n');
		y++;
	}
	rst_map = ft_insert_char(rst_map, '\0');
}

void	exc_bsq(t_file_lines *lines)
{
	t_bsq_map		*map;
	t_resolve		sol;
	unsigned int	len;
	char			*rst_map;

	map = bsq_map_malloc();
	if (init_map(map, lines))
	{
		sol = find_max(calc_map(map));
		len = sizeof(char) * ((map->width + 1) * map->height + 1);
		rst_map = ft_malloc(len);
		write_map(rst_map, map, &sol);
		ft_putstr(1, rst_map);
		free(rst_map);
	}
	else
		ft_putstr(2, ERROR_MSG);
	bsq_map_free(map);
}

int	handle_path(char *path)
{
	t_file_lines	*lines;
	int				result;

	lines = malloc_lines();
	result = 0;
	if (read_lines_from_path(lines, path))
	{
		exc_bsq(lines);
		result = 1;
	}
	else
		ft_putstr(2, ERROR_MSG);
	free_lines(lines);
	return (result);
}

int	main(int argc, char **argv)
{
	int	idx;
	int	i;

	if (argc > 1)
	{
		idx = 0;
		i = 1;
		while (i < argc)
		{
			if (idx)
				ft_putstr(1, "\n");
			idx = handle_path(argv[i]);
			i++;
		}
	}
	else
		(void)handle_path(NULL);
	return (0);
}
