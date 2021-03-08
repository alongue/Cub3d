/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:05:13 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:59:12 by erlajoua         ###   ########.fr       */
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
				return (0);
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
	side = classify_point(splitter, p);
	oldside = side;
	while ((side = classify_point(splitter, p)) == oldside)
	{
		oldside = side;
			get_next_point(poly.segment, &p, 64);
	}
	if (oldside == FRONT)
		partition_frontset(frontset, backset, p, poly);
	else if (oldside == BACK)
		partition_backset(frontset, backset, p, poly); 
}
