/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_segmenti.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:29:46 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/05 19:02:03 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

t_segment	get_segmenti(int px, int py, int qx, int qy)
{
	t_segment	s;

	s.exist = false;
	s.a = get_point(px, py);
	s.b = get_point(qx, qy);
	if (s.b.x - s.a.x == 0 && s.b.y - s.a.y == 0)
		return (s);
	if (s.b.x - s.a.x != 0)
		s.coeff = (s.b.y - s.a.y) / (s.b.x - s.a.x);
	else if (s.b.y - s.a.y < 0)
		s.coeff = -INFINITY;
	else
		s.coeff = INFINITY;
	if (s.coeff == INFINITY || s.coeff == -INFINITY)
		s.intercept = NAN;
	else
		s.intercept = s.a.y - s.coeff * s.a.x;
	s.exist = true;
	return (s);
}
