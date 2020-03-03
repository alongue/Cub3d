/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:04:58 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/03 11:49:25 by alongcha         ###   ########.fr       */
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

	printf("cond est vrai\n");
	printf("x = %d\t\tet\t\ty = %d\nmap.cub[y][x].exist = %d\n", x, y, map.cub[y][x].exist);
	if (cond_top(map, x, y))
	{
		p = create_polytop(map, x, y);
		(*c)++;
		printf("cond_top est vrai\n");
	}
	if (cond_bot(map, x, y))
	{
		p = create_polybot(map, x, y);
		(*c)++;
		printf("cond_bop est vrai\n");
	}
	if (cond_right(map, x, y))
	{
		p = create_polyright(map, x, y);
		(*c)++;
		printf("cond_right est vrai\n");
	}
	if (cond_left(map, x, y))
	{
		p = create_polyleft(map, x, y);
		(*c)++;
		printf("cond_left est vrai\n");
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
	printf("map.nbcuby = %d\t\tet\t\tmap.nbcubx = %d\n", map.nbcuby, map.nbcubx);
	while (++y < map.nbcuby/* - 1*/)
	{
		x = 0;
		while (++x < map.nbcubx/* - 1*/)
		{
			printf("map.nbcubx = %d\n", map.nbcubx);
			printf("x (dans get_malloc) = %d\n", x);
			count(map, x, y, &counter);
		}
	}
	printf("counter = %d\n", counter);
	if (!(p = malloc(sizeof(t_polygon) * counter + 1)))
		return (NULL);
	p[counter].exist = false;
	return (p);
}

t_polygon	*parse_poly(t_map map)
{
	int			x;
	int			y;
	t_polygon	*p;

	p = get_malloc(map);
	y = 0;
	while (++y < map.nbcuby/* - 1*/)
	{
		x = 0;
		while (++x < map.nbcubx/* - 1*/)
			search_polyverti(map, p, x, y);
	}
	return (p);
}
