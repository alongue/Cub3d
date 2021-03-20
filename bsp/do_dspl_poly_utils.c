/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dspl_poly_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 10:16:57 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/14 10:18:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	cannot_see_first_part(double *tanpoly, t_polygon *polygon)
{
	*tanpoly = (polygon->newsegment.a.x - polygon->newsegment.b.x != 0) ?
	(polygon->newsegment.a.y - polygon->newsegment.b.y)
	/ (polygon->newsegment.a.x - polygon->newsegment.b.x) :
	0;
	polygon->newsegment.a.y += (ZMIN - polygon->newsegment.a.x) * *tanpoly;
	polygon->newsegment.a.x = ZMIN;
}

void	cannot_see_last_part(double *tanpoly, t_polygon *polygon)
{
	*tanpoly = (polygon->newsegment.b.x - polygon->newsegment.a.x != 0) ?
	(polygon->newsegment.b.y - polygon->newsegment.a.y)
	/ (polygon->newsegment.b.x - polygon->newsegment.a.x) :
	0;
	polygon->newsegment.b.y += (ZMIN - polygon->newsegment.b.x) * *tanpoly;
	polygon->newsegment.b.x = ZMIN;
}

int		init4drawing(t_data *data, t_player player, t_polygon *polygon, int i)
{
	double	tanindex;
	int		index;

	polygon->wall.topcl = fmax(polygon->wall.top, 0.);
	polygon->wall.botcl = fmin(polygon->wall.bot, data->win_height);
	tanindex = -(polygon->newangle + to_rad(90) - player.angleray[i]);
	index = (int)(polygon->pdist * tan(tanindex) + polygon->btobp)
	% (polygon->wall.imgwidth);
	index = (index < 0) ? 0 : index;
	polygon->wall.incr[0] = (polygon->wall.imgheight - 1)
	/ (polygon->wall.bot - polygon->wall.top);
	polygon->wall.incr[1] = (polygon->wall.topcl - polygon->wall.top)
	* polygon->wall.incr[0];
	polygon->wall.incr[1] = (polygon->wall.incr[1] < 0)
	? 0 : polygon->wall.incr[1];
	polygon->wall.ptraddr[0] = (int)(round(polygon->wall.topcl)
	* data->win_width + i);
	polygon->wall.ptraddr[0] -= data->win_width;
	polygon->wall.ptraddr[1] = (int)(round(polygon->wall.botcl)
	* data->win_width + i);
	return (index);
}
