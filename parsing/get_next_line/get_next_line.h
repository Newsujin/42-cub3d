/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 20:52:12 by spark2            #+#    #+#             */
/*   Updated: 2024/02/01 15:24:54 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

int		main_loop(char **backup, int fd, ssize_t *rd_size);
int		split_line(char **backup, char **res);
void	ft_free_gnl(char **backup, char **res);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
ssize_t	ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strjoin2(char *s1, char *s2, int s2_len, int count);

#endif