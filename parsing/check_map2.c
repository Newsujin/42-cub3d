/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 02:33:10 by spark2            #+#    #+#             */
/*   Updated: 2024/02/04 02:38:30 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_all_direction(char **map, int i, int j)
{
	if (map[i - 1] && valid_check(map[i - 1][j]))
		error("Error\ninvalid map\n");
	else if (map[i - 1] && valid_check(map[i - 1][j - 1]))
		error("Error\ninvalid map\n");
	else if (map[i - 1] && valid_check(map[i - 1][j + 1]))
		error("Error\ninvalid map\n");
	else if (map[i] && valid_check(map[i][j - 1]))
		error("Error\ninvalid map\n");
	else if (map[i] && valid_check(map[i][j + 1]))
		error("Error\ninvalid map\n");
	else if (map[i + 1] && valid_check(map[i + 1][j]))
		error("Error\ninvalid map\n");
	else if (map[i + 1] && valid_check(map[i + 1][j - 1]))
		error("Error\ninvalid map\n");
	else if (map[i + 1] && valid_check(map[i + 1][j + 1]))
		error("Error\ninvalid map\n");
}

int	valid_check(char c)
{
	if (c == '\0' || c == ' ')
		return (1);
	return (0);
}

int	check_map_end(char *map)
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

void	find_start_end_wall(char *map)
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
		error("Error\nfirst_end_wall\n");
}
