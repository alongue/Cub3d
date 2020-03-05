/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_point_on_segx.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:20:29 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/05 19:15:15 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	set_point_on_segx(t_segment segment, t_point *p)
{
	if (p->x > max(segment.a.x, segment.b.x))
		*p = (segment.a.x > segment.b.x) ? dup_point(segment.a)
			: dup_point(segment.b);
	else if (p->x < min(segment.a.x, segment.b.x))
		*p = (segment.a.x < segment.b.x) ? dup_point(segment.a)
			: dup_point(segment.b);
	else //sinon on a juste besoin de changer y vu que le point en x est deja egale a un point du segment en x
	{
		if (!isnan(segment.intercept))
			p->y = segment.coeff * p->x + segment.intercept;
		else
			p->y = segment.a.y; // j'aurais tres bien pu l'affecter a un tout autre point sur le segment en y;
	}
}
