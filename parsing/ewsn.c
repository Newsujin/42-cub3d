/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ewsn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:09:53 by spark2            #+#    #+#             */
/*   Updated: 2024/02/06 02:59:41 by sujin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_extension(char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len <= 4 || (!(line[len - 1] == 'm' && line[len - 2] == 'p' \
		&& line[len - 3] == 'x' && line[len - 4] == '.')))
		error("extension Error\n");
}

void	set_ewsn(int *cnt, t_game *game, char *path, char *direction)
{
	if (!(ft_strncmp(direction, "EA", ft_strlen(direction))) \
		&& !(game->text[EAST].path))
		put_ewsn_img(cnt, game, path, EAST);
	else if (!(ft_strncmp(direction, "WE", ft_strlen(direction))) \
		&& !(game->text[WEST].path))
		put_ewsn_img(cnt, game, path, WEST);
	else if (!(ft_strncmp(direction, "SO", ft_strlen(direction))) \
		&& !(game->text[SOUTH].path))
		put_ewsn_img(cnt, game, path, SOUTH);
	else if (!(ft_strncmp(direction, "NO", ft_strlen(direction))) \
		&& !(game->text[NORTH].path))
		put_ewsn_img(cnt, game, path, NORTH);
	else
		error("ewsn Error\n");
}

void	put_ewsn_img(int *cnt, t_game *game, char *path, int direction)
{
	char	*path_cpy;

	path_cpy = ft_strcpy(path);
	if (direction == EAST)
	{
		put_mlx_img(game, path, &(game->text[EAST]));
		game->text[EAST].path = path_cpy;
	}
	else if (direction == WEST)
	{
		put_mlx_img(game, path, &(game->text[WEST]));
		game->text[WEST].path = path_cpy;
	}
	else if (direction == SOUTH)
	{
		put_mlx_img(game, path, &(game->text[SOUTH]));
		game->text[SOUTH].path = path_cpy;
	}
	else if (direction == NORTH)
	{
		put_mlx_img(game, path, &(game->text[NORTH]));
		game->text[NORTH].path = path_cpy;
	}
	(*cnt)++;
}

void	put_mlx_img(t_game *game, char *path, t_img *img)
{
	int	w;
	int	h;

	img->init = NULL;
	img->init = mlx_xpm_file_to_image(game->mlx, path, &w, &h);
	if (!img->init)
		error("put_mlx_img Error\n");
	img->data = (int *)mlx_get_data_addr(img->init, &(img->bpp), \
		&(img->size_l), &(img->endian));
	if (!img->data)
		error("put_mlx_img Error\n");
}

void	check_ewsn(char *line, t_game *game, int *cnt)
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
		check_extension(new_line);
		set_ewsn(cnt, game, new_line, tmp[0]);
	}
	else
		error("ewsn Error\n");
	ft_free_2d(tmp, 0);
	free(new_line);
}
