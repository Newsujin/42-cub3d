/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_overlap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 22:59:52 by spark2            #+#    #+#             */
/*   Updated: 2024/01/30 23:02:23 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	overlap_direction(char *file1, char *file2)
{
	if (!(ft_strncmp(file1, file2, ft_strlen(file2))))
		error("Error\noverlap rgb\n");
}

void	overlap_rgb(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->color->ceil[i] != game->color->floor[i])
			return ;
		i++;
	}
	error("Error\nsame rgb\n");
}

void	check_overlap(t_game *game)
{
	int		i;
	int		j;
	char	*temp[5];

	i = -1;
	temp[0] = game->text[NORTH].path;
	temp[1] = game->text[SOUTH].path;
	temp[2] = game->text[WEST].path;
	temp[3] = game->text[EAST].path;
	temp[4] = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				continue ;
			else
				overlap_direction(temp[i], temp[j]);
		}
	}
	overlap_rgb(game);
}
