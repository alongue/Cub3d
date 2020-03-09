/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:04:58 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/08 17:15:37 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void		search_polyverti(t_map map, t_polygon *p, int *coor, t_player player)
{
	static int	i = 0;
	int			*x;
	int			*y;

	x = &coor[0];
	y = &coor[1];
	if (cond_top(map, *x, *y))
	{
		p[i].isused = false;
		p[i++] = create_polytop(map, *x, *y, player);
		printf("i = %d\n", i);
	}
	if (cond_bot(map, *x, *y))
	{
		p[i].isused = false;
		p[i++] = create_polybot(map, *x, *y, player);
		printf("i = %d\n", i);
	}
	if (cond_right(map, *x, *y))
	{
		p[i].isused = false;
		p[i++] = create_polyright(map, *x, *y, player);
		printf("i = %d\n", i);
	}
	if (cond_left(map, *x, *y))
	{
		p[i].isused = false;
		p[i++] = create_polyleft(map, *x, *y, player);
		printf("i = %d\n", i);
	}
	//printf("fin !\n");
}

void		create_polywall(t_map map, t_polygon *p, t_player player, int *coor)
{
	int	x;
	int	y;
	int	i;

	x = coor[0]; //enelver tous les trucs comme ca
	y = coor[1];
	i = coor[2];
	printf("i (dans create_poly_wall) = %d\n", i);
	if (cond_top(map, x, y))
	{
		replace_poly(&p[i], player);
		printf("p[i].newsegment.a.x = %d\n", p[i].newsegment.a.x);
		p[i].dodisplay = do_display_poly(&p[i]);
		p[i].wall = create_wall(p[i], player, map.cub[0][0]);
		i++; //enlever toutes les incrementations comme ca
	}
	if (cond_bot(map, x, y))
	{
		replace_poly(&p[i], player);
		printf("p[i].newsegment.a.x = %d\n", p[i].newsegment.a.x);
		p[i].dodisplay = do_display_poly(&p[i]);
		p[i].wall = create_wall(p[i], player, map.cub[0][0]);
		i++;
	}
	if (cond_right(map, x, y))
	{
		replace_poly(&p[i], player);
		printf("p[i].newsegment.a.x = %d\n", p[i].newsegment.a.x);
		p[i].dodisplay = do_display_poly(&p[i]);
		p[i].wall = create_wall(p[i], player, map.cub[0][0]);
		i++;
	}
	if (cond_left(map, x, y))
	{
		replace_poly(&p[i], player);
		printf("p[i].newsegment.a.x = %d\n", p[i].newsegment.a.x);
		p[i].dodisplay = do_display_poly(&p[i]);
		p[i].wall = create_wall(p[i], player, map.cub[0][0]);
		i++;
	}
}

int			count(t_map map, int x, int y, int *c)
{
	printf("x = %d\tet\ty = %d\n", x, y);
	if (cond_top(map, x, y))
	{
		(*c)++;
	}
	if (cond_bot(map, x, y))
	{
		(*c)++;
	}
	if (cond_right(map, x, y))
	{
		(*c)++;
	}
	if (cond_left(map, x, y))
	{
		(*c)++;
	}
	return (1);
}

t_polygon	*get_malloc(t_map map)
{
	int			x;
	int			y;
	int			counter;
	t_polygon	*p;

	counter = 0;
	y = 0;
	while (++y < map.nbcuby - 1)
	{
		x = 0;
		while (++x < map.nbcubx - 1)
			count(map, x, y, &counter);
	}
	if (!(p = malloc(sizeof(t_polygon) * counter + 1)))
		return (NULL);
	p[counter].exist = false;
	return (p);
}

t_polygon	*parse_poly(t_map map, t_player player)
{
	t_polygon	*p;
	int			coor[2];

	p = get_malloc(map);
	coor[0] = 0;
	coor[1] = 0;
	while (++coor[1] < map.nbcuby - 1)
	{
		coor[0] = 0;
		while (++coor[0] < map.nbcubx - 1)
			search_polyverti(map, p, coor, player);
	}
	return (p);
}
