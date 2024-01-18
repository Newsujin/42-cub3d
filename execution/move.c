/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:52 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/18 22:16:36 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	rotate_vectors(t_mlx *mlx, int orientation)
{
	double	angle;
	double	dir_x = mlx->data->dir_x;
	double	dir_y = mlx->data->dir_y;
	double	plane_x = mlx->data->plane_x;
	double	plane_y = mlx->data->plane_y;

	angle = ROTATION_SPEED * (M_1_PI / 180.0);
	if (orientation == LEFT)
		angle = -angle;
	mlx->data->dir_x = cos(angle) * dir_x - sin(angle) * dir_y;
	mlx->data->dir_y = sin(angle) * dir_x + cos(angle) * dir_y;
	mlx->data->plane_x = cos(angle) * plane_x - sin(angle) * plane_y;
	mlx->data->plane_y = sin(angle) * plane_x + cos(angle) * plane_y;
}

// static void	move_player(t_mlx *mlx, double x_change, double y_change)
// {
// 	char	**map;

// 	map = mlx->data->map;
// 	if (map[(int)mlx->data->pos_y][(int)(mlx->data->pos_x + x_change)] == 0)
// 		mlx->data->pos_x += x_change;
// 	if (map[(int)(mlx->data->pos_y + y_change)][(int)mlx->data->pos_x] == 0)
// 		mlx->data->pos_y += y_change;
// }

// static void	handle_movement(t_key *key, t_mlx *mlx)
// {
// 	double	tmp_dir_x;
// 	double	tmp_dir_y;
// 	double	tmp_plane_x;
// 	double	tmp_plane_y;

// 	tmp_dir_x = mlx->data->dir_x * MOVE_SPEED;
// 	tmp_dir_y = mlx->data->dir_y * MOVE_SPEED;
// 	tmp_plane_x = mlx->data->plane_x * MOVE_SPEED;
// 	tmp_plane_y = mlx->data->plane_y * MOVE_SPEED;
// 	if (key->move_forward == 1)
// 		move_player(mlx, tmp_dir_x, tmp_dir_y);
// 	if (key->move_backward == 1)
// 		move_player(mlx, -tmp_dir_x, -tmp_dir_y);
// 	if (key->move_right == 1)
// 		move_player(mlx, tmp_plane_x, tmp_plane_y);
// 	if (key->move_left == 1)
// 		move_player(mlx, tmp_plane_x, -tmp_plane_y);
// }
