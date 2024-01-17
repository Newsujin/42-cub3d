/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 19:59:12 by yerilee           #+#    #+#             */
/*   Updated: 2024/01/17 20:00:13 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../executing.h"

double	ft_abs(double num)
{
	if (num < 0)
		return (-num);
	return (num);
}

bool	check_wall(t_mlx *mlx, t_dda *dda)
{
	bool	hit;

	hit = false;

	/* ... */
	(void) mlx;
	(void) dda;
	/* ... */

	return (hit);
}
