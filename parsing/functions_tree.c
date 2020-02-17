/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:05:13 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 02:04:17 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			polysetlen(t_polygon *set)
{
	int		i;

	i = 0;
	while (set[i])
		i++;
	return (i);
}

int			classify_point(t_polygon polygon, t_point point)
{
	int		testvalue;
	int		realres;

	testval = polygon.normal.xlen * point.x + polygon.normal.ylen * point.y;
	realres = polygon.normal.xlen * polygon.segment.p.x + polygon.normal.ylen * polygon.segment.p.y;
	if (testvalue == realres)
		return (COINCIDING);
	if (testvalue < realres)
		return (BACK);
	else
		return (FRONT);
}

int			get_side(t_polygon poly1, t_polygon poly2)
{
	if (classify_point(poly1, poly2.segment.p) == FRONT
		&& classify_point(poly1, poly2.segment.p) == FRONT)
		return (FRONT);
	else if (classify_point(poly1, poly2.segment.p) == BACK
			 && classify_point(poly1, poly2.segment.q) == BACK)
		return (BACK);
	else if (classify_point(poly1, poly2.segment.p) == COINCIDING
			 && classify_point(poly1, poly2.segment.p) == COINCIDING)
		return (COINCIDING);
	return (SPANNING);
}

bool		is_convex_set(t_polygon *set)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (set[++i])
		while (set[++j])
			if (i != j && get_side(set[i], set[j]) != FRONT)
				return (false);
	return (true);
}
