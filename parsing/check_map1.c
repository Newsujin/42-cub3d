/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:04:22 by spark2            #+#    #+#             */
/*   Updated: 2024/02/06 04:40:04 by sujin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

long	go_to_first_line(char *map)
{
	long	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '\n')
			break ;
		i++;
	}
	return (i);
}

void	check_double_new_line(char *map)
{
	int		i;

	i = 0;
	while (map[i])
	{
		if (map[i] && map[i] == '\n')
			if (map[i + 1] && map[i + 1] == '\n')
				error("double new line Error\n");
		i++;
	}
}

void	check_zero(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' \
				|| map[i][j] == 'S' || map[i][j] == 'W' \
				|| map[i][j] == 'E')
				check_all_direction(map, i, j);
			j++;
		}
		i++;
	}
}

void	check_wall2(char **map)
{
	int	i;
	int	end_line;

	end_line = 0;
	while (map[end_line])
		end_line++;
	if (check_wall_top_bottom(map[0]) || \
		check_wall_top_bottom(map[end_line - 1]))
		error("wall Error\n");
	i = -1;
	while (map[++i])
	{
		if (only_space(map[i]))
			continue ;
		check_wall_left_right(map[i]);
	}
}

void	check_map_detail(t_game *game)
{
	long	location;
	int		hei;

	hei = 0;
	if (game->player_cnt >= 2 || !game->player_cnt)
		error("player_cnt Error\n");
	location = go_to_first_line(game->map);
	check_double_new_line(game->map + location);
	game->map_2d = ft_split(game->map, '\n');
	if (!game->map_2d)
		error("malloc Error\n");
	check_zero(game->map_2d); 
	check_wall2(game->map_2d);
	while (game->map_2d[hei])
		hei++;
	game->height = hei;
	free(game->map);
}
