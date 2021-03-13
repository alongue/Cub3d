/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:50:59 by user42            #+#    #+#             */
/*   Updated: 2021/03/12 17:51:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	check_outside(int *x, int y, int *i, char *map_number)
{
	int		boundend;
	int		max;
	char	**xtreme;
	char	**boundy;

	xtreme = xtreme_sorted_y(y, &boundend);
	boundy = get_all_boundy(y, &max, xtreme, boundend);
	if (*i < max && *x == get_xtreme_x(boundy[*i]))
	{
		if (ft_atoi(&boundy[*i][4]) == BLOCKED)
			(*i)++;
		else
		{
			if (*i + 1 < max)
				*x = get_xtreme_x(boundy[*i + 1]);
			*i += 2;
		}
	}
	else
	{
		if (map_number[*x] != ' ' && !is_boundaries(*x, y))
			return (1);
	}
	return (0);
}

int		is_outside_xboundaries(int y, t_map map)
{
	int		i;
	int		x;

	x = -1;
	i = 0;
	while (++x <= get_line_nbmax(map.number, y))
		if (check_outside(&x, y, &i, map.number[y]))
			return (1);
	return (0);
}
