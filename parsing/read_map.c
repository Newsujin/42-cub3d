/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:11:35 by spark2            #+#    #+#             */
/*   Updated: 2024/02/14 22:40:29 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	check_ewsn_rgb(char *line, t_game *game, int *cnt)
{
	char	**tmp;

	if (line[0] == '\n' && !(line[1]))
		return ;
	if (only_space(line))
		error("Error\nonly space\n");
	tmp = ft_split(line, ' ');
	if (!tmp)
		error("Error\nsplit\n");
	if (!(ft_strncmp(tmp[0], "EA", 2)) || \
		!(ft_strncmp(tmp[0], "WE", 2)) || \
		!(ft_strncmp(tmp[0], "SO", 2)) || \
		!(ft_strncmp(tmp[0], "NO", 2)))
		check_ewsn(line, game, cnt);
	else if (!(ft_strncmp(tmp[0], "C", 1)) || \
		!(ft_strncmp(tmp[0], "F", 1)))
		check_rgb(line, game, cnt);
	else
		error("Error\ninvalid ewsn rgb\n");
	ft_free_2d(tmp, 0);
}

void	check_map(char *line, char **map_buf, t_game *game)
{
	char	*tmp;

	tmp = *map_buf;
	if (check_map_value(line, game))
		*map_buf = ft_strjoin_free(tmp, line, ft_strlen(line), ft_strlen(tmp));
	else
		ft_error(map_buf, line);
}

int	check_map_value(char *line, t_game *game)
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(line))
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == ' ' \
			|| line[i] == '\n')
			continue ;
		else if (line[i] == 'E' || line[i] == 'W' || \
			line[i] == 'S' || line[i] == 'N')
			game->player_cnt++;
		else
			return (0);
	}
	return (1);
}

void	read_map(t_game *game)
{
	int		cnt;
	char	*line;

	cnt = 0;
	line = NULL;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		if (cnt <= 5)
			check_ewsn_rgb(line, game, &cnt);
		else
			check_map(line, &game->map, game);
		free(line);
		line = NULL;
	}
	close(game->fd);
	free(line);
}
