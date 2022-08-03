/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:41:13 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/27 13:03:14 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	key_hook(int key_code, t_game *game)
{
	int	move_left;
	int	move_down;
	int	move_right;
	int	move_up;

	move_left = -1;
	move_right = 1;
	move_down = game->mapinfo.width;
	move_up = -game->mapinfo.width;
	if (key_code == KEY_ESC)
		exit_game(game);
	if (key_code == KEY_A || key_code == KEY_LEFT)
		move_player(game, move_left);
	if (key_code == KEY_S || key_code == KEY_DOWN)
		move_player(game, move_down);
	if (key_code == KEY_D || key_code == KEY_RIGHT)
		move_player(game, move_right);
	if (key_code == KEY_W || key_code == KEY_UP)
		move_player(game, move_up);
	return (0);
}

void	move_player(t_game *game, int loc_change)
{
	if (game->mapinfo.map[game->play_info.player_loc + loc_change] != '1')
	{
		game->play_info.player_loc += loc_change;
		game->play_info.move_cnt++;
		printf("movement_cnt: %d\n", game->play_info.move_cnt);
	}
	if (game->mapinfo.map[game->play_info.patrol_loc + loc_change] != '1')
		game->play_info.patrol_loc += loc_change;
	if (game->play_info.player_loc == game->mapinfo.exit_point)
	{
		if (game->mapinfo.cltb_cnt == 0 && \
			game->play_info.player_loc != game->play_info.patrol_loc)
			clear_game(game);
		else
			exit_game(game);
	}
	if (game->mapinfo.map[game->play_info.player_loc] == 'C')
	{
		game->play_info.score += 50;
		game->mapinfo.map[game->play_info.player_loc] = '0';
		game->mapinfo.cltb_cnt--;
	}
}
