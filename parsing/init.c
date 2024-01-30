/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:51:35 by spark2            #+#    #+#             */
/*   Updated: 2024/01/30 22:58:23 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->text[i].path = NULL;
		game->text[i].init = NULL;
		game->text[i].data = NULL;
		i++;
	}
}

void	init_mlx(t_game *game)
{
	t_mlx	mlx;

	mlx.init = mlx_init();
	if (game->mlx->init == (void *)0)
		error("Error\nmlx\n");
	mlx.win = mlx_new_window(mlx.init, WIDTH, HEIGHT, "cub3D");
	game->mlx = &mlx;
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
	i = 0;
	while (i < HEIGHT)
	{
		game->buf[i] = (int *)malloc(sizeof(int) * WIDTH);
		i++;
	}
	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			game->buf[i][j] = 0;
			j++;
		}
		i++;
	}
}

char	find_location(t_game *game, char location, int i, int j)
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
			if (find_location(game, game->map_2d[i][j], i, j))
				return ;
			j++;
		}
		i++;
	}
}

void	init_game(t_game *game, char *file)
{
	game->map = NULL;
	game->map_2d = NULL;
	game->height = 0;
	game->player_cnt = 0;
	game->fd = open(file, O_RDONLY);
	if (game->fd < 0)
		error("open Error\n");
	game->color = (t_color *)malloc(sizeof(t_color));
	game->player = (t_player *)malloc(sizeof(t_player));
	game->img = (t_img *)malloc(sizeof(t_img));
	if (game->color == (void *)0 || game->player == (void *)0 || \
		game->img == (void *)0)
		error("malloc Error\n");
	init_texture(game);
	init_mlx(game);
	game->color->ceil_flag = 0;
	game->color->floor_flag = 0;
}
