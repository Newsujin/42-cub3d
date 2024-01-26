/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:59:33 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/26 21:23:23 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	init_direction_vectors(t_mlx *mlx)
{
	mlx->game->player->pos_x = mlx->game->player->y;
	mlx->game->player->pos_y = mlx->game->player->x;
	mlx->game->player->dir_x = 0;
	mlx->game->player->dir_y = 0;
	if (mlx->game->direction == 'S')
		mlx->game->player->dir_y = 1;
	else if (mlx->game->direction == 'N')
		mlx->game->player->dir_y = -1;
	else if (mlx->game->direction == 'E')
		mlx->game->player->dir_x = 1;
	else if (mlx->game->direction == 'W')
		mlx->game->player->dir_x = -1;
}

void	init_raycast(t_mlx *mlx)
{
	double	dir_x;
	double	dir_y;

	dir_x = 0;
	dir_y = 0;
	if (mlx->game->direction == 'S')
		dir_y = 1;
	else if (mlx->game->direction == 'N')
		dir_y = -1;
	else if (mlx->game->direction == 'E')
		dir_x = 1;
	else if (mlx->game->direction == 'W')
		dir_x = -1;
	mlx->game->player->plane_x = -(dir_y) * 0.66;
	mlx->game->player->plane_y = dir_x * 0.66;
}

void	init_side_dist(t_dda *dda, t_mlx *mlx, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (mlx->game->player->pos_x - dda->map_x)
			* dda->delta_dist_x;
	}
	else
		dda->side_dist_x = (dda->map_x + 1.0 - mlx->game->player->pos_x)
			* dda->delta_dist_x;
	if (ray->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (mlx->game->player->pos_y - dda->map_y)
			* dda->delta_dist_y;
	}
	else
		dda->side_dist_y = (dda->map_y + 1.0 - mlx->game->player->pos_y)
			* dda->delta_dist_y;
}

void	init_dda(t_dda *dda, t_raycast *ray, t_mlx *mlx)
{
	dda->map_x = (int)(mlx->game->player->pos_x);
	dda->map_y = (int)(mlx->game->player->pos_y);
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
	init_side_dist(dda, mlx, ray);
}
