/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:59:39 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/18 15:19:37 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

int	destroy_win(int keycode, t_data *data)
{
	int	i;

	i = -1;
	(void)keycode;
	(void)data;
	// ft_free_split
	// while (++i <= 3)
	// 	mlx_destroy_image
	exit(0);
}

int	key_detector(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_flag.move_forward = 1;
	if (keycode == KEY_S)
		data->key_flag.move_backward = 1;
	if (keycode == KEY_D)
		data->key_flag.move_right = 1;
	if (keycode == KEY_A)
		data->key_flag.move_left = 1;
	if (keycode == KEY_LEFT)
		data->key_flag.rotate_left = 1;
	if (keycode == KEY_RIGHT)
		data->key_flag.rotate_right = 1;
	if (keycode == KEY_ESC)
		destroy_win(53, data);
	return (0);
}

int	key_released(int keycode, t_data *data)
{
	if (keycode == KEY_W)
		data->key_flag.move_forward = 0;
	if (keycode == KEY_S)
		data->key_flag.move_backward = 0;
	if (keycode == KEY_D)
		data->key_flag.move_right = 0;
	if (keycode == KEY_A)
		data->key_flag.move_left = 0;
	if (keycode == KEY_LEFT)
		data->key_flag.rotate_left = 0;
	if (keycode == KEY_RIGHT)
		data->key_flag.rotate_right = 0;
	if (keycode == KEY_ESC)
		destroy_win(53, data);
	return (0);
}

int	update_frame(t_mlx *mlx)
{
	t_key	key;

	key = mlx->data->key_flag;
	// handle_movement(&key, mlx);
	if (key.rotate_left == 1)
		rotate_vectors(mlx, LEFT);
	if (key.rotate_right == 1)
		rotate_vectors(mlx, RIGHT);
	// raycasting(mlx);
	return (0);
}

int	key_pressed(t_mlx *mlx)
{
	mlx_hook(mlx->win, 2, 0, key_detector, mlx->data);
	mlx_hook(mlx->win, 3, 0, key_released, mlx->data);
	mlx_hook(mlx->win, 17, 0, destroy_win, mlx->data);
	mlx_loop_hook(mlx->init, update_frame, mlx);
	return (0);
}
