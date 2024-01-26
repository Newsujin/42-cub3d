/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 13:02:17 by spark2            #+#    #+#             */
/*   Updated: 2024/01/26 20:52:46 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parsing.h"

void	parsing(t_game *game, char *argv)
{
	init_game(game, argv);
	read_map(game);
	if (game->map == (void *)0)
		error("Error\nmap\n");
}
