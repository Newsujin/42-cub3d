/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:32:42 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/29 20:11:24 by yerilee          ###   ########.fr       */
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

void	calculate_vertical_wall(t_game *game, t_raycast *ray, t_dda *dda)
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
	calculate_vertical_wall(game, ray, dda);
	find_collision_wall_direction(ray, *dda, dda->side);
}

void	calculating_texture(t_game *game, int x, t_dda *dda, t_raycast *ray)
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
	ray->step = 1.0 * 64 / (double)dda->wall_height;
	ray->tex_pos = (ray->start - (double)HEIGHT / 2
			+ (double)dda->wall_height / 2) * ray->step;
}

void	draw_vertical_line(t_game *game, t_raycast ray, int line, t_dda *dda)
{
	int	y;

	y = 0;
	(void) game;
	(void) ray;
	(void) line;
	(void) dda;
	while (y < HEIGHT)
	{
		// if (y < ray.start && y < 이미지 높이 && x < 이미지 너비)
		// 	배경
		// else if (y >= ray.start && y <= ray.end && y < 이미지 높이 && x < 이미지 너비)
		// 	스프라이트
		// else if (y > ray.end && y < 이미지 높이 && x x < 이미지 너비)
		// 배경
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
		calculating_texture(game, i, &dda, &ray);
		draw_vertical_line(game, ray, i, &dda);
		i++;
	}
}

void	set_buf(t_game *game)
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

void	executing(t_game *game)
{
	set_buf(game);
	init_direction_vectors(game);
	init_raycast(game);
	// raycasting(&mlx);
	key_pressed(game);
	mlx_loop(game->mlx->init);
	// exit;
}

