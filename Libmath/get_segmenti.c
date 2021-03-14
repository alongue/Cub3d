/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segmenti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:29:46 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 23:00:41 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_segment	get_segmenti(double px, double py, double qx, double qy)
{
	t_segment	s;

	s.exist = 0;
	s.a = set_point(px, py);
	s.b = set_point(qx, qy);
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
