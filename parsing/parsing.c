/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:02:17 by spark2            #+#    #+#             */
/*   Updated: 2024/02/04 02:13:42 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	parsing(t_game *game, char *argv)
{
	init_game(game, argv);
	game->mlx = mlx_init();
	if (game->mlx == (void *)0)
		error("Error\nmlx\n");
	read_map(game);
	if (game->map == (void *)0)
		error("Error\nmap\n");
	check_map2(game);
	check_overlap(game);
	init_player(game);
	init_rgb(game);
	init_buf(game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	game->img->init = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img->data = (int *)mlx_get_data_addr(game->img->init, \
	&(game->img->bpp), &(game->img->size_l), &(game->img->endian));
}
