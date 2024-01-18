/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:32:42 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/18 11:32:28 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

t_dda	*apply_dda(t_mlx *mlx, t_raycast *ray, t_dda *dda)
{
	bool	hit;

	init_dda(dda, ray, mlx);
	hit = false;
	while (hit == false)
	{
		if (dda->side_dist_x < dda->side_dist_y)
		{
			dda->side_dist_x += dda->delta_dist_x;
			dda->map_x += dda->step_x;
			dda->side = 0;
		}
		else
		{
			dda->side_dist_y += dda->delta_dist_y;
			dda->map_y += dda->step_y;
			dda->side = 1;
		}
		hit = check_wall(mlx, dda);
	}
	return (dda);
}

void	shoot_ray(t_mlx *mlx, t_raycast *ray, t_dda *dda)
{
	apply_dda(mlx, ray, dda);
	if (dda->side == 0)
		dda->perp_wall_dist = dda->side_dist_x - dda->delta_dist_x;
	else
		dda->perp_wall_dist = dda->side_dist_y - dda->delta_dist_y;
	if (dda->perp_wall_dist != 0)
		dda->wall_height = (int)((double)HEIGHT / dda->perp_wall_dist);
	ray->start = -(dda->wall_height) / 2 + HEIGHT / 2;
	if (ray->start < 0)
		ray->start = 0;
	ray->end = dda->wall_height / 2 + HEIGHT / 2;
	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	// texture
}

void	draw_vertical_line(t_mlx *mlx, t_raycast ray, int line, t_dda *dda)
{
	int	y;

	y = 0;
	(void) mlx;
	(void) ray;
	(void) line;
	(void) dda;
	while (y < HEIGHT)
	{
		/* ... */
		y++;
	}
}

void	raycasting(t_mlx *mlx)
{
	t_dda		dda;
	t_raycast	ray;
	double		camera;
	int			i;

	i = 0;
	while (i <= WIDTH)
	{
		camera = 2 * i / (double)WIDTH - 1;
		ray.ray_dir_x = mlx->data->dir_x + mlx->data->plane_x * camera;
		ray.ray_dir_y = mlx->data->dir_y + mlx->data->plane_y * camera;
		shoot_ray(mlx, &ray, &dda);
		draw_vertical_line(mlx, ray, i, &dda);
		i++;
	}
}

void	executing(t_data *data)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "cub3D");
	mlx.data = data;
	init_direction_vectors(&mlx);
	init_raycast(&mlx);
	// image
	// texture
	raycasting(&mlx);
	// key_hook
	// mlx_loop_hook(mlx.init, handle_key, &mlx);
	mlx_loop(mlx.init);
	// exit;
}
