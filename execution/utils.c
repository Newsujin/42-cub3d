/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:59:12 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/24 17:02:04 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

bool	check_wall(t_mlx *mlx, t_dda *dda)
{
	bool	hit;
	char	pixel = mlx->data->map[dda->map_y][dda->map_x];

	hit = false;
	if (dda->map_x > -1 && dda->map_y > -1 && pixel == '1')
		hit = true;
	return (hit);
}

int	find_collision_wall_direction(t_raycast *ray, t_dda dda, int side)
{
	int	orientation;

	if (ray->end >= HEIGHT)
		ray->end = HEIGHT - 1;
	if (dda.step_x == -1 && side == WALL_X)
		orientation = EAST;
	else if (dda.step_x == 1 && side == WALL_X)
		orientation = WEST;
	else if (dda.step_y == 1 && side == WALL_Y)
		orientation = NORTH;
	else
		orientation = SOUTH;
	return (orientation);
}
