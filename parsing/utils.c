/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:20:04 by spark2            #+#    #+#             */
/*   Updated: 2024/02/14 22:41:25 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	ft_free_2d(char **str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (flag);
}

char	*delete_new_line(char *line)
{
	int		i;
	char	*res;

	if (!line)
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	i = 0;
	while (line[i])
	{
		res[i] = line[i];
		if (line[i] == '\n')
			break ;
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strjoin_free(char *s1, char *s2, int s2_len, int cnt)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char *)malloc(sizeof(char) * (cnt + s2_len + 1));
	if (!tmp)
	{
		free(s1);
		return (0);
	}
	while (i < cnt)
	{
		tmp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		tmp[cnt + i] = s2[i];
		i++;
	}
	tmp[cnt + i] = '\0';
	free(s1);
	s1 = NULL;
	return (tmp);
}

void	ft_error(char **map_buf, char *line)
{
	free(*map_buf);
	free(line);
	*map_buf = NULL;
	line = NULL;
	error("Error\ninvalid map\n");
}
