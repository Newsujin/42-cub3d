/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:23:46 by spark2            #+#    #+#             */
/*   Updated: 2024/02/14 22:38:54 by spark2           ###   ########.fr       */
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
				error("Error\ndouble new line\n");
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

void	check_all_direction(char **map, int i, int j)
{
	if (map[i - 1])
	{
		if (is_null_space(map[i - 1][j]) || is_null_space(map[i - 1][j - 1]) ||
			is_null_space(map[i - 1][j + 1]))
			error("Error\ninvalid map\n");
	}
	else if (map[i])
	{
		if (is_null_space(map[i][j - 1]) || is_null_space(map[i][j + 1]))
			error("Error\ninvalid map\n");
	}
	else if (map[i + 1])
	{
		if (is_null_space(map[i + 1][j]) || is_null_space(map[i + 1][j - 1]) ||
			is_null_space(map[i + 1][j + 1]))
			error("Error\ninvalid map\n");
	}
}

void	check_map_detail(t_game *game)
{
	long	location;
	int		h;

	h = 0;
	if (game->player_cnt >= 2 || !game->player_cnt)
		error("Error\nplayer_cnt\n");
	location = go_to_first_line(game->map);
	check_double_new_line(game->map + location);
	game->map_2d = ft_split(game->map, '\n');
	if (!game->map_2d)
		error("Error\nmalloc\n");
	check_zero(game->map_2d);
	check_wall_valid(game->map_2d);
	while (game->map_2d[h])
		h++;
	game->height = h;
	free(game->map);
}
