/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:59:39 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/26 21:17:03 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

int	destroy_win(int keycode, t_game *game)
{
	int	i;

	i = -1;
	(void)keycode;
	(void)game;
	// ft_free_split
	// while (++i <= 3)
	// 	mlx_destroy_image
	exit(0);
}

int	key_detector(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key_flag.move_forward = 1;
	if (keycode == KEY_S)
		game->key_flag.move_backward = 1;
	if (keycode == KEY_D)
		game->key_flag.move_right = 1;
	if (keycode == KEY_A)
		game->key_flag.move_left = 1;
	if (keycode == KEY_LEFT)
		game->key_flag.rotate_left = 1;
	if (keycode == KEY_RIGHT)
		game->key_flag.rotate_right = 1;
	if (keycode == KEY_ESC)
		destroy_win(53, game);
	return (0);
}

int	key_released(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		game->key_flag.move_forward = 0;
	if (keycode == KEY_S)
		game->key_flag.move_backward = 0;
	if (keycode == KEY_D)
		game->key_flag.move_right = 0;
	if (keycode == KEY_A)
		game->key_flag.move_left = 0;
	if (keycode == KEY_LEFT)
		game->key_flag.rotate_left = 0;
	if (keycode == KEY_RIGHT)
		game->key_flag.rotate_right = 0;
	if (keycode == KEY_ESC)
		destroy_win(53, game);
	return (0);
}

int	update_frame(t_mlx *mlx)
{
	t_key	key;

	key = mlx->game->key_flag;
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
	mlx_hook(mlx->win, 2, 0, key_detector, mlx->game);
	mlx_hook(mlx->win, 3, 0, key_released, mlx->game);
	mlx_hook(mlx->win, 17, 0, destroy_win, mlx->game);
	mlx_loop_hook(mlx->init, update_frame, mlx);
	return (0);
}
