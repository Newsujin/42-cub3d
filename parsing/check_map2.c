/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_detail.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:33:10 by spark2            #+#    #+#             */
/*   Updated: 2024/02/06 04:06:30 by sujin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_all_direction(char **map, int i, int j)
{
	if (map[i - 1])
	{
		if (is_null_space(map[i - 1][j]) || is_null_space(map[i - 1][j - 1]) ||
			is_null_space(map[i - 1][j + 1]))
		error("invalid map Error\n");
	}
	else if (map[i])
	{
		if (is_null_space(map[i][j - 1]) || is_null_space(map[i][j + 1]))
			error("invalid map Error\n");
	}
	else if (map[i + 1])
	{
		if (is_null_space(map[i + 1][j]) || is_null_space(map[i + 1][j - 1]) ||
			is_null_space(map[i + 1][j + 1]))
			error("invalid map Error\n");
	}
}

int	is_null_space(char c)
{
	if (c == '\0' || c == ' ')
		return (1);
	return (0);
}

int	check_wall_top_bottom(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != ' ' && map[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	only_space(char *map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (map[i])
	{
		if (map[i] != ' ')
			flag = 0;
		i++;
	}
	return (flag);
}

void	check_wall_left_right(char *map)
{
	int	len;
	int	first_wall;

	len = ft_strlen(map);
	first_wall = 0;
	while (map[first_wall])
	{
		if (map[first_wall] == '1')
			break ;
		first_wall++;
	}
	if (map[first_wall] != '1' && map[len - 1] != '1')
		error("wall_left_right Error\n");
}
