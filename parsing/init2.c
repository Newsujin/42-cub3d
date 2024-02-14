/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:14:32 by spark2            #+#    #+#             */
/*   Updated: 2024/02/14 21:48:00 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

char	init_player_position(t_game *game, char location, int i, int j)
{
	game->player->pos_x = i + 0.5;
	game->player->pos_y = j + 0.5;
	if (location == 'N')
	{
		game->player->dir_x = -1;
		game->player->plane_y = 0.66;
	}
	else if (location == 'S')
	{
		game->player->dir_x = 1;
		game->player->plane_y = -0.66;
	}
	else if (location == 'W')
	{
		game->player->dir_y = -1;
		game->player->plane_x = -0.66;
	}
	else if (location == 'E')
	{
		game->player->dir_y = 1;
		game->player->plane_x = 0.66;
	}
	else
		return (0);
	return (1);
}

void	init_player(t_game *game)
{
	int		i;
	int		j;

	game->player->plane_x = 0;
	game->player->plane_y = 0;
	game->player->dir_x = 0;
	game->player->dir_y = 0;
	i = 0;
	while (game->map_2d[i])
	{
		j = 0;
		while (game->map_2d[i][j])
		{
			if (init_player_position(game, game->map_2d[i][j], i, j))
				return ;
			j++;
		}
		i++;
	}
}

void	init_rgb(t_game *game)
{
	game->color->c_color = (game->color->ceil[0] << 16) | \
		(game->color->ceil[1] << 8) | game->color->ceil[2];
	game->color->f_color = (game->color->floor[0] << 16) | \
		(game->color->floor[1] << 8) | game->color->floor[2];
}

void	init_buf(t_game *game)
{
	int	i;
	int	j;

	game->buf = (int **)malloc(sizeof(int *) * HEIGHT);
	i = -1;
	while (++i < HEIGHT)
		game->buf[i] = (int *)malloc(sizeof(int) * WIDTH);
	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			game->buf[i][j] = 0;
	}
}

void	init_struct_mlx(t_game *game)
{
	init_player(game);
	init_rgb(game);
	init_buf(game);
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "cub3D");
	game->img->init = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->img->data = (int *)mlx_get_data_addr(game->img->init, \
	&(game->img->bpp), &(game->img->size_l), &(game->img->endian));
}
