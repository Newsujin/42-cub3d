/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:50:07 by spark2            #+#    #+#             */
/*   Updated: 2024/02/01 13:55:29 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../parsing/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include "executing.h"
# include "cub3d.h"
# include "struct.h"


/* check_map2 */
int		check_map_end(char *map);
void	find_start_end_wall(char *map);
int		only_space(char *map);
void	check_wall2(char **map);
long	go_to_second_line(char *map);
void	check_double_new_line(char	*map);
void	check_map2(t_game *game);

/* check_overlap */
void	overlap_direction(char *file1, char *file2);
void	overlap_rgb(t_game *game);
void	check_overlap(t_game *game);


/* check */
int		check_argv(char *argv);

/* direction */
void	put_mlx_img(t_game *game, char *path, t_img *img);
void	put_img(int *count, t_game *game, char *temp, int flag);
void	check_extension(char *file);
void	direction_chose(int	*count, t_game *game, char *new_line, char *temp);
void	check_direction(char *line, t_game *game, int *count);

/* ft_split */
void	*ft_free(char **ptr, int i);
int		cnt_word(const char *s, char c);
char	*ft_word_dup(const char *src, char c);
char	**ft_split(char const *s, char c);

/* init */
void	init_texture(t_game *game);
void	init_rgb(t_game *game);
void	init_buf(t_game *game);
char	find_location(t_game *game, char location, int i, int j);
void	init_player(t_game *game);
void	init_game(t_game *game, char *file);

/* parsing */
void	parsing(t_game *game, char *argv);

/* read_map */
void	check_dir_rgb(char *line, t_game *game, int *count);
int		check_line(char *line, int line_len, t_game *game);
int		check_map(char *line, char **map_buf, t_game *game);
void	read_map(t_game *game);

/* rgb */
void	check_rgb(char *line, t_game *game, int *count);

/* utils */
int		ft_free_2d(char **str, int flag);
char	*no_new_line(char *line);

/* libft */
int		ft_atoi(const char *str);
char	*ft_strcpy(const char *string);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
