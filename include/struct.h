/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:01:17 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/18 14:28:11 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdbool.h>
# include "../mlx/mlx.h"

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
	int		orientation;
	int		wall_height;
}	t_dda;

typedef struct s_data
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				floor;
	int				ceiling;
	char			**map;
	char			orientation;
	double			x;
	double			y;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	t_key			key_flag;
}	t_data;

typedef struct s_mlx
{
	t_data		*data;
	void		*init;
	void		*win;
}	t_mlx;

#endif