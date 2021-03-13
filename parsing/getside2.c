/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getside2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 15:54:15 by user42            #+#    #+#             */
/*   Updated: 2021/03/12 15:54:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	init_getside(int *coor, int *ycop, int *side, int *static_outside)
{
	if (*ycop != coor[1])
	{
		*ycop = coor[1];
		*static_outside = BLOCKED;
		*side = BLOCKED;
	}
}

int		start_from_up(int *coor, int *side, int *static_outside, int oldside)
{
	char	*b4_xtreme;

	b4_xtreme = get_xtreme(coor[0], coor[1] - 1);
	if (ft_atoi(&b4_xtreme[4]) != BLOCKED)
	{
		*side = TOP;
		*static_outside = oldside;
		free(b4_xtreme);
		if (oldside == 1)
			return (!oldside);
		else
			return (oldside);
	}
	return (-1);
}

int		start_from_down(int *coor, int *side, int *static_outside, int oldside)
{
	char	*b4_xtreme;

	b4_xtreme = get_xtreme(coor[0], coor[1] + 1);
	if (ft_atoi(&b4_xtreme[4]) != BLOCKED)
	{
		*side = BOT;
		*static_outside = oldside;
		free(b4_xtreme);
		if (oldside == 1)
			return (!oldside);
		else
			return (oldside);
	}
	return (-1);
}
