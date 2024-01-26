/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:59:13 by spark2            #+#    #+#             */
/*   Updated: 2024/01/24 15:43:39 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

int	check_argv(char *argv)
{
	int		str;
	int		tmp_cnt;
	char	**tmp;

	tmp = ft_split(argv, '/');
	if (!tmp)
		error("Error split_argv\n");
	tmp_cnt = 0;
	while (tmp[tmp_cnt])
		tmp_cnt++;
	tmp_cnt--;
	str = ft_strlen(tmp[tmp_cnt]);
	if (str <= 4)
		return (ft_free_2d(tmp, 1));
	if (!(tmp[tmp_cnt][str - 1] == 'b' && \
		tmp[tmp_cnt][str - 2] == 'u' && \
		tmp[tmp_cnt][str - 3] == 'c' && \
		tmp[tmp_cnt][str - 4] == '.'))
		return (ft_free_2d(tmp, 1));
	return (ft_free_2d(tmp, 0));
}
