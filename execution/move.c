/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:52 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/30 21:48:55 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	rotate_vectors(t_game *game, int direction)
{
	double	angle;
	double	dir_x = game->player->dir_x;
	double	dir_y = game->player->dir_y;
	double	plane_x = game->player->plane_x;
	double	plane_y = game->player->plane_y;

	angle = ROTATION_SPEED * (M_1_PI / 180.0);
	if (direction == LEFT)
		angle = -angle;
	game->player->dir_x = cos(angle) * dir_x - sin(angle) * dir_y;
	game->player->dir_y = sin(angle) * dir_x + cos(angle) * dir_y;
	game->player->plane_x = cos(angle) * plane_x - sin(angle) * plane_y;
	game->player->plane_y = sin(angle) * plane_x + cos(angle) * plane_y;
}

void	move_player(t_game *game, double x_change, double y_change)
{
	char	**map;

	map = game->map_2d;
	if (map[(int)game->player->pos_y][(int)(game->player->pos_x + x_change)] == 0)
		game->player->pos_x += x_change;
	if (map[(int)(game->player->pos_y + y_change)][(int)game->player->pos_x] == 0)
		game->player->pos_y += y_change;
}

void	handle_movement(t_key *key, t_game *game)
{
	double	tmp_dir_x;
	double	tmp_dir_y;
	double	tmp_plane_x;
	double	tmp_plane_y;

	tmp_dir_x = game->player->dir_x * MOVE_SPEED;
	tmp_dir_y = game->player->dir_y * MOVE_SPEED;
	tmp_plane_x = game->player->plane_x * MOVE_SPEED;
	tmp_plane_y = game->player->plane_y * MOVE_SPEED;
	if (key->move_forward == 1)
		move_player(game, tmp_dir_x, tmp_dir_y);
	if (key->move_backward == 1)
		move_player(game, -tmp_dir_x, -tmp_dir_y);
	if (key->move_right == 1)
		move_player(game, tmp_plane_x, tmp_plane_y);
	if (key->move_left == 1)
		move_player(game, tmp_plane_x, -tmp_plane_y);
}
