/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_poly.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:04:58 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:00:45 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			iserror(t_polygon *polygon, int counter)
{
	int	i;

	i = -1;
	while (++i < counter)
		if (!polygon[i].exist)
			return (1);
	return (0);
}

int			search_polyverti(t_map *map, t_data data)
{
	static int	i = 0;

	if (cond_top(map, data.currentCubIndex[0], data.currentCubIndex[1]))
		if ((i = do_cond_top(map, i, &data)) == -1)
			return (i);
	if (cond_bot(map, data.currentCubIndex[0], data.currentCubIndex[1]))
		if ((i = do_cond_bot(map, i, &data)) == -1)
			return (i);
	if (cond_right(map, data.currentCubIndex[0], data.currentCubIndex[1]))
		if ((i = do_cond_right(map, i, &data)) == -1)
			return (i);
	if (cond_left(map, data.currentCubIndex[0], data.currentCubIndex[1]))
		if ((i = do_cond_left(map, i, &data)) == -1)
			return (i);
	return (i);
}

int			count(t_map *map, int x, int y, int *c)
{
	if (cond_top(map, x, y))
		(*c)++;
	if (cond_bot(map, x, y))
		(*c)++;
	if (cond_right(map, x, y))
		(*c)++;
	if (cond_left(map, x, y))
		(*c)++;
	return (1);
}

t_polygon	*get_malloc(t_map *map, int *counter)
{
	int			x;
	int			y;
	int			i;
	t_polygon	*p;

	*counter = 0;
	y = -1;
	x = -1;
	while (++y < map->nbymax)
	{
		x = -1;
		while (++x < map->nbxmax)
			count(map, x, y, counter);
	}
	if (!(p = malloc(sizeof(t_polygon) * *counter + 1)))
		return (NULL);
	i = -1;
	while (++i < *counter)
		p[i].exist = 0;
	p[*counter].exist = 0;
	return (p);
}

int			parse_poly(t_map *map, t_data data)
{
	int			realpolynb;

	map->tree.rootnode->set = get_malloc(map, &realpolynb);
	data.currentCubIndex[0] = -1;
	data.currentCubIndex[1] = -1;
	while (++data.currentCubIndex[1] < map->nbymax)
	{
		data.currentCubIndex[0] = -1;
		while (++data.currentCubIndex[0] < map->nbxmax)
		{
			realpolynb = search_polyverti(map, data);
			if (iserror(map->tree.rootnode->set, realpolynb))
				return (0);
		}
	}
	return (1);
}
