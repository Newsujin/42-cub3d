/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:09 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/17 19:19:26 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void)argv;
	if (argc != 2)
		error("Error\n");
	// argv[1] 입력값 유효성 체크 추가하기

	// init_data(data, argv[1])
	// parsing
	executing(&data);
}