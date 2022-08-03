/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:39:55 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/27 14:28:42 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

void	put_img(t_game *game, t_img image, int loc, int img_size)
{
	int	map_w;
	int	map_h;
	int	margin;

	margin = (TILE_SIZE - img_size) / 2;
	map_w = game->mapinfo.width;
	map_h = game->mapinfo.height;
	mlx_put_image_to_window(game->mlx, game->win, image.img, \
		TILE_SIZE * (loc % map_w) + margin, TILE_SIZE * (loc / map_w) + margin);
}

void	put_specified_image(t_game *game, t_img_comp img, int loc)
{
	if (img == GROUND)
		put_img(game, game->imgs.ground, loc, TILE_SIZE);
	if (img == WALL)
		put_img(game, game->imgs.wall, loc, TILE_SIZE);
	if (img == CLTB)
		put_img(game, game->imgs.cltb, loc, CLBT_SIZE);
	if (img == EXIT)
		put_img(game, game->imgs.exit, loc, TILE_SIZE);
	if (img == NUMBER)
		put_img(game, game->imgs.number, loc, TILE_SIZE);
	if (img == PLAYER1)
		put_img(game, game->imgs.player1, loc, TILE_SIZE);
	if (img == PLAYER2)
		put_img(game, game->imgs.player2, loc, TILE_SIZE);
	if (img == PATROL1)
		put_img(game, game->imgs.patrol1, loc, TILE_SIZE);
	if (img == PATROL2)
		put_img(game, game->imgs.patrol2, loc, TILE_SIZE);
}
