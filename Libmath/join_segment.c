/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_segment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 16:33:01 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 22:55:54 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_segment	get_first_point(t_segment s1, t_segment s2)
{
	if (s1.a.x < s1.b.x)
	{
		return ((s1.a.x < s2.a.x) ? get_segment(s1.a, s2.b)
		: get_segment(s2.a, s1.b));
	}
	else if (s1.a.x > s1.b.x)
	{
		return ((s1.a.x > s2.a.x) ? get_segment(s1.a, s2.b)
		: get_segment(s2.a, s1.b));
	}
	else if (s1.a.y < s1.b.y)
	{
		return ((s1.a.y < s2.a.y) ? get_segment(s1.a, s2.b)
		: get_segment(s2.a, s1.b));
	}
	else if (s1.a.y > s1.b.y)
	{
		return ((s1.a.y > s2.a.y) ? get_segment(s1.a, s2.b)
		: get_segment(s2.a, s1.b));
	}
	return (get_segment(s1.a, s2.b));
}

t_segment	join_segment(t_segment s1, t_segment s2)
{
	t_segment	s;

	s.exist = 0;
	if (!is_colinear(s1, s2))
		return (s);
	if (!s1.exist)
		return (s2);
	if (!s2.exist)
		return (s1);
	s = get_first_point(s1, s2);
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
	s.exist = 1;
	return (s);
}
