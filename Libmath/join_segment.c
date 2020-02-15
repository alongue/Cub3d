/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:33:01 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/15 16:33:03 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int			hardmin(t_point a, t_point b, t_point c, t_point d)
{
	t_point p;
	t_point	pcop;

	if (a.x == b.x && a.x == c.x && a.x == d.x)
	{
		pcop = (a.y < b.y) ? a : b;
		pcop = (pcop.y < c.y) ? p : c;
		pcop = (pcop.y < d.y) ? p : d;
	}
	else
	{
		pcop = (a.x < b.x) ? a : b;
		pcop = (pcop.x < c.x) ? p : c;
		pcop = (pcop.x < d.x) ? p : d;
	}
	p.x = pcop.x;
	p.y = pcop.y;
	return (p);
}

int			hardmax(t_point a, t_point b, t_point c, t_point d)
{
	t_point p;
	t_point	pcop;

	if (a.x == b.x && a.x == c.x && a.x == d.x)
	{
		pcop = (a.y > b.y) ? a : b;
		pcop = (pcop.y > c.y) ? p : c;
		pcop = (pcop.y > d.y) ? p : d;
	}
	else
	{
		pcop = (a.x > b.x) ? a : b;
		pcop = (pcop.x > c.x) ? p : c;
		pcop = (pcop.x > d.x) ? p : d;
	}
	p.x = pcop.x;
	p.y = pcop.y;
	return (p);
}

t_segment	join_segment(t_segment s1, t_segment s2)
{
	t_segment	s;

	if ((!s1 && !s2) || !is_colinear(s1, s2))
		return (NULL);
	if (!s1)
		return (s2);
	if (!s2)
		return (s1);
	if (!(s.p = malloc(sizeof(t_point))))
		return (NULL);
	if (!(s.q = malloc(sizeof(t_point))))
		return (NULL);
	s.p = hardmin(s1.p, s1.q, s2.p, s2.q);
	s.q = hardmax(s1.p, s1.q, s2.p, s2.q);
	return (s);
}
