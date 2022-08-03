/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:42:45 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/27 14:59:22 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	check_tile1(t_game *game, t_mapinfo *mapinfo, int i)
{
	if (i / mapinfo->width == 0 || i / mapinfo->width == mapinfo->height -1 || \
		i % mapinfo->width == 0 || i % mapinfo->width == mapinfo->width -1)
	{
		if (mapinfo->map[i] != '1')
			print_err("Invalid map: Invalid Wall\n");
	}
	else if (mapinfo->map[i] == 'C')
		mapinfo->cltb_cnt++;
	else if (mapinfo->map[i] == 'P')
	{
		if (game->play_info.player_loc == -1)
			game->play_info.player_loc = i;
		else
			print_err("Invalid map: Too Many Starting Point\n");
	}
}

void	check_tile2(t_game *game, t_mapinfo *mapinfo, int i)
{
	if (mapinfo->map[i] == 'M')
	{
		if (game->play_info.patrol_loc == -1)
			game->play_info.patrol_loc = i;
		else
			print_err("Invalid map: Too Many Patrol\n");
	}
	else if (mapinfo->map[i] == 'E')
	{
		if (mapinfo->exit_point == -1)
			mapinfo->exit_point = i;
		else
			print_err("Invalid map: Too Many Exit\n");
	}
	else if (mapinfo->map[i] != '1' && mapinfo->map[i] != '0' && \
			mapinfo->map[i] != 'C' && mapinfo->map[i] != 'P')
		print_err("Invalid map: Unexpected component\n");
}

void	map_validation(t_game *game)
{
	int	i;

	if (game->mapinfo.width == -1)
		print_err("Invalid map\n");
	i = 0;
	while (i < game->mapinfo.width * game->mapinfo.height)
	{
		check_tile1(game, &(game->mapinfo), i);
		check_tile2(game, &(game->mapinfo), i);
		i++;
	}
	if (game->mapinfo.cltb_cnt == 0 || \
			game->play_info.player_loc == -1 || game->mapinfo.exit_point == -1)
		print_err("Invalid map\n");
}

void	render_map(t_game *game)
{
	int			w;
	int			h;
	int			i;
	t_mapinfo	*mapinfo;

	mapinfo = &(game->mapinfo);
	w = mapinfo->width;
	h = mapinfo->height;
	i = 0;
	while (i < w * h)
	{
		put_specified_image(game, GROUND, i);
		if (mapinfo->map[i] == '1')
			put_specified_image(game, WALL, i);
		if (mapinfo->map[i] == 'C')
			put_specified_image(game, CLTB, i);
		if (mapinfo->map[i] == 'E')
			put_specified_image(game, EXIT, i);
		i++;
	}
	render_number(game);
}

void	render_number(t_game *game)
{
	char		*mv_cnt;

	put_specified_image(game, NUMBER, 0);
	mv_cnt = ft_itoa(game->play_info.move_cnt);
	if (mv_cnt == NULL)
	{
		perror("Error");
		exit(0);
	}
	mlx_string_put(game->mlx, game->win, 15, 11, 0, mv_cnt);
	free(mv_cnt);
}
