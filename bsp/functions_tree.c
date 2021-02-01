/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:05:13 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 11:46:39 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define POINT_SCALE 0.001

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
	double	testvalue;
	double	realres;

	testvalue = polygon.normal.xlen * point.x + polygon.normal.ylen * point.y;
	realres = polygon.normal.xlen * polygon.segment.a.x + polygon.normal.ylen * polygon.segment.a.y;
	////vscode printf("testvalue = %ld\tet\trealres = %ld\n", testvalue, realres);
	if (testvalue == realres)
		return (COINCIDING);
	else if (testvalue > realres)
		return (FRONT);
	else
		return (BACK);
}

int			get_side(t_polygon poly1, t_polygon poly2)
{
	t_point	a;
	t_point	b;

	a = poly2.segment.a;
	get_next_point(poly2.segment, &a, POINT_SCALE);
	b = poly2.segment.b;
	get_prev_point(poly2.segment, &b, POINT_SCALE);
	if (classify_point(poly1, a) == FRONT
		&& classify_point(poly1, b) == FRONT)
		return (FRONT);
	else if (classify_point(poly1, a) == BACK
			 && classify_point(poly1, b) == BACK)
		return (BACK);
	else if (classify_point(poly1, a) == COINCIDING
			 && classify_point(poly1, b) == COINCIDING)
		return (COINCIDING);
	return (SPANNING);
}

int		is_convex_set(t_polygon *set, t_node *node)
{
	int		i;
	int		j;
	int		side;

	i = -1;
	j = -1;
	side = 0;
	if (node)
		node->isleaf = 0;
	while (set[++i].exist)
	{
		j = -1;
		while (set[++j].exist)
			if (i != j && (side = get_side(set[i], set[j])) != FRONT && side != COINCIDING)
			{
				//vscode printf("side = %d\n", side); //FRONT -> 1 | BACK -> 2 | SPANNING -> 3
				//vscode printf("finished.. unless...\n");
				return (0); // COINCIDING -> 0
			}
	}
	if (!node)
		return (1);
	node->exist = 1;
	node->isleaf = 1;
	node->frontchild->exist = 0;
	node->backchild->exist = 0;
	return (1);
}

void		split_polygon(t_polygon poly, t_polygon splitter,
t_polygon *frontset, t_polygon *backset)
{
	int		side;
	int		oldside;
	t_point	p;

	p = dup_point(poly.segment.a);
	//t_point	a;
	//a = dup_point(p);
	//vscode printf("poly.segment.a.x = %f\tpoly.segment.b.x = %f\n", poly.segment.a.x, poly.segment.b.x);
	////vscode sleep(4);
	side = classify_point(splitter, p);
	//vscode printf("p.x = %f\tet\tp.y = %f\tseg.b.x = %f\tet\tseg.b.y = %f\n", p.x, p.y, poly.segment.b.x, poly.segment.b.y);
	oldside = side;
	//vscode printf("oldside = %d\n", oldside);
	//int	i;
	//i = 0;
	//vscode printf("Extremites sont : %f\t\tet\t\t%f\n", poly.segment.a.y, poly.segment.b.y);
	////vscode sleep(4);
	while ((side = classify_point(splitter, p)) == oldside)
	{
		oldside = side;
		//if (poly.segment.coeff >= 0)
		//vscode printf("side = %d\n", side);
		////vscode printf("finish...    unless...\n");

		////vscode sleep(4);
			get_next_point(poly.segment, &p, 64);
			//vscode printf("coeff = %f\tpoint : x = %f\tet\ty = %f\n", poly.segment.coeff, p.x, p.y);
		//else
		//	get_prev_point(poly.segment, &p);
		//i++;
		//if (i >= 10 || !poly.exist || !poly.segment.exist)
		//{
			//vscode printf("poly.exist = %d\tet\tpoly.segment.exist = %d\n", poly.exist, poly.segment.exist);
			//vscode sleep(1);
		//}
		//vscode printf("poly.segment.a.x = %f\tpoly.segment.a.y = %f\npoly.segment.b.x = %f\tpoly.segment.b.y = %f\n", poly.segment.a.x, poly.segment.a.y, poly.segment.b.x, poly.segment.b.y);
		//vscode printf("poly.normal.xlen = %f\tpoly.normal.ylen = %f\n", poly.normal.xlen, poly.normal.ylen);
		//vscode printf("splitter.segment.a.x = %f\tsplitter.segment.a.y = %f\nsplitter.segment.b.x = %f\tsplitter.segment.b.y = %f\n", splitter.segment.a.x, splitter.segment.a.y, splitter.segment.b.x, splitter.segment.b.y);
		//vscode printf("splitter.normal.xlen = %f\tsplitter.normal.ylen = %f\n", splitter.normal.xlen, splitter.normal.ylen);
		//vscode printf("p.x = %f\tet\tp.y = %f\n", p.x, p.y);
	}
	/*//vscode printf("side = %d\n", side);
	//vscode printf("p.x = %d\tet\tp.y = %d\tseg.b.x = %d\tet\tseg.a.y = %d\n", p.x, p.y, poly.segment.b.x, poly.segment.b.y);
	//vscode sleep(1);*/
	////vscode sleep(4);
	if (oldside == FRONT)
		partition_frontset(frontset, backset, p, poly); // on met oldside pcq c le moment ou ca coincide a ce moment la
	else if (oldside == BACK)
		partition_backset(frontset, backset, p, poly); // on met oldside pcq c le moment ou ca coincide a ce moment la
}
