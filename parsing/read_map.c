/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:11:35 by spark2            #+#    #+#             */
/*   Updated: 2024/01/26 22:12:36 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

/* 동서남북 or 천장,바닥 값 체크 */
void	check_dir_rgb(char *line, t_game *game, int *count)
{
	char	**tmp;

	tmp = ft_split(line, ' ');
	if (tmp == (void *)0 || tmp[0] == (void *)0)
		error("dir_rgb_split Error\n");
	/* 개행만 있는 행 -> 에러 처리 */
	if (line[0] == '\n' && !(line[1]))
	{
		ft_free_2d(tmp, 0);
		return ;
	}
	else if (!(ft_strncmp(tmp[0], "F", 1)) || \
		!(ft_strncmp(tmp[0], "C", 1)))
		check_rgb(line, game, count);
	// else if (!(ft_strncmp(tmp[0], "NO", 2)) || \
	// 	!(ft_strncmp(tmp[0], "SO", 2)) || \
	// 	!(ft_strncmp(tmp[0], "WE", 2)) || \
	// 	!(ft_strncmp(tmp[0], "EA", 2)))
	// 	check_direction(line, game, count);
	else
		error("invalid dir_rgb Error\n");
	ft_free_2d(tmp, 0);
}

/* map 한 줄씩 읽기 */
void	read_map(t_game *game)
{
	char	*map_buf;
	char	*line;
	int		cnt;

	map_buf = NULL;
	line = NULL;
	cnt = 0;
	while (1)
	{
		line = get_next_line(game->fd);
		if (!line)
			break ;
		if (cnt <= 5)
			check_dir_rgb(line, game, &cnt);
		// else
		// 	if (check_map(&line, &map_buf, game) == 1)
		// 		error("invalid input map Error\n");
		free(line);
		line = NULL;
	}
	close(game->fd);
	game->map = map_buf;
	free(line);
}
