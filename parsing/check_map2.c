/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 23:04:22 by spark2            #+#    #+#             */
/*   Updated: 2024/02/01 14:40:14 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	valid_check(char c)
{
	if (c == '\0' || c == ' ')
		return (1);
	return (0);
}

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

void	check_wall2(char **map)
{
	int	i;
	int	end_line;

	end_line = 0;
	while (map[end_line])
		end_line++;
	if (check_map_end(map[0]) || check_map_end(map[end_line - 1]))
		error("Error\nwall\n");
	i = -1;
	while (map[++i])
	{
		if (only_space(map[i]) == 1)
			continue ;
		find_start_end_wall(map[i]);
	}
}

long	go_to_second_line(char *map)
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

void	check_double_new_line(char	*map)
{
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strcpy(map);
	while (temp[i])
	{
		if (temp[i] && temp[i] == '\n')
			if (temp[i + 1] && temp[i + 1] == '\n')
				error("Error\nmap\n");
		i++;
	}
	free(temp);
}

void	check_map2(t_game *game)
{
	char	**map_2d;
	long	location;
	int		hei;

	hei = 0;
	if (game->player_cnt >= 2 || game->player_cnt == 0)
		error("Error\nplay_direction\n");
	location = go_to_second_line(game->map);
	check_double_new_line(game->map + location);
	map_2d = ft_split(game->map, '\n');
	if (map_2d == (void *)0)
		error("Error\nmap malloc fail\n");
	check_zero(map_2d);
	check_wall2(map_2d);
	game->map_2d = map_2d;
	while (game->map_2d[hei])
		hei++;
	game->height = hei;
	free(game->map);
}
