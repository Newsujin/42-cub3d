/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:44:07 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/31 21:45:08 by yerilee          ###   ########.fr       */
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

void	calculating_drawing_size(t_dda *dda, t_raycast *ray)
{
	if (dda->side == WALL_X)
		dda->perp_wall_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		dda->perp_wall_dist = dda->side_dist_y - dda->delta_dist_y;
	if (dda->perp_wall_dist == 0)
		dda->perp_wall_dist = 1e30;
	dda->wall_height = (int)((double)HEIGHT / dda->perp_wall_dist);
	ray->start = -(dda->wall_height) / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = dda->wall_height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
}

void	calculating_texture_x(t_game *game, t_dda *dda, t_raycast *ray)
{
	double	wall_x;

	if (dda->side == WALL_X)
		wall_x = game->player->pos_y + dda->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = game->player->pos_x + dda->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * 64.0);
	if (dda->side == WALL_X && ray->ray_dir_x > 0)
		ray->tex_x = 64.0 - ray->tex_x - 1;
	if (dda->side == WALL_Y && ray->ray_dir_y < 0)
		ray->tex_x = 64.0 - ray->tex_x - 1;
}

void	calculating_texture_y(t_game *game, t_dda *dda, t_raycast ray, int x)
{
	int	y;

	ray.step = 1.0 * 64 / (double)dda->wall_height;
	ray.tex_pos = (ray.start - (double)HEIGHT / 2
			+ (double)dda->wall_height / 2) * ray.step;
	y = ray.start;
	while (y < ray.end)
	{
		ray.tex_y = (int)ray.tex_pos & 63;
		ray.tex_pos += ray.step;
		ray.color = game->text[ray.tex_direction].data[64 * ray.tex_y + ray.tex_x];
		if (dda->side == WALL_Y)
			ray.color = (ray.color >> 1) & 8355711;
		game->buf[y][x] = ray.color;
		y++;
	}
}
