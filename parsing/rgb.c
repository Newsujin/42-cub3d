/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:29:26 by spark2            #+#    #+#             */
/*   Updated: 2024/02/06 02:58:16 by sujin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	set_rgb(int *cnt, t_game *game, char *path, char *direction)
{
	if (!(ft_strncmp(direction, "F", ft_strlen(direction))) \
		&& !game->color->floor_flag)
		put_rgb(path, cnt, game->color->floor, \
		&(game->color->floor_flag));
	else if (!(ft_strncmp(direction, "C", ft_strlen(direction))) \
		&& !game->color->ceil_flag)
		put_rgb(path, cnt, game->color->ceil, \
		&(game->color->ceil_flag));
	else
		error("rgb Error\n");
}

void	put_rgb(char *path, int *cnt, int *array, int *flag)
{
	int		i;
	int		comma;
	char	**rgb_list;

	i = 0;
	comma = 0;
	while (path[i])
	{
		if (path[i] == ',')
			comma++;
		i++;
	}
	if (comma >= 3)
		error("comma Error\n");
	rgb_list = ft_split(path, ',');
	if (!rgb_list)
		error("split Error\n");
	check_rgb_range(path);
	check_rgb_cnt(rgb_list, array);
	(*cnt)++;
	*flag = 1;
	ft_free_2d(rgb_list, 0);
}

void	check_rgb_range(char *tmp)
{
	int		i;

	i = 0;
	while (tmp[i])
	{
		if (!(tmp[i] == ',' || tmp[i] == '\n' || \
		(tmp[i] >= '0' && tmp[i] <= '9')))
			error("rgb_range Error\n");
		i++;
	}
}

void	check_rgb_cnt(char **rgb_list, int *array)
{
	int	len;

	len = 0;
	while (rgb_list[len])
		len++;
	if (len != 3)
		error("rgb_cnt Error\n");
	len = 0;
	while (rgb_list[len])
	{
		array[len] = ft_atoi(rgb_list[len]);
		len++;
	}
}

void	check_rgb(char *line, t_game *game, int *cnt)
{
	int		len;
	char	*new_line;
	char	**tmp;

	new_line = NULL;
	tmp = ft_split(line, ' ');
	if (!tmp)
		error("split Error\n");
	len = 0;
	while (tmp[len])
		len++;
	if (len == 2)
	{
		new_line = delete_new_line(tmp[1]);
		set_rgb(cnt, game, new_line, tmp[0]);
	}
	else
		error("rgb Error\n");
	ft_free_2d(tmp, 0);
	free(new_line);
}
