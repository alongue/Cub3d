/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_on_segy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 14:08:34 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/05 19:16:59 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	set_point_on_segy(t_segment segment, t_point *p)
{
	if (p->y > max(segment.a.y, segment.b.y))
		*p = (segment.a.y > segment.b.y) ? dup_point(segment.a)
			: dup_point(segment.b);
	else if (p->y < min(segment.a.y, segment.b.y))
		*p = (segment.a.y < segment.b.y) ? dup_point(segment.a)
			: dup_point(segment.b);
	else //sinon on a juste besoin de changer y vu que le point en x est deja egale a un point du segment en x
	{
		if (isfinite(segment.coeff) && segment.coeff != 0)
			p->x = (p->y - segment.intercept) / segment.coeff;
		else
			p->x = segment.a.x; // j'aurais tres bien pu l'affecter a un tout autre point sur le segment en y;
	}
}
