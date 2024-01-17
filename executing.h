/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:03:11 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/17 20:04:35 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H

# include <stdbool.h>
// #include "parsing.h"
# include "struct.h"
# include "mlx/mlx.h"

# define WIDTH	1920
# define HEIGHT	1080


/* init */
void	init_direction_vectors(t_mlx *mlx);
void	init_raycast(t_mlx *mlx);
void	init_side_dist(t_dda *dda, t_mlx *mlx, t_raycast *ray);
void	init_dda(t_dda *dda, t_raycast *ray, t_mlx *mlx);

/* utils */
double	ft_abs(double num);
bool	check_wall(t_mlx *mlx, t_dda *dda);

/* executing */
t_dda	*apply_dda(t_mlx *mlx, t_raycast *ray, t_dda *dda);
void	shoot_ray(t_mlx *mlx, t_raycast *ray, t_dda *dda);
void	draw_vertical_line(t_mlx *mlx, t_raycast ray, int line, t_dda *dda);
void	raycasting(t_mlx *mlx);
void	executing(t_data *data);


#endif