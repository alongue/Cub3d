/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:04:58 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/15 13:05:00 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool		cond_horizontal(t_cub main, t_cub top, t_cub topleft, t_cub left)
{
	if (!main)
		return (false);
	if (left && !top && !topleft)
		return (true);
	return (false);
}

bool		cond_vertical(t_cub main, t_cub top, t_cub topleft, t_cub left)
{
	if (!main)
		return (false);
	if (!left && !topleft && top)
		return (true);
	return (false);
}

int			count(t_map map)
{
	int		counter;

	counter = 0;

	return (counter);
}

t_polygon	search_poly(t_map map, int x, int y)
{
	static t_polygon	p;

	while (cond_horizontal(map.cub[x][y], map.cub[x][y - 1], map.cub[x - 1][y - 1], map.cub[x - 1][y]))
	{
		p[i]->segment = join_segment(map.cub[x][y]->stop, map.cub[x - 1][y]->stop);
		p[i]->normal = get_normal(map.cub[x][y]->stop);
		x++;
		if (!cond_horizontal(map.cub[x][y], map.cub[x][y - 1], map.cub[x - 1][y - 1], map.cub[x - 1][y]))
			return (p);
	}
	return (p);
}

t_polygon	*parse_poly(t_map map)
{
	int			x;
	int			y;
	t_polygon	*p;
	int			i;

	y = 1;
	i = 0;
	while (y < map.counterx)
	{
		x = 1;
		while (x < map.countery)
		{
			p[i] = search_poly(map, x, y);
			x++;
		}
		y++;
	}
	return (p);
}
