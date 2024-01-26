/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 21:09:35 by spark2            #+#    #+#             */
/*   Updated: 2024/01/26 22:50:58 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include "../mlx/mlx.h"

enum e_direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

typedef struct s_key
{
	int	move_right;
	int	move_left;
	int	move_backward;
	int	move_forward;
	int	rotate_left;
	int	rotate_right;
}	t_key;

typedef struct s_raycast
{
	double	ray_dir_x;
	double	ray_dir_y;
	double	tex_pos;
	double	step;
	int		tex_x;
	int		start;
	int		end;
}	t_raycast;

typedef struct s_dda
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		direction;
	int		wall_height;
}	t_dda;

/* parsing */
typedef struct s_color
{
	int				ceil[3];
	unsigned int	c_color;
	int				ceil_flag;
	int				floor[3];
	unsigned int	f_color;
	int				floor_flag;
}	t_color;

typedef struct s_img
{
	void	*init;
	char	*path;
	int		*data;
	int		bpp;
	int		size_l;
	int		endian;
}	t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
}	t_player;

typedef struct s_mlx
{
	void		*init;
	void		*win;
}	t_mlx;

typedef struct s_game
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			direction; // ?
	/* map */
	int				fd;
	char			*map;
	char			**map_2d;
	/* player */
	t_player		*player;
	/* mlx */
	t_mlx			*mlx;
	/* img */
	t_img			*img;
	t_img			text[4];
	t_color			*color;
	int				**buf;
	/* 정체불명 */
	int				height;
	int				player_cnt;
	/* key hook */
	t_key			key_flag;
}	t_game;

#endif