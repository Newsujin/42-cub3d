/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:32:42 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/29 21:52:53 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

t_dda	*apply_dda(t_game *game, t_raycast *ray, t_dda *dda)
{
	bool	hit;

	init_dda(dda, ray, game);
	hit = false;
	while (hit == false)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = WALL_X;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = WALL_Y;
		}
		hit = check_wall(game, dda);
	}
	return (dda);
}

void	calculate_vertical_wall(t_raycast *ray, t_dda *dda)
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

void	shoot_ray(t_game *game, t_raycast *ray, t_dda *dda)
{
	apply_dda(game, ray, dda);
	calculate_vertical_wall(ray, dda);
	ray->tex_direction = find_collision_wall_direction(ray, *dda, dda->side);
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

void	calculating_texture_y(t_game *game, int x, t_dda *dda, t_raycast ray)
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

void	raycasting(t_game *game)
{
	t_dda		dda;
	t_raycast	ray;
	double		camera;
	int			i;

	i = 0;
	while (i <= WIDTH)
	{
		camera = 2 * i / (double)WIDTH - 1;
		ray.ray_dir_x = game->player->dir_x + game->player->plane_x * camera;
		ray.ray_dir_y = game->player->dir_y + game->player->plane_y * camera;
		shoot_ray(game, &ray, &dda);
		calculating_texture_x(game, &dda, &ray);
		calculating_texture_y(game, i, &dda, ray);
		i++;
	}
}

void	executing(t_game *game)
{
	set_buffer(game);
	init_direction_vectors(game);
	init_raycast(game);
	raycasting(game);
	draw_buffer(game);
	key_pressed(game);
	mlx_loop(game->mlx->init);
	// exit;
}

