/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:36:08 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/15 15:57:11 by yerilee          ###   ########.fr       */
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

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*map;
	int			fd;
}	t_game;

#endif