/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:59:13 by spark2            #+#    #+#             */
/*   Updated: 2024/02/05 23:51:33 by sujin            ###   ########.fr       */
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
		error("check_argv Error\n");
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
