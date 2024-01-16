/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:36:08 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/16 16:40:27 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "mlx/mlx.h"

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

typedef struct s_key
{
	int	move_forward;
	int	move_backward;
	int	move_right;
	int	move_left;
	int	rotate_left;
	int	rotate_right;
}	t_key;

typedef struct s_player
{
	float	x;
	float	y;
	float	fov;
	float	angle;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*map;
	int			fd;
	t_player	player;
}	t_game;

#endif