/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:32:42 by yerilee           #+#    #+#             */
/*   Updated: 2024/02/02 21:09:26 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

void	shoot_ray(t_game *game, t_dda *dda, t_raycast *ray, int i)
{
	init_dda(game, dda, ray, i);
	apply_dda(game, dda);
	find_collision_wall_direction(ray, dda->side);
}

void	raycasting(t_game *game)
{
	t_dda		dda;
	t_raycast	ray;
	int			i;

	i = 0;
	while (i < WIDTH)
	{
		shoot_ray(game, &dda, &ray, i);
		calculating_drawing_size(&dda, &ray);
		calculating_texture_x(game, &dda, &ray);
		calculating_texture_y(game, &dda, ray, i);
		i++;
	}
}

void	executing(t_game *game)
{
	set_buffer(game);
	raycasting(game);
	draw_buffer(game);
	key_detector(game);
	mlx_loop(game->mlx);
}
