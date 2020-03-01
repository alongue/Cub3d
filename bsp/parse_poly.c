/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:04:58 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/01 14:10:43 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		search_polyverti(t_map map, t_polygon *p, int x, int y)
{
	static int i = 0;

	if (cond_top(map, x, y))
	{
		p[i].isused = false;
		p[i++] = create_polytop(map, x, y);
	}
	if (cond_bot(map, x, y))
	{
		p[i].isused = false;
		p[i++] = create_polybot(map, x, y);
	}
	if (cond_right(map, x, y))
	{
		p[i].isused = false;
		p[i++] = create_polyright(map, x, y);
	}
	if (cond_left(map, x, y))
	{
		p[i].isused = false;
		p[i++] = create_polyleft(map, x, y);
	}
}

int			count(t_map map, int x, int y, int *c)
{
	t_polygon	p;

	if (cond_top(map, x, y))
	{
		p = create_polytop(map, x, y);
		(*c)++;
	}
	if (cond_bot(map, x, y))
	{
		p = create_polybot(map, x, y);
		(*c)++;
	}
	if (cond_right(map, x, y))
	{
		p = create_polyright(map, x, y);
		(*c)++;
	}
	if (cond_left(map, x, y))
	{
		p = create_polyleft(map, x, y);
		(*c)++;
	}
	return (*c);
}

t_polygon	*get_malloc(t_map map)
{
	int			x;
	int			y;
	int			counter;
	t_polygon	*p;

	counter = 0;
	y = 0;
	while (++y < map.nbcuby)
	{
		x = 0;
		while (++x < map.nbcubx)
			count(map, x, y, &counter);
	}
	if (!(p = malloc(sizeof(t_polygon) * counter)))
		return (NULL);
	return (p);
}

t_polygon	*parse_poly(t_map map)
{
	int			x;
	int			y;
	t_polygon	*p;

	p = get_malloc(map);
	y = 0;
	while (++y < map.nbcuby)
	{
		x = 0;
		while (++x < map.nbcubx)
			search_polyverti(map, p, x, y);
	}
	return (p);
}
