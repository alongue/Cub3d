/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:37:02 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/01 19:31:46 by alongcha         ###   ########.fr       */
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
	p.nbwall = 1;
	while (cub[++x][y].exist && cub[x - 1][y].exist
		&& !cub[x][y - 1].exist && !cub[x][y - 1].exist)
	{
		p.segment = join_segment(p.segment, cub[x][y].stop);
		p.nbwall++;
	}
	p.exist = true;
	return (p);
}

t_polygon			create_polybot(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[x][y].sbot);
	p.normal = get_normal(cub[x][y].sbot);
	p.nbwall = 1;
	while (cub[++x][y].exist && cub[x - 1][y].exist
		&& cub[x][y + 1].exist && !cub[x - 1][y + 1].exist)
	{
		p.segment = join_segment(p.segment, cub[x][y].sbot);
		p.nbwall++;
	}
	p.exist = true;
	return (p);
}

t_polygon			create_polyright(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[x][y].sright);
	p.nbwall = 1;
	p.normal = get_normal(cub[x][y].sright);
	while (cub[x][++y].exist && cub[x][y - 1].exist
		&& !cub[x + 1][y - 1].exist && !cub[x + 1][y].exist)
	{
		p.segment = join_segment(p.segment, cub[x][y].sright);
		p.nbwall++;
	}
	p.exist = true;
	return (p);
}

t_polygon			create_polyleft(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[x][y].sleft);
	p.normal = get_normal(cub[x][y].sleft);
	p.nbwall = 1;
	while (cub[x][++y].exist && cub[x][y - 1].exist
		&& !cub[x - 1][y - 1].exist && !cub[x - 1][y].exist)
	{
		p.segment = join_segment(p.segment, cub[x][y].sleft);
		p.nbwall++;
	}
	p.exist = true;
	return (p);
}
