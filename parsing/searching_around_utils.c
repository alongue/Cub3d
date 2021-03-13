/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching_around_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 18:11:42 by user42            #+#    #+#             */
/*   Updated: 2021/03/12 18:11:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		get_location(int moving_side)
{
	if (moving_side == RIGHT)
		return (TOP);
	else if (moving_side == LEFT)
		return (BOT);
	else if (moving_side == TOP)
		return (LEFT);
	else if (moving_side == BOT)
		return (RIGHT);
	return (BLOCKED);
}

int		remind(int x, int y)
{
	char	**xtreme;
	int		boundend;
	int		i;

	xtreme = recover_xtreme(NULL, &boundend, 0);
	i = -1;
	while (++i < boundend)
	{
		if (x == get_xtreme_x(xtreme[i]) && y == get_xtreme_y(xtreme[i]))
			return (i);
	}
	return (-1);
}