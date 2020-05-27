/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:04:58 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 18:57:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool		iserror(t_polygon *polygon, int counter)
{
	int	i;

	i = -1;
	while (++i < counter)
		if (!polygon[i].exist)
			return (1);
	return (0);
}
// faire une fonction ou on prend une fonction en param
int		search_polyverti(t_map *map, t_data data, t_player player)
{
	static int	i = 0;
	int			*x;
	int			*y;

	x = &data.currentCubIndex[0];
	y = &data.currentCubIndex[1];
	if (cond_top(*map, *x, *y))
	{
		map->tree.rootnode->set[i].isused = false;
		map->tree.rootnode->set[i++] = create_polytop(*map, data.currentCubIndex, data, player);
		//printf("i = %d\n", i);
		if (iserror(map->tree.rootnode->set, i))
			return (i);
	}
	if (cond_bot(*map, *x, *y))
	{
		map->tree.rootnode->set[i].isused = false;
		map->tree.rootnode->set[i++] = create_polybot(*map, data.currentCubIndex, data, player);
		//printf("i = %d\n", i);
		if (iserror(map->tree.rootnode->set, i))
			return (i);
	}
	if (cond_right(*map, *x, *y))
	{
		map->tree.rootnode->set[i].isused = false;
		map->tree.rootnode->set[i++] = create_polyright(*map, data.currentCubIndex, data, player);
		//printf("i = %d\n", i);
		if (iserror(map->tree.rootnode->set, i))
			return (i);
	}
	if (cond_left(*map, *x, *y))
	{
		map->tree.rootnode->set[i].isused = false;
		map->tree.rootnode->set[i++] = create_polyleft(*map, data.currentCubIndex, data, player);
		//printf("i = %d\n", i);
		if (iserror(map->tree.rootnode->set, i))
			return (i);
	}
	//printf("fin !\n");
	return (i);
}


/* ---------------------- !!! DEPRECATED !!! ---------------------- */

/*
void		create_polywall(t_map map, t_data data, t_polygon *p, t_player)
{
	int	x;
	int	y;
	int	i;

	x = data.currentCubIndex[0]; //enelver tous les trucs comme ca
	y = data.currentCubIndex[1];
	i = [2];
	printf("i (dans create_poly_wall) = %d\n", i);
	if (cond_top(map, x, y))
	{
		replace_poly(&p[i], data.player);
		printf("p[i].newsegment.a.x = %f\n", p[i].newsegment.a.x);
		p[i].dodisplay = do_display_poly(&p[i], data);
		p[i].wall = create_wall(p[i], player, data.cubside);
		i++; //enlever toutes les incrementations comme ca
	}
	if (cond_bot(map, x, y))
	{
		replace_poly(&p[i], data.player);
		printf("p[i].newsegment.a.x = %f\n", p[i].newsegment.a.x);
		p[i].dodisplay = do_display_poly(&p[i], data);
		p[i].wall = create_wall(p[i], player, data.cubside);
		i++;
	}
	if (cond_right(map, x, y))
	{
		replace_poly(&p[i], data.player);
		printf("p[i].newsegment.a.x = %f\n", p[i].newsegment.a.x);
		p[i].dodisplay = do_display_poly(&p[i], data);
		p[i].wall = create_wall(p[i], player, data.cubside);
		i++;
	}
	if (cond_left(map, x, y))
	{
		replace_poly(&p[i], data.player);
		printf("p[i].newsegment.a.x = %f\n", p[i].newsegment.a.x);
		p[i].dodisplay = do_display_poly(&p[i], data);
		p[i].wall = create_wall(p[i], player, data.cubside);
		i++;
	}
}
*/

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

t_polygon	*get_malloc(t_map map, int *counter)
{
	int			x;
	int			y;
	int			i;
	t_polygon	*p;

	*counter = 0;
	y = -1;
	x = -1;
	while (++y < get_nbymax(map.nbcuby))
	{
		x = -1;
		while (++x < get_nbxmax(map.nbcuby))
			count(map, x, y, counter);
	}
	//printf("counter de polys = %d\n", *counter);
	//sleep(2);
	if (!(p = malloc(sizeof(t_polygon) * *counter + 1)))
		return (NULL);
	i = -1;
	while (++i < *counter)
		p[i].exist = false;
	p[*counter].exist = false;
	return (p);
}

int			parse_poly(t_map *map, t_player player, t_data data)
{
	int			realpolynb;

	map->tree.rootnode->set = get_malloc(*map, &realpolynb);
	data.currentCubIndex[0] = -1;
	data.currentCubIndex[1] = -1;
	while (++data.currentCubIndex[1] < get_nbymax(map->nbcuby))
	{
		data.currentCubIndex[0] = -1;
		while (++data.currentCubIndex[0] < get_nbxmax(map->nbcuby))
		{
			realpolynb = search_polyverti(map, data, player);
			if (iserror(map->tree.rootnode->set, realpolynb))
				return (0);
		}
	}
	return (1);
}
