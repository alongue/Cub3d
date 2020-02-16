/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:04:58 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 18:14:09 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		search_polyverti(t_polygon *p, t_map map, int x, int y)
{
	static int i = 0;

	if (cond_top)
		p[i++] = create_polytop(map, x, y);
	if (cond_bot)
		p[i++] = create_polybot(map, x, y);
	if (cond_right)
		p[i++] = create_polyright(map, x, y);
	if (cond_left)
		p[i++] = create_polyleft(map, x, y);
	return (p);
}

int			count(t_map map)
{
	int		counter;

	counter = 0;

	return (counter);
}

t_polygon	*parse_poly(t_map map)
{
	int			x;
	int			y;
	t_polygon	*p;

	y = 0;
	while (++y < map.nbcuby)
	{
		x = 0;
		while (++x < map.nbcubx)
				search_polyverti(map, &x, &y, p);
	}
	return (p);
}
