/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:02:17 by spark2            #+#    #+#             */
/*   Updated: 2024/02/14 22:40:11 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	check_argv(char *argv)
{
	int		str;
	int		cnt;
	char	**tmp;

	tmp = ft_split(argv, '/');
	if (!tmp)
		error("Error\ncheck_argv\n");
	cnt = 0;
	while (tmp[cnt])
		cnt++;
	cnt--;
	str = ft_strlen(tmp[cnt]);
	if (str <= 4)
		return (ft_free_2d(tmp, 1));
	if (!(tmp[cnt][str - 1] == 'b' && \
		tmp[cnt][str - 2] == 'u' && \
		tmp[cnt][str - 3] == 'c' && \
		tmp[cnt][str - 4] == '.'))
		return (ft_free_2d(tmp, 1));
	return (ft_free_2d(tmp, 0));
}

void	parsing(t_game *game, char *argv)
{
	init_game(game, argv);
	init_img(game);
	game->mlx = mlx_init();
	if (!game->mlx)
		error("Error\nmlx\n");
	read_map(game);
	if (!game->map)
		error("Error\nmap\n");
	check_map_detail(game);
	check_dup(game);
	init_struct_mlx(game);
}
