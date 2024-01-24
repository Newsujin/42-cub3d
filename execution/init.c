/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:59:33 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/24 17:11:20 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	init_direction_vectors(t_mlx *mlx)
{
	mlx->data->pos_x = mlx->data->y;
	mlx->data->pos_y = mlx->data->x;
	mlx->data->dir_x = 0;
	mlx->data->dir_y = 0;
	if (mlx->data->direction == 'S')
		mlx->data->dir_y = 1;
	else if (mlx->data->direction == 'N')
		mlx->data->dir_y = -1;
	else if (mlx->data->direction == 'E')
		mlx->data->dir_x = 1;
	else if (mlx->data->direction == 'W')
		mlx->data->dir_x = -1;
}

void	init_raycast(t_mlx *mlx)
{
	double	dir_x;
	double	dir_y;

	dir_x = 0;
	dir_y = 0;
	if (mlx->data->direction == 'S')
		dir_y = 1;
	else if (mlx->data->direction == 'N')
		dir_y = -1;
	else if (mlx->data->direction == 'E')
		dir_x = 1;
	else if (mlx->data->direction == 'W')
		dir_x = -1;
	mlx->data->plane_x = -(dir_y) * 0.66;
	mlx->data->plane_y = dir_x * 0.66;
}

void	init_side_dist(t_dda *dda, t_mlx *mlx, t_raycast *ray)
{
	if (ray->ray_dir_x < 0)
	{
		dda->step_x = -1;
		dda->side_dist_x = (mlx->data->pos_x - dda->map_x)
			* dda->delta_dist_x;
	}
	else
		dda->side_dist_x = (dda->map_x + 1.0 - mlx->data->pos_x)
			* dda->delta_dist_x;
	if (ray->ray_dir_y < 0)
	{
		dda->step_y = -1;
		dda->side_dist_y = (mlx->data->pos_y - dda->map_y)
			* dda->delta_dist_y;
	}
	else
		dda->side_dist_y = (dda->map_y + 1.0 - mlx->data->pos_y)
			* dda->delta_dist_y;
}

void	init_dda(t_dda *dda, t_raycast *ray, t_mlx *mlx)
{
	dda->map_x = (int)(mlx->data->pos_x);
	dda->map_y = (int)(mlx->data->pos_y);
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
