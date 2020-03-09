/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:33:01 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/09 15:33:46 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_point		hardmin(t_point a, t_point b, t_point c, t_point d)
{
	t_point p;
	t_point	pcop;

	if (a.x == b.x && a.x == c.x && a.x == d.x)
	{
		pcop = (a.y < b.y) ? dup_point(a) : dup_point(b);
		pcop = (pcop.y < c.y) ? pcop : dup_point(c);
		pcop = (pcop.y < d.y) ? pcop : dup_point(d);
	}
	else
	{
		pcop = (a.x < b.x) ? dup_point(a) : dup_point(b);
		pcop = (pcop.x < c.x) ? pcop : dup_point(c);
		pcop = (pcop.x < d.x) ? pcop : dup_point(d);
	}
	p = dup_point(pcop);
	return (p);
}

t_point		hardmax(t_point a, t_point b, t_point c, t_point d)
{
	t_point p;
	t_point	pcop;

	if (a.x == b.x && a.x == c.x && a.x == d.x)
	{
		pcop = (a.y > b.y) ? dup_point(a) : dup_point(b);
		pcop = (pcop.y > c.y) ? pcop : dup_point(c);
		pcop = (pcop.y > d.y) ? pcop : dup_point(d);
	}
	else
	{
		pcop = (a.x > b.x) ? dup_point(a) : dup_point(b);
		pcop = (pcop.x > c.x) ? pcop : dup_point(c);
		pcop = (pcop.x > d.x) ? pcop : dup_point(d);
	}
	p = dup_point(pcop);
	return (p);
}

t_segment	join_segment(t_segment s1, t_segment s2)
{
	t_segment	s;

	s.exist = false;
	if (!is_colinear(s1, s2))
		return (s);
	if (!s1.exist)
		return (s2);
	if (!s2.exist)
		return (s1);
	s.a = hardmin(s1.a, s1.b, s2.a, s2.b);
	s.b = hardmax(s1.a, s1.b, s2.a, s2.b);
	if (s.b.x - s.a.x != 0)
		s.coeff = (s.b.y - s.a.y) / (s.b.x - s.a.x);
	else if (s.a.y > s.b.y)
		s.coeff = -INFINITY;
	else if (s.b.y > s.a.y)
		s.coeff = INFINITY;
	if (s.coeff == INFINITY || s.coeff == -INFINITY)
		s.intercept = NAN;
	else
		s.intercept = s.a.y - s.coeff * s.a.x;
	s.exist = true;
	return (s);
}
