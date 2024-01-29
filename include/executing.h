/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executing.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:03:11 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/29 21:53:06 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTING_H
# define EXECUTING_H

# include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
# include <math.h>
#include "parsing.h"
# include "struct.h"
# include "../mlx/mlx.h"

# define WIDTH	1920
# define HEIGHT	1080
# define ROTATION_SPEED 40
# define MOVE_SPEED 0.08
# define LEFT 1
# define RIGHT 2
# define POS_X 1
# define POS_Y -1
# define WALL_X 0
# define WALL_Y 1

# define KEY_ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_EXIT 17

# define KEY_LEFT		123
# define KEY_RIGHT		124
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

/* init */
void	init_direction_vectors(t_game *game);
void	init_raycast(t_game *game);
void	init_side_dist(t_dda *dda, t_game *game, t_raycast *ray);
void	init_dda(t_dda *dda, t_raycast *ray, t_game *game);

/* move */
void		rotate_vectors(t_game *game, int direction);
// static void	move_player(t_mlx *mlx, double x_change, double y_change);
// static void	handle_movement(t_key *key, t_mlx *mlx);

/* key */
int	key_pressed(t_game *game);
int	key_detector(int keycode, t_game *game);
int	key_released(int keycode, t_game *game);
int	update_frame(t_game *game);
int	destroy_win(int keycode, t_game *game);

/* utils */
double	ft_abs(double num);
bool	check_wall(t_game *game, t_dda *dda);
int		find_collision_wall_direction(t_raycast *ray, t_dda dda, int side);

/* executing */
t_dda	*apply_dda(t_game *game, t_raycast *ray, t_dda *dda);
void	shoot_ray(t_game *game, t_raycast *ray, t_dda *dda);
void	draw_vertical_line(t_game *game, t_raycast ray, int line, t_dda *dda);
void	raycasting(t_game *game);
void	executing(t_game *game);

/* draw */
void	set_buffer(t_game *game);
void	draw_buffer(t_game *game);

#endif