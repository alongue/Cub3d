/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 13:37:02 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 12:16:49 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon			create_polytop(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[y][x].stop);
	printf("p.segment.a.x = %d\tet\tp.segment.a.y = %d\n", p.segment.a.x, p.segment.a.y);
	p.normal = get_normal(cub[y][x].stop);
	p.nbwall = 1;
	while (cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y - 1][x].exist && !cub[y - 1][x].exist)
	{
		p.segment = join_segment(p.segment, cub[y][x].stop);
		p.nbwall += 1;
	}
	p.exist = true;
	return (p);
}

t_polygon			create_polybot(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sbot);
	printf("p.segment.a.x = %d\tet\tp.segment.a.y = %d\n", p.segment.a.x, p.segment.a.y);
	p.normal = get_normal(cub[y][x].sbot);
	p.nbwall = 1;
	while (cub[y][++x].exist && cub[y][x - 1].exist
		&& !cub[y + 1][x].exist && !cub[y - 1][x - 1].exist)
	{
		p.segment = join_segment(p.segment, cub[y][x].stop);
		p.nbwall += 1;
	}
	p.exist = true;
	return (p);
}

t_polygon			create_polyright(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sright);
	printf("p.segment.a.x = %d\tet\tp.segment.a.y = %d\n", p.segment.a.x, p.segment.a.y);
	p.normal = get_normal(cub[y][x].sright);
	p.nbwall = 1;
	while (cub[y][++x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x + 1].exist && !cub[y][x + 1].exist)
	{
		p.segment = join_segment(p.segment, cub[y][x].stop);
		p.nbwall += 1;
	}
	p.exist = true;
	return (p);
}

t_polygon			create_polyleft(t_map map, int x, int y)
{
	t_polygon	p;
	t_cub		**cub;

	cub = map.cub;
	p.segment = dup_segment(cub[y][x].sleft);
	printf("p.segment.a.x = %d\tet\tp.segment.a.y = %d\n", p.segment.a.x, p.segment.a.y);
	p.normal = get_normal(cub[y][x].sleft);
	p.nbwall = 1;
	while (cub[y][++x].exist && cub[y - 1][x].exist
		&& !cub[y - 1][x - 1].exist && !cub[y][x - 1].exist)
	{
		p.segment = join_segment(p.segment, cub[y][x].stop);
		p.nbwall += 1;
	}
	p.exist = true;
	return (p);
}
