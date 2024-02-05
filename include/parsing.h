/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:50:07 by spark2            #+#    #+#             */
/*   Updated: 2024/02/06 04:43:27 by sujin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../parsing/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include "executing.h"
# include "cub3d.h"
# include "struct.h"

/* check_dup */
void	check_ewsn_dup(char *file1, char *file2);
void	check_rgb_dup(t_game *game);
void	check_dup(t_game *game);

/* check_map1 */
long	go_to_first_line(char *map);
void	check_double_new_line(char *map);
void	check_zero(char **map);
void	check_wall2(char **map);
void	check_map_detail(t_game *game);

/* check_map2 */
void	check_all_direction(char **map, int i, int j);
int		is_null_space(char c);
int		check_wall_top_bottom(char *map);
int		only_space(char *map);
void	check_wall_left_right(char *map);

/* check */
int		check_argv(char *argv);

/* ewsn */
void	check_extension(char *file);
void	set_ewsn(int *cnt, t_game *game, char *path, char *direction);
void	put_ewsn_img(int *cnt, t_game *game, char *path, int direction);
void	put_mlx_img(t_game *game, char *path, t_img *img);
void	check_ewsn(char *line, t_game *game, int *count);

/* ft_split */
void	*ft_free(char **ptr, int i);
int		cnt_word(const char *s, char c);
char	*ft_word_dup(const char *src, char c);
char	**ft_split(char const *s, char c);

/* init1 */
void	init_texture(t_game *game);
void	init_game(t_game *game, char *file);

/* init2 */
char	find_location(t_game *game, char location, int i, int j);
void	init_player(t_game *game);
void	init_rgb(t_game *game);
void	init_buf(t_game *game);
void	init_struct_mlx(t_game *game);

/* parsing */
void	parsing(t_game *game, char *argv);

/* read_map */
void	check_ewsn_rgb(char *line, t_game *game, int *count);
void	check_map(char *line, char **map_buf, t_game *game);
int		check_map_value(char *line, t_game *game);
void	read_map(t_game *game);

/* rgb */
void	set_rgb(int *cnt, t_game *game, char *path, char *direction);
void	put_rgb(char *path, int *cnt, int *array, int *flag);
void	check_rgb_range(char *tmp);
void	check_rgb_cnt(char **rgb_list, int *array);
void	check_rgb(char *line, t_game *game, int *cnt);

/* utils */
int		ft_free_2d(char **str, int flag);
char	*delete_new_line(char *line);
char	*ft_strjoin_free(char *s1, char *s2, int s2_len, int count);
void    ft_error(char **map_buf, char *line);

/* libft */
int		ft_atoi(const char *str);
char	*ft_strcpy(const char *string);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
