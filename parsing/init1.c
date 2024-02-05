/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:35 by spark2            #+#    #+#             */
/*   Updated: 2024/02/06 00:04:29 by sujin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->text[i].init = NULL;
		game->text[i].path = NULL;
		game->text[i].data = NULL;
		i++;
	}
}

void	init_game(t_game *game, char *map)
{
	game->fd = open(map, O_RDONLY);
	if (game->fd < 0)
		error("open Error\n");
	game->player = (t_player *)malloc(sizeof(t_player));
	game->img = (t_img *)malloc(sizeof(t_img));
	game->color = (t_color *)malloc(sizeof(t_color));
	if (game->player == NULL || game->img == NULL \
		|| game->color == NULL)
		error("malloc Error\n");
	game->map = NULL;
	game->map_2d = NULL;
	game->player_cnt = 0;
	game->height = 0;
	game->color->ceil_flag = 0;
	game->color->floor_flag = 0;
	init_texture(game);
}
