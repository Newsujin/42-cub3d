/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:59:39 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/31 16:28:19 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

int	destroy_win(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
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
		destroy_win(game);
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
		destroy_win(game);
	return (0);
}

int	update_frame(t_game *game)
{
	t_key	key;

	key = game->key_flag;
	handle_movement(&key, game);
	if (key.rotate_left == 1)
		rotate_vectors(game, LEFT);
	if (key.rotate_right == 1)
		rotate_vectors(game, RIGHT);
	raycasting(game);
	return (0);
}

int	key_pressed(t_game *game)
{
	mlx_hook(game->win, 2, 0, key_detector, game);
	mlx_hook(game->win, 3, 0, key_released, game);
	mlx_hook(game->win, 17, 0, destroy_win, game);
	mlx_loop_hook(game->mlx, update_frame, game->mlx);
	return (0);
}
