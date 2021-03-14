/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 12:16:17 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 22:28:31 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

void	get_next_point(t_segment segment, t_point *point, double iterator)
{
	if (segment.coeff == INFINITY &&
		point->y >= segment.a.y && point->y <= segment.b.y)
	{
		point->y += iterator;
		set_point_on_segy(segment, point);
	}
	else if (segment.coeff == -INFINITY &&
		point->y >= segment.b.y && point->y <= segment.a.y)
	{
		point->y -= iterator;
		set_point_on_segy(segment, point);
	}
	else if (point->x >= segment.a.x && point->x <= segment.b.x
	&& segment.a.x < segment.b.x)
	{
		point->x += iterator;
		set_point_on_segx(segment, point);
	}
	else if (point->x <= segment.a.x && point->x >= segment.b.x
	&& segment.a.x > segment.b.x)
	{
		point->x -= iterator;
		set_point_on_segx(segment, point);
	}
}
