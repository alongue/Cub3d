/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 17:50:59 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/12 17:51:14 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		check_outside(int *x, int y, int *i, char *map_number)
{
	int		boundend;
	int		max;
	char	**xtreme;
	char	**boundy;

	if (!(xtreme = xtreme_sorted_y(y, &boundend)) ||
	!(boundy = get_all_boundy(y, &max, xtreme, boundend)))
		return (ft_putstrreti_fd(MALLOC, 1, STDOUT_FILENO));
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
			return (free_boundy(1, boundy, max, WALL));
	}
	return (free_boundy(0, boundy, max, NULL));
}

int		is_outside_xboundaries(int y, t_map map)
{
	int		i;
	int		x;

	x = -1;
	i = 0;
	while (++x <= get_line_nbmax(map.number, y))
		if (check_outside(&x, y, &i, map.number[y]))
		{
			free_xtreme(NULL, NULL, 2);
			return (1);
		}
	return (0);
}
