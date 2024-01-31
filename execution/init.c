/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:59:33 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/31 21:30:22 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	init_side_dist(t_dda *dda, t_game *game, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (game->player->pos_x - dda->map_x)
			* dda->delta_dist_x;
	}
	else
		dda->side_dist_x = (dda->map_x + 1.0 - game->player->pos_x)
			* dda->delta_dist_x;
	if (ray->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (game->player->pos_y - dda->map_y)
			* dda->delta_dist_y;
	}
	else
		dda->side_dist_y = (dda->map_y + 1.0 - game->player->pos_y)
			* dda->delta_dist_y;
}

void	init_dda(t_game *game, t_dda *dda, t_raycast *ray, int i)
{
	double camera;

	camera = 2 * i / (double)WIDTH - 1;
	ray->ray_dir_x = game->player->dir_x + game->player->plane_x * camera;
	ray->ray_dir_y = game->player->dir_y + game->player->plane_y * camera;
	dda->map_x = (int)(game->player->pos_x);
	dda->map_y = (int)(game->player->pos_y);
	if (ray->ray_dir_x == 0)
		dda->delta_dist_x = 1e30;
	else
		dda->delta_dist_x = ft_abs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		dda->delta_dist_y = 1e30;
	else
		dda->delta_dist_y = ft_abs(1 / ray->ray_dir_y);
	dda->step_x = 1;
	dda->step_y = 1;
	init_side_dist(dda, game, ray);
}
