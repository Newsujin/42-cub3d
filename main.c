/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujin <sujin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:37:37 by spark2            #+#    #+#             */
/*   Updated: 2024/02/06 03:40:28 by sujin            ###   ########.fr       */
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
	exit(1);
}

void	system_check(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	atexit(system_check);
	t_game	game;

	if (argc != 2 || check_argv(argv[1]))
		error("arg Error\n");
	parsing(&game, argv[1]);
	executing(&game);
}
