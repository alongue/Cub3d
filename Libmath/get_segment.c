/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 09:48:51 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/09 14:03:59 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_segment	get_segment(t_point p, t_point q)
{
	t_segment	s;

	s.exist = 0;
	s.a = set_point(p.x, p.y);
	s.b = set_point(q.x, q.y);
	if (s.b.x - s.a.x == 0 && s.b.y - s.a.y == 0)
		return (s);
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
