/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:24:30 by spark2            #+#    #+#             */
/*   Updated: 2024/02/14 22:39:08 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	is_null_space(char c)
{
	if (c == '\0' || c == ' ')
		return (1);
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
		error("Error\nwall_left_right\n");
}

void	check_wall_valid(char **map)
{
	int	i;
	int	end_line;

	end_line = 0;
	while (map[end_line])
		end_line++;
	if (check_wall_top_bottom(map[0]) || \
		check_wall_top_bottom(map[end_line - 1]))
		error("Error\nwall\n");
	i = -1;
	while (map[++i])
	{
		if (only_space(map[i]))
			continue ;
		check_wall_left_right(map[i]);
	}
}
