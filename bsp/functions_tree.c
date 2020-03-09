/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:05:13 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/09 18:02:16 by alongcha         ###   ########.fr       */
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
	long	testvalue;
	long	realres;

	testvalue = (long)polygon.normal.xlen * point.x + polygon.normal.ylen * point.y;
	realres = (long)polygon.normal.xlen * polygon.segment.a.x + polygon.normal.ylen * polygon.segment.a.y;
	//printf("testvalue = %ld\tet\trealres = %ld\n", testvalue, realres);
	if (testvalue == (long)realres)
		return (COINCIDING);
	else if (testvalue > (long)realres)
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

bool		is_convex_set(t_polygon *set, t_node *node)
{
	int		i;
	int		j;
	int		side;

	i = -1;
	j = -1;
	side = 0;
	while (set[++i].exist)
	{
		j = -1;
		while (set[++j].exist)
			if (i != j && (side = get_side(set[i], set[j])) != FRONT && side != COINCIDING)
			{
				//printf("side = %d\n", side); //FRONT -> 1 | BACK -> 2 | SPANNING -> 3
				return (false); // COINCIDING -> 0
			}
	}
	if (!node)
		return (true);
	node->exist = true;
	node->isleaf = true;
	node->frontchild->exist = false;
	node->backchild->exist = false;
	return (true);
}

void		split_polygon(t_polygon poly, t_polygon splitter,
t_polygon *frontset, t_polygon *backset)
{
	int		side;
	int		oldside;
	t_point	p;

	p = dup_point(poly.segment.a);
	t_point	a;
	a = dup_point(p);
	//printf("poly.segment.a.x = %d\tpoly.segment.b.x = %d\n", poly.segment.a.x, poly.segment.b.x);
	//sleep(4);
	side = classify_point(splitter, p);
	//printf("p.x = %d\tet\tp.y = %d\tseg.b.x = %d\tet\tseg.b.y = %d\n", p.x, p.y, poly.segment.b.x, poly.segment.b.y);
	sleep(4);
	oldside = side;
	//printf("oldside = %d\n", oldside);
	int	i;
	i = 0;
	while ((side = classify_point(splitter, p)) == oldside)
	{
		oldside = side;
		//if (poly.segment.coeff >= 0)
			get_next_point(poly.segment, &p);
			printf("coeff = %f\tpoint du debut : x = %d\tet\ty = %d\n", poly.segment.coeff, a.x, a.y);
		//else
		//	get_prev_point(poly.segment, &p);
		i++;
		/*if (i >= 200 || !poly.exist || !poly.segment.exist)
		{
			printf("poly.exist = %d\tet\tpoly.segment.exist = %d\n", poly.exist, poly.segment.exist);
			sleep(1);
		}
		printf("poly.segment.a.x = %d\tpoly.segment.a.y = %d\npoly.segment.b.x = %d\tpoly.segment.b.y = %d\n", poly.segment.a.x, poly.segment.a.y, poly.segment.b.x, poly.segment.b.y);
		printf("poly.normal.xlen = %d\tpoly.normal.ylen = %d\n", poly.normal.xlen, poly.normal.ylen);
		printf("splitter.segment.a.x = %d\tsplitter.segment.a.y = %d\nsplitter.segment.b.x = %d\tsplitter.segment.b.y = %d\n", splitter.segment.a.x, splitter.segment.a.y, splitter.segment.b.x, splitter.segment.b.y);
		printf("splitter.normal.xlen = %d\tsplitter.normal.ylen = %d\n", splitter.normal.xlen, splitter.normal.ylen);
		printf("p.x = %d\tet\tp.y = %d\n", p.x, p.y);*/
	}
	/*printf("side = %d\n", side);
	printf("p.x = %d\tet\tp.y = %d\tseg.b.x = %d\tet\tseg.a.y = %d\n", p.x, p.y, poly.segment.b.x, poly.segment.b.y);
	sleep(1);*/
	if (oldside == FRONT)
		partition_frontset(frontset, backset, p, poly); // on met oldside pcq c le moment ou ca coincide a ce moment la
	else
		partition_backset(frontset, backset, p, poly); // on met oldside pcq c le moment ou ca coincide a ce moment la
}
