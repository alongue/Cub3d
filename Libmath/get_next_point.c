/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:16:17 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/05 18:43:12 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

#include <stdio.h>

void	get_next_point(t_segment segment, t_point *point)
{
	if (segment.coeff == INFINITY &&
		point->y < max(segment.a.y, segment.b.y))
	{
		point->y++;
		set_point_on_segy(segment, point);
	}
	else if (segment.coeff == -INFINITY)
	{
		point->y--;
		set_point_on_segy(segment, point);
	}
	else
	{
		point->x++;
		set_point_on_segx(segment, point);
	}
	//printf("point->x = %d\tet\tpoint->y = %d\n", point->x, point->y);
}
