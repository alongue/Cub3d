/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_prev_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:16:17 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/08 15:17:45 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	get_prev_point(t_segment segment, t_point *point)
{
	if (segment.coeff == INFINITY &&
		point->y <= max(segment.a.y, segment.b.y))
	{
		point->y--;
		set_point_on_segy(segment, point);
	}
	else if (segment.coeff == -INFINITY)
	{
		point->y++;
		set_point_on_segy(segment, point);
	}
	else
	{
		point->x--;
		set_point_on_segx(segment, point);
	}
}
