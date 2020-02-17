/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:37:02 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 22:07:30 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon			create_polytop(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[x][y].stop);
	p.normal = get_normal(cub[x][y].stop);
	while (cub[++x][y].exist && cub[x - 1][y].exist
		&& !cub[x][y - 1].exist && !cub[x][y - 1].exist)
		p.segment = join_segment(p.segment, cub[x][y].stop);
	return (p);
}

t_polygon			create_polybot(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[x][y].sbot);
	p.normal = get_normal(cub[x][y].sbot);
	while (cub[++x][y].exist && cub[x - 1][y].exist
		&& cub[x][y + 1].exist && !cub[x - 1][y + 1].exist)
		p.segment = join_segment(p.segment, cub[x][y].sbot);
	return (p);
}

t_polygon			create_polyright(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[x][y].sright);
	p.normal = get_normal(cub[x][y].sright);
	while (cub[x][++y].exist && cub[x][y - 1].exist
		&& !cub[x + 1][y - 1].exist && !cub[x + 1][y].exist)
		p.segment = join_segment(p.segment, cub[x][y].sbot);
	return (p);
}

t_polygon			create_polyleft(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[x][y].sleft);
	p.normal = get_normal(cub[x][y].sleft);
	while (cub[x][++y].exist && cub[x][y - 1].exist
		&& !cub[x - 1][y - 1].exist && !cub[x - 1][y].exist)
		p.segment = join_segment(p.segment, cub[x][y].sbot);
	return (p);
}
