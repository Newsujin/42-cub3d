/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:52 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/31 22:03:42 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	rotate_player(t_game *game, int direction)
{
	double	angle;
	double	dir_x = game->player->dir_x;
	double	dir_y = game->player->dir_y;
	double	plane_x = game->player->plane_x;
	double	plane_y = game->player->plane_y;

	angle = ROTATION_SPEED * (M_1_PI / 180.0);
	if (direction == RIGHT)
		angle = -angle;
	game->player->dir_x = cos(angle) * dir_x - sin(angle) * dir_y;
	game->player->dir_y = sin(angle) * dir_x + cos(angle) * dir_y;
	game->player->plane_x = cos(angle) * plane_x - sin(angle) * plane_y;
	game->player->plane_y = sin(angle) * plane_x + cos(angle) * plane_y;
	mlx_clear_window(game->mlx, game->win);
	executing(game);
}

void	move_player(t_game *game, double x_change, double y_change)
{
	char	**map;

	map = game->map_2d;
	if (map[(int)(game->player->pos_x + x_change)][(int)game->player->pos_y] != '1')
		game->player->pos_x += x_change;
	if (map[(int)game->player->pos_x][(int)(game->player->pos_y + y_change)] != '1')
		game->player->pos_y += y_change;
	mlx_clear_window(game->mlx, game->win);
	executing(game);
}
