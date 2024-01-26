/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:29:26 by spark2            #+#    #+#             */
/*   Updated: 2024/01/24 22:19:54 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

/* 주어진 문자열(temp)이 RGB 값으로 유효한지 확인 */
static void	check_rgb_invalid(char *temp)
{
	int		i;

	i = 0;
	while (temp[i])
	{
		if (!(temp[i] == ',' || (temp[i] >= '0' && temp[i] <= '9') || \
			temp[i] == '\n'))
			error("rgb_invalid Error\n");
		i++;
	}
}

/* 주어진 문자열 배열(temp_split)이 3개의 원소를 가지는지 확인 */
static void	check_color(char **temp_split, int *array)
{
	int	temp_string;

	temp_string = 0;
	while (temp_split[temp_string])
		temp_string++;
	if (temp_string != 3)
		error("rgb_color Error\n");
	temp_string = 0;
	while (temp_split[temp_string])
	{
		array[temp_string] = ft_atoi(temp_split[temp_string]);
		temp_string++;
	}
}

/* 주어진 문자열(temp)을 파싱하여 RGB 값을 설정 */
static void	input_rgb(char *temp, int *count, int *array, int *check)
{
	char	**comma_split;
	int		comma;
	int		i;

	i = 0;
	comma = 0;
	while (temp[i])
	{
		if (temp[i] == ',')
			comma++;
		i++;
	}
	if (comma >= 3)
		error("comma Error\n");
	check_rgb_invalid(temp);
	comma_split = ft_split(temp, ',');
	if (!comma_split)
		error("rgb_split Error\n");
	check_color(comma_split, array);
	(*count)++;
	ft_free_2d(comma_split, 0);
	*check = 1;
}

/* 설정 파일에서 읽은 한 줄(line)을 파싱하여 RGB 값을 설정 */
void	check_rgb(char *line, t_game *game, int *count)
{
	char	**temp;
	int		temp_string;
	char	*new_line;

	new_line = NULL;
	temp = ft_split(line, ' ');
	if (!temp)
		error("rgb_split Error\n");
	temp_string = 0;
	while (temp[temp_string])
		temp_string++;
	if (temp_string == 2)
		new_line = no_new_line(temp[1]);
	if (!(ft_strncmp(temp[0], "F", ft_strlen(temp[0]))) \
		&& temp_string == 2 && game->color->floor_flag == 0)
		input_rgb(new_line, count, game->color->floor, \
		&(game->color->floor_flag));
	else if (!(ft_strncmp(temp[0], "C", ft_strlen(temp[0]))) \
		&& temp_string == 2 && game->color->ceil_flag == 0)
		input_rgb(new_line, count, game->color->ceil, \
		&(game->color->ceil_flag));
	else
		error("rgb_invalid Error\n");
	ft_free_2d(temp, 0);
	free(new_line);
}
