/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:37:09 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/24 21:26:30 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3d.h"

void	error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	exit(0); //에러인데 0 반환인 이유?
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_game	game;

	(void)argv;
	if (argc != 2 || check_argv(argv[1]))
		error("Error\n");
	parsing(&game, argv[1]);
	executing(&data);
}
