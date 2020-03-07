/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:05:13 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/07 19:40:39 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			polysetlen(t_polygon *set)
{
	int		i;

	i = 0;
	while (set[i].exist)
		i++;
	return (i);
}

int			classify_point(t_polygon polygon, t_point point)
{
	int		testvalue;
	int		realres;

	testvalue = polygon.normal.ylen * point.x + polygon.normal.xlen * point.y;
	realres = polygon.normal.ylen * polygon.segment.a.x + polygon.normal.xlen * polygon.segment.a.y;
	if (testvalue == realres)
		return (COINCIDING);
	if (testvalue > realres)
		return (FRONT);
	else
		return (BACK);
}

int			get_side(t_polygon poly1, t_polygon poly2)
{
	if (classify_point(poly1, poly2.segment.a) == FRONT
		&& classify_point(poly1, poly2.segment.b) == FRONT)
		return (FRONT);
	else if (classify_point(poly1, poly2.segment.a) == BACK
			 && classify_point(poly1, poly2.segment.b) == BACK)
		return (BACK);
	else if (classify_point(poly1, poly2.segment.a) == COINCIDING
			 && classify_point(poly1, poly2.segment.b) == COINCIDING)
		return (COINCIDING);
	return (SPANNING);
}

bool		is_convex_set(t_polygon *set)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (set[++i].exist)
		while (set[++j].exist)
			if (i != j && get_side(set[i], set[j]) != FRONT && get_side(set[i], set[j]) != COINCIDING)
				return (false);
	return (true);
}

void		split_polygon(t_polygon poly, t_polygon splitter,
t_polygon *frontset, t_polygon *backset)
{
	int		side;
	int		oldside;
	t_point	p;

	p.x = min(poly.segment.a.x, poly.segment.b.x);
	set_point_on_segx(poly.segment, &p);
	side = classify_point(splitter, p);
	printf("p.x = %d\tet\tp.y = %d\tseg.b.x = %d\tet\tseg.b.y = %d\n", p.x, p.y, poly.segment.b.x, poly.segment.b.y);
	oldside = side;
	printf("oldside = %d\n", oldside);
	while ((side = classify_point(splitter, p)) == oldside)
	{
		oldside = side;
		get_next_point(poly.segment, &p);
		printf("p.x = %d\tet\tp.y = %d\n", p.x, p.y);
	}
	/*printf("side = %d\n", side);
	printf("p.x = %d\tet\tp.y = %d\tseg.b.x = %d\tet\tseg.a.y = %d\n", p.x, p.y, poly.segment.b.x, poly.segment.b.y);
	sleep(1);*/
	if (oldside == FRONT)
		partition_frontset(frontset, backset, p, poly); // on met oldside pcq c le moment ou ca coincide a ce moment la
	else
		partition_backset(frontset, backset, p, poly); // on met oldside pcq c le moment ou ca coincide a ce moment la
}
