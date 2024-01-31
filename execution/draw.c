/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:44:07 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/31 16:26:38 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	set_buffer(t_game *game)
{
	int	wid;
	int	hei;

	wid = 0;
	while (wid < WIDTH)
	{
		hei = 0;
		while (hei < HEIGHT / 2)
		{
			game->buf[hei][wid] = game->color->c_color;
			game->buf[HEIGHT - hei - 1][wid] = game->color->f_color;
			hei++;
		}
		wid++;
	}
}

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
	mlx_put_image_to_window(game->mlx, game->win, game->img->init, 0, 0);
}
