/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:59:12 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/31 16:31:37 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/executing.h"

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

bool	check_wall(t_game *game, t_dda *dda)
{
	bool	hit;
	char	pixel = game->map_2d[dda->map_x][dda->map_y];

	hit = false;
	if (dda->map_x > -1 && dda->map_y > -1 && pixel == '1')
		hit = true;
	return (hit);
}

void	find_collision_wall_direction(t_raycast *ray, t_dda dda, int side)
{
	if (dda.step_x == -1 && side == WALL_X)
		ray->tex_direction = EAST;
	else if (dda.step_x == 1 && side == WALL_X)
		ray->tex_direction = WEST;
	else if (dda.step_y == 1 && side == WALL_Y)
		ray->tex_direction = NORTH;
	else
		ray->tex_direction = SOUTH;
}
