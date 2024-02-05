/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:02:17 by spark2            #+#    #+#             */
/*   Updated: 2024/02/06 04:08:08 by sujin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	parsing(t_game *game, char *argv)
{
	init_game(game, argv);
	game->mlx = mlx_init();
	if (!game->mlx)
		error("mlx Error\n");
	read_map(game);
	if (!game->map)
		error("map Error\n");
	check_map_detail(game);
	check_dup(game);
	init_struct_mlx(game);
	}
