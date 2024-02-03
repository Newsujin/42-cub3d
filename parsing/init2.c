/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:14:32 by spark2            #+#    #+#             */
/*   Updated: 2024/02/04 02:16:11 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	find_location(t_game *game, char location, int i, int j)
{
	game->player->pos_x = i + 0.5;
	game->player->pos_y = j + 0.5;
	if (location == 'N')
	{
		game->player->dir_x = -1;
		game->player->plane_y = 0.66;
	}
	else if (location == 'S')
	{
		game->player->dir_x = 1;
		game->player->plane_y = -0.66;
	}
	else if (location == 'W')
	{
		game->player->dir_y = -1;
		game->player->plane_x = -0.66;
	}
	else if (location == 'E')
	{
		game->player->dir_y = 1;
		game->player->plane_x = 0.66;
	}
	else
		return (0);
	return (1);
}

void	init_player(t_game *game)
{
	int		i;
	int		j;

	game->player->plane_x = 0;
	game->player->plane_y = 0;
	game->player->dir_x = 0;
	game->player->dir_y = 0;
	i = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			if (find_location(game, game->map_2d[i][j], i, j))
				return ;
			j++;
		}
		i++;
	}
}

void	init_rgb(t_game *game)
{
	game->color->c_color = (game->color->ceil[0] << 16) | \
		(game->color->ceil[1] << 8) | game->color->ceil[2];
	game->color->f_color = (game->color->floor[0] << 16) | \
		(game->color->floor[1] << 8) | game->color->floor[2];
}

void	init_buf(t_game *game)
{
	int	i;
	int	j;

	game->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	i = 0;
	while (i < HEIGHT)
	{
		game->buf[i] = (int *)malloc(sizeof(int) * WIDTH);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			game->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}
