/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 20:13:52 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/17 22:49:56 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

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

// double	convert_degree_to_radian(double degree)
// {
// 	return (degree * (M_PI / 180));
// }

static void	move_player(t_mlx *mlx, double x_change, double y_change)
{
	char	**map;

	map = mlx->data->map;
	// if (can_move)
	// 	mlx->data->pos_x += x_change;
	// if (can_move)
	// 	mlx->data->pos_y += y_change;
}

/*
static void	handle_movement(t_mlx *mlx)
{
	double	tmp_dir_x;
	double	tmp_dir_y;
	double	tmp_plane_x;
	double	tmp_plane_y;

	tmp_dir_x = mlx->data->dir_x * MOVE_SPEED;
	tmp_dir_y = mlx->data->dir_y * MOVE_SPEED;
	tmp_plane_x = mlx->data->plane_x * MOVE_SPEED;
	tmp_plane_y = mlx->data->plane_y * MOVE_SPEED;
	if (mlx_is_key_down(mlx->init, KEY_W))
		move_player(mlx, tmp_dir_x, tmp_dir_y);
	if (mlx_is_key_down(mlx->init, KEY_S))
		move_player(mlx, -tmp_dir_x, -tmp_dir_y);
	if (mlx_is_key_down(mlx->init, KEY_D))
		move_player(mlx, tmp_plane_x, tmp_plane_y);
	if (mlx_is_key_down(mlx->init, KEY_A))
		move_player(mlx, tmp_plane_x, -tmp_plane_y);
}

void	handle_key(void *arg)
{
	t_mlx	*mlx;

	mlx = arg;
	handle_movement(mlx);
	if (mlx_is_key_down(mlx->init, KEY_ESC))
		mlx_clear_window(mlx->init, mlx->win);
	if (mlx_is_key_down(mlx->init, KEY_LEFT))
		rotate_vectors(mlx, LEFT);
	if (mlx_is_key_down(mlx->init, KEY_RIGHT))
		rotate_vectors(mlx, RIGHT);
	// key_space
	raycasting(mlx);
}
*/
