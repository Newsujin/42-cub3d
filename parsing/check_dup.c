/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 03:52:20 by sujin             #+#    #+#             */
/*   Updated: 2024/02/06 03:57:43 by sujin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_ewsn_dup(char *file1, char *file2)
{
	if (!(ft_strncmp(file1, file2, ft_strlen(file2))))
		error("ewsn file dup Error\n");
}

void	check_rgb_dup(t_game *game)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (game->color->ceil[i] != game->color->floor[i])
			return ;
		i++;
	}
	error("rgb dup Error\n");
}

void	check_dup(t_game *game)
{
	int		i;
	int		j;
	char	*tmp[5];

	i = -1;
	tmp[0] = game->text[NORTH].path;
	tmp[1] = game->text[SOUTH].path;
	tmp[2] = game->text[WEST].path;
	tmp[3] = game->text[EAST].path;
	tmp[4] = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (i == j)
				continue ;
			else
				check_ewsn_dup(tmp[i], tmp[j]);
		}
	}
	check_rgb_dup(game);
}
