/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:20:04 by spark2            #+#    #+#             */
/*   Updated: 2024/02/02 21:16:28 by yerilee          ###   ########.fr       */
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

char	*no_new_line(char *line)
{
	int		i;
	char	*no_newline;

	if (!line)
		return (NULL);
	no_newline = (char *)malloc(sizeof(char) * (ft_strlen(line) + 1));
	i = 0;
	while (line[i])
	{
		no_newline[i] = line[i];
		if (line[i] == '\n')
			break ;
		i++;
	}
	no_newline[i] = '\0';
	return (no_newline);
}

char	*ft_strjoin2(char *s1, char *s2, int s2_len, int count)
{
	char	*temp;
	int		i;

	i = 0;
	temp = (char *)malloc(sizeof(char) * (count + s2_len + 1));
	if (!temp)
	{
		free(s1);
		return (0);
	}
	while (i < count)
	{
		temp[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		temp[count + i] = s2[i];
		i++;
	}
	temp[count + i] = '\0';
	free(s1);
	s1 = NULL;
	return (temp);
}
