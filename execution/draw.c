/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:44:07 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/29 21:44:03 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	draw_buffer(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			game->img->data[y * WIDTH + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx->win, game->img->init, 0, 0);
}
