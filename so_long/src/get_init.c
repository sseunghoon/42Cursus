/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunghso <seunghso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:41:47 by seunghso          #+#    #+#             */
/*   Updated: 2022/07/27 18:41:20 by seunghso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	init_mapinfo(t_mapinfo *mapinfo)
{
	mapinfo->map = (char *)malloc(sizeof(char) * 1);
	if (mapinfo->map == NULL)
	{
		perror("Error");
		exit(0);
	}
	mapinfo->map[0] = '\0';
	mapinfo->width = -1;
	mapinfo->height = 0;
	mapinfo->cltb_cnt = 0;
	mapinfo->exit_point = -1;
}

void	init_game(t_game *game, int argc, char **argv)
{
	if (argc != 2)
		print_err("Few or Too Many Arguments\n");
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
		print_err("Wrong Extension\n");
	game->play_info.move_cnt = 0;
	game->play_info.player_loc = -1;
	game->play_info.patrol_loc = -1;
	game->play_info.score = 0;
	init_mapinfo(&(game->mapinfo));
	get_mapinfo(&(game->mapinfo), argv[1]);
	map_validation(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, TILE_SIZE * game->mapinfo.width, \
							TILE_SIZE * game->mapinfo.height, "so_long");
	game->flame = 0;
	get_imginfo(game, &(game->imgs.ground), "asset/ground.xpm");
	get_imginfo(game, &(game->imgs.wall), "asset/wall.xpm");
	get_imginfo(game, &(game->imgs.cltb), "asset/cltb.xpm");
	get_imginfo(game, &(game->imgs.exit), "asset/exit.xpm");
	get_imginfo(game, &(game->imgs.number), "asset/num_tree.xpm");
	get_imginfo(game, &(game->imgs.player1), "asset/player1.xpm");
	get_imginfo(game, &(game->imgs.player2), "asset/player2.xpm");
	get_imginfo(game, &(game->imgs.patrol1), "asset/patrol1.xpm");
	get_imginfo(game, &(game->imgs.patrol2), "asset/patrol2.xpm");
}

void	get_imginfo(t_game *game, t_img *image, char *path)
{
	int		tmp;

	image->img = NULL;
	image->img = mlx_xpm_file_to_image(game->mlx, path, &tmp, &tmp);
	if (image->img == NULL)
	{
		printf("Error opening file %s: %s\n", path, strerror(errno));
		exit(0);
	}
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel), \
								&(image->line_length), &(image->endian));
	if (image->addr == NULL)
	{
		perror("Error");
		exit(0);
	}
}

void	get_mapinfo(t_mapinfo *mapinfo, char *path)
{
	int		fd;
	int		len;
	char	*buff;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_err("opening file");
	while (fd >= 0)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		len = ft_strlen(buff);
		if (len == 0 && ft_strlen(mapinfo->map) != 0)
			break ;
		if (buff[len - 1] == '\n')
			len = len -1;
		if (mapinfo->width != -1 && mapinfo->width != len)
			print_err("Invalid Map");
		ft_buffncat(&(mapinfo->map), buff, -1, len);
		if (mapinfo->width == -1)
			mapinfo->width = ft_strlen(mapinfo->map);
		mapinfo->height++;
		free(buff);
	}
}
