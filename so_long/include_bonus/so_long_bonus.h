/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:40:21 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/27 15:38:46 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../libft/include/ft_printf.h"
# include "../libft/include/get_next_line.h"
# include "../libft/include/libft.h"
# include "../mlx/mlx.h"
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

# define KEY_ESC 53
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_DOWN 125
# define KEY_RIGHT 124
# define KEY_UP 126
# define X_EVENT_KEY_EXIT 17
# define TILE_SIZE 64
# define CLBT_SIZE 44

typedef enum e_img_comp
{
	GROUND,
	WALL,
	CLTB,
	EXIT,
	NUMBER,
	PLAYER1,
	PLAYER2,
	PATROL1,
	PATROL2
}	t_img_comp;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_imgs
{
	t_img	ground;
	t_img	wall;
	t_img	cltb;
	t_img	exit;
	t_img	number;
	t_img	player1;
	t_img	player2;
	t_img	patrol1;
	t_img	patrol2;
}		t_imgs;

typedef struct s_play_info
{
	int			player_loc;
	int			patrol_loc;
	int			move_cnt;
	int			score;
}		t_play_info;

typedef struct s_mapinfo
{
	char			*map;
	int				width;
	int				height;
	int				cltb_cnt;
	int				exit_point;
}		t_mapinfo;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	int				flame;
	t_imgs			imgs;
	t_mapinfo		mapinfo;
	t_play_info		play_info;
}		t_game;

// get_init_bonus.c
void	init_mapinfo(t_mapinfo *mapinfo);
void	init_game(t_game *game, int argc, char **argv);
void	get_mapinfo(t_mapinfo *mapinfo, char *path);
void	get_imginfo(t_game *game, t_img *image, char *path);

// map_bonus.c
void	check_tile1(t_game *game, t_mapinfo *mapinfo, int i);
void	check_tile2(t_game *game, t_mapinfo *mapinfo, int i);
void	map_validation(t_game *game);
void	render_map(t_game *game);
void	render_number(t_game *game);

// command_bonus.c
int		key_hook(int keycode, t_game *game);
void	move_player(t_game *game, int loc_change);

// put_img_bonus.c
void	put_img(t_game *game, t_img image, int loc, int img_size);
void	put_specified_image(t_game *game, t_img_comp img, int loc);

// etc_bonus.c
void	clear_game(t_game *game);
int		exit_game(t_game *game);
void	print_err(char *str);

#endif
