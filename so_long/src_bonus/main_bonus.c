/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:42:08 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/27 14:28:47 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/so_long_bonus.h"

int	main_loop(t_game *game)
{
	render_map(game);
	if (game->flame > 30)
		put_specified_image(game, PLAYER1, game->play_info.player_loc);
	else
		put_specified_image(game, PLAYER2, game->play_info.player_loc);
	if (game->flame > 30)
		put_specified_image(game, PATROL1, game->play_info.patrol_loc);
	else
		put_specified_image(game, PATROL2, game->play_info.patrol_loc);
	if (game->play_info.player_loc == game->play_info.patrol_loc)
		exit_game(game);
	game->flame++;
	if (game->flame > 60)
		game->flame = 0;
	return (0);
}

void	print_tips(void)
{
	printf("\n##########################################################\n\n");
	printf("Game Goal: Get the Pokemon ball(s) and catch the Pikachu! \n");
	printf("Tips: The Phantom imitates your movements. \n");
	printf("\n##########################################################\n\n");
}

int	main(int argc, char **argv)
{
	t_game		game;

	init_game(&game, argc, argv);
	print_tips();
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_game, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
