/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:09:53 by spark2            #+#    #+#             */
/*   Updated: 2024/01/30 22:47:50 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	put_mlx_img(t_game *game, char *path, t_img *img)
{
	int	wid;
	int	hei;

	img->init = NULL;
	img->init = mlx_xpm_file_to_image(game->mlx->init, path, &wid, &hei);
	if (!img->init)
		error("Error\nput_mlx_img\n");
	img->data = (int *)mlx_get_data_addr(img->init, &(img->bpp), \
		&(img->size_l), &(img->endian));
	if (!img->data)
		error("Error\nput_mlx_img\n");
}

void	put_img(int *count, t_game *game, char *temp, int flag)
{
	char	*copy;

	copy = ft_strcpy(temp);
	if (flag == NORTH)
	{
		put_mlx_img(game, temp, &(game->text[NORTH]));
		game->text[NORTH].path = copy;
	}
	else if (flag == SOUTH)
	{
		put_mlx_img(game, temp, &(game->text[SOUTH]));
		game->text[SOUTH].path = copy;
	}
	else if (flag == EAST)
	{
		put_mlx_img(game, temp, &(game->text[EAST]));
		game->text[EAST].path = copy;
	}
	else if (flag == WEST)
	{
		put_mlx_img(game, temp, &(game->text[WEST]));
		game->text[WEST].path = copy;
	}
	(*count)++;
}

void	check_extension(char *file)
{
	int	length;

	length = ft_strlen(file);
	if (length <= 4)
		error("Error\nextension\n");
	if (!(file[length - 1] == 'm' && file[length - 2] == 'p' \
		&& file[length - 3] == 'x' && file[length - 4] == '.'))
		error("Error\nextension\n");
}

void	direction_chose(int	*count, t_game *game, char *new_line, char *temp)
{
	if (!(ft_strncmp(temp, "NO", ft_strlen(temp))) && \
		!(game->text[NORTH].path))
		put_img(count, game, new_line, NORTH);
	else if (!(ft_strncmp(temp, "SO", ft_strlen(temp))) \
		&& !(game->text[SOUTH].path))
		put_img(count, game, new_line, SOUTH);
	else if (!(ft_strncmp(temp, "WE", ft_strlen(temp))) \
		&& !(game->text[WEST].path))
		put_img(count, game, new_line, WEST);
	else if (!(ft_strncmp(temp, "EA", ft_strlen(temp))) \
		&& !(game->text[EAST].path))
		put_img(count, game, new_line, EAST);
	else
		error("Error\ndirection\n");
}

void	check_direction(char *line, t_game *game, int *count)
{
	char	**temp;
	int		temp_string;
	char	*new_line;

	new_line = NULL;
	temp = ft_split(line, ' ');
	if (!temp)
		error("Error\ndirection\n");
	temp_string = 0;
	while (temp[temp_string])
		temp_string++;
	if (temp_string == 2)
	{
		new_line = no_new_line(temp[1]);
		check_extension(new_line);
	}
	if (temp_string == 2)
		direction_chose(count, game, new_line, temp[0]);
	else
		error("Error\ndirection\n");
	ft_free_2d(temp, 0);
	free(new_line);
}
