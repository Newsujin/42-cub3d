/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:50:07 by spark2            #+#    #+#             */
/*   Updated: 2024/01/24 22:16:50 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../parsing/get_next_line/get_next_line.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "executing.h"
# include "cub3d.h"
# include "struct.h"

/* check */
int		check_argv(char *argv);

/* ft_split */
void	*ft_free(char **ptr, int i);
int		cnt_word(const char *s, char c);
char	*ft_word_dup(const char *src, char c);
char	**ft_split(char const *s, char c);

/* init */
void	init_texture(t_game *game);
void	init_game(t_game *game, char *file);

/* parsing */
void	parsing(t_game *game, char *argv);

/* read_map */
void	check_dir_rgb(char *line, t_game *game, int *count);
void	read_map(t_game *game);

/* rgb */
void	check_rgb(char *line, t_game *game, int *count);

/* utils */
int		ft_free_2d(char **str, int flag);
char	*no_new_line(char *line);

#endif
