/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:35 by spark2            #+#    #+#             */
/*   Updated: 2024/01/24 17:09:52 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->text[i].path = NULL;
		game->text[i].img = NULL;
		game->text[i].data = NULL;
		i++;
	}
}

void	init_game(t_game *game, char *file)
{
	game->map = NULL;
	game->map_2d = NULL;
	game->height = 0;
	game->player_cnt = 0;
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
		error("open Error\n");
	game->color = (t_color *)malloc(sizeof(t_color));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->img = (t_img *)malloc(sizeof(t_img));
	if (game->color == (void *)0 || game->player == (void *)0 || \
		game->img == (void *)0)
		error("malloc Error\n");
	init_texture(game);
	game->color->ceil_flag = 0;
	game->color->floor_flag = 0;
}
