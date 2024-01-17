/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:01:17 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/17 15:01:57 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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