/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:52 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/26 21:23:36 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	rotate_vectors(t_mlx *mlx, int direction)
{
	double	angle;
	double	dir_x = mlx->game->player->dir_x;
	double	dir_y = mlx->game->player->dir_y;
	double	plane_x = mlx->game->player->plane_x;
	double	plane_y = mlx->game->player->plane_y;

	angle = ROTATION_SPEED * (M_1_PI / 180.0);
	if (direction == LEFT)
		angle = -angle;
	mlx->game->player->dir_x = cos(angle) * dir_x - sin(angle) * dir_y;
	mlx->game->player->dir_y = sin(angle) * dir_x + cos(angle) * dir_y;
	mlx->game->player->plane_x = cos(angle) * plane_x - sin(angle) * plane_y;
	mlx->game->player->plane_y = sin(angle) * plane_x + cos(angle) * plane_y;
}

// static void	move_player(t_mlx *mlx, double x_change, double y_change)
// {
// 	char	**map;

// 	map = mlx->game->map;
// 	if (map[(int)mlx->game->pos_y][(int)(mlx->game->pos_x + x_change)] == 0)
// 		mlx->game->pos_x += x_change;
// 	if (map[(int)(mlx->game->pos_y + y_change)][(int)mlx->game->pos_x] == 0)
// 		mlx->game->pos_y += y_change;
// }

// static void	handle_movement(t_key *key, t_mlx *mlx)
// {
// 	double	tmp_dir_x;
// 	double	tmp_dir_y;
// 	double	tmp_plane_x;
// 	double	tmp_plane_y;

// 	tmp_dir_x = mlx->game->dir_x * MOVE_SPEED;
// 	tmp_dir_y = mlx->game->dir_y * MOVE_SPEED;
// 	tmp_plane_x = mlx->game->plane_x * MOVE_SPEED;
// 	tmp_plane_y = mlx->game->plane_y * MOVE_SPEED;
// 	if (key->move_forward == 1)
// 		move_player(mlx, tmp_dir_x, tmp_dir_y);
// 	if (key->move_backward == 1)
// 		move_player(mlx, -tmp_dir_x, -tmp_dir_y);
// 	if (key->move_right == 1)
// 		move_player(mlx, tmp_plane_x, tmp_plane_y);
// 	if (key->move_left == 1)
// 		move_player(mlx, tmp_plane_x, -tmp_plane_y);
// }
