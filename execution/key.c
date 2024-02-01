/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:59:39 by yerilee           #+#    #+#             */
/*   Updated: 2024/02/01 13:09:47 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

int	destroy_win(t_game *game)
{
	free(game->color);
	free(game->player);
	free(game->img);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	update_frame(int keycode, t_game *game)
{
	double	tmp_dir_x;
	double	tmp_dir_y;
	double	tmp_plane_x;
	double	tmp_plane_y;

	tmp_dir_x = game->player->dir_x * MOVE_SPEED;
	tmp_dir_y = game->player->dir_y * MOVE_SPEED;
	tmp_plane_x = game->player->plane_x * MOVE_SPEED;
	tmp_plane_y = game->player->plane_y * MOVE_SPEED;
	if (keycode == KEY_ESC)
		destroy_win(game);
	else if (keycode == KEY_W)
	 	move_player(game, tmp_dir_x, tmp_dir_y);
	else if (keycode == KEY_S)
		move_player(game, -tmp_dir_x, -tmp_dir_y);
	else if (keycode == KEY_D)
		move_player(game, tmp_plane_x, tmp_plane_y);
	else if (keycode == KEY_A)
		move_player(game, -tmp_plane_x, -tmp_plane_y);
	else if (keycode == KEY_LEFT)
		rotate_player(game, LEFT);
	else if (keycode == KEY_RIGHT)
		rotate_player(game, RIGHT);
	return (0);
}

int	key_detector(t_game *game)
{
	mlx_hook(game->win, 2, 0, &update_frame, game);
	mlx_hook(game->win, 17, 0, &destroy_win, game);
	return (0);
}
