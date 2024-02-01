/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:37:37 by spark2            #+#    #+#             */
/*   Updated: 2024/02/01 15:28:40 by spark2           ###   ########.fr       */
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

void	system_check(void)
{
	system("leaks cub3D");
}

int	main(int argc, char **argv)
{
	atexit(system_check);
	t_game	game;

	(void)argv;
	if (argc != 2 || check_argv(argv[1]))
		error("Error\n");
	parsing(&game, argv[1]);
	executing(&game);
}
