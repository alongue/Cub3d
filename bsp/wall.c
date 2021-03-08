/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:03:43 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#include <stdio.h>
#include <stdlib.h>

#define ZMIN 1

void			replace_poly(t_polygon *polygon, t_player player)
{
	t_point	a;
	t_point	b;

	get_extremity(polygon->segment, &a, &b);
	translate_point(&a, -player.x, -player.z);
	translate_point(&b, -player.x, -player.z);
	polygon->newsegment = get_segmenti(a.x * cos(-player.angle)
									- a.y * sin(-player.angle),
									a.y * cos(-player.angle)
							 		+ a.x * sin(-player.angle),
									b.x * cos(-player.angle)
									 - b.y * sin(-player.angle),
									b.y * cos(-player.angle)
									+ b.x * sin(-player.angle));
}

int			do_display_poly(t_polygon *polygon, t_data data, t_player player)
{
	double		tanpoly;
	t_segment	segmentcop;

	if (polygon->newsegment.a.x < ZMIN && polygon->newsegment.b.x < ZMIN)
		return ((polygon->dodisplay = 0));
	segmentcop = dup_segment(polygon->newsegment);
	if (polygon->newsegment.a.x < ZMIN)
	{
		tanpoly = (polygon->newsegment.a.x - polygon->newsegment.b.x != 0) ?
		(polygon->newsegment.a.y - polygon->newsegment.b.y)
		/ (polygon->newsegment.a.x - polygon->newsegment.b.x) :
		0;
		polygon->newsegment.a.y += (ZMIN - polygon->newsegment.a.x) * tanpoly;
		polygon->newsegment.a.x = ZMIN;
	}
	if (polygon->newsegment.b.x < ZMIN)
	{
		tanpoly = (polygon->newsegment.b.x - polygon->newsegment.a.x != 0) ?
		(polygon->newsegment.b.y - polygon->newsegment.a.y)
		/ (polygon->newsegment.b.x - polygon->newsegment.a.x) :
		0;
		polygon->newsegment.b.y += (ZMIN - polygon->newsegment.b.x) * tanpoly;
		polygon->newsegment.b.x = ZMIN;
	}
	polygon->newsegment.a.x = min(9999, polygon->newsegment.a.x);
	polygon->newsegment.b.x = min(9999, polygon->newsegment.b.x);
	polygon->dodisplay = raycastx(&polygon->wall, polygon, data, &segmentcop);
	if (!raycastx_img(player, polygon, segmentcop))
		return (0);
	return (polygon->dodisplay);
}

t_wall			create_wall(t_polygon poly, t_player player, t_data data)
{
	t_wall	wall;

	wall.left = get_segmenti(poly.wall.left.a.x, 0,
							 poly.wall.left.a.x, data.cubside); //on met left.b.x = left.a.x
	wall.right = get_segmenti(poly.wall.right.a.x, 0,
								poly.wall.right.a.x, data.cubside);
	if (player.exist)
	{
		translate_segment(&wall.left, 0, -player.y);
		translate_segment(&wall.right, 0, -player.y);
	}
	raycastfps(&wall, player, poly, data);
	set_delta(&wall);
	return (wall);
}

t_wall			dup_wall(t_wall wall)
{
	t_wall	wallcop;

	wallcop.exist = wall.exist;
	wallcop.bpp = wall.bpp;
	wallcop.size_line = wall.size_line;
	wallcop.endian = wall.endian;
	wallcop.bppimg = wall.bppimg;
	wallcop.size_lineimg = wall.size_lineimg;
	wallcop.endianimg = wall.endianimg;
	wallcop.top = wall.top;
	wallcop.topcl = wall.topcl;
	wallcop.bot = wall.bot;
	wallcop.botcl = wall.botcl;
	wallcop.left = wall.left;
	wallcop.leftcl = wall.leftcl;
	wallcop.right = wall.right;
	wallcop.rightcl = wall.rightcl;
	wallcop.deltatop = wall.deltatop;
	wallcop.deltabot = wall.deltabot;
	wallcop.color = wall.color;
	wallcop.img = wall.img;
	wallcop.imgwidth = wall.imgwidth;
	wallcop.imgheight = wall.imgheight;
	wallcop.img_data = wall.img_data;
	wallcop.data_file = wall.data_file;
	return (wallcop);
}

int				display_wall(t_data *data, t_wall wall, t_polygon polygon, t_player player)
{
	int		i;
	int		ptraddr[2];
	double	tanindex;
	int		index;
	double	incr[2];

	initbe4display(&wall, &i, data);
	ft_memseti(ptraddr, 0, 2);
	ft_memseti(incr, 0, 2);
	while (++i <= (int)round(wall.rightcl.a.x))
	{
		if (can_draw(wall, data, i))
		{
			wall.topcl = fmax(wall.top, 0.);
			wall.botcl = fmin(wall.bot, data->win_height);
			tanindex = -polygon.newangle - to_rad(90) + player.angleray[i];
			index = (int)((polygon.pdist * tan(tanindex) + polygon.btobp) * ((wall.imgwidth) / data->cubside)) % (wall.imgwidth);
			index = (index < 0) ? 0 : index;
			incr[0] = (wall.imgheight - 1) / (wall.bot - wall.top);
			incr[1] = (wall.topcl - wall.top) * incr[0];
			incr[1] = (incr[1] < 0) ? 0 : incr[1];
			ptraddr[0] = (int)(round(wall.topcl) * data->win_width + i);
			ptraddr[1] = (int)(round(wall.botcl) * data->win_width + i);
			while (ptraddr[0] < ptraddr[1])
			{
				wall.img_data[ptraddr[0]] = wall.data_file[(int)(round(incr[1]) * wall.imgwidth + index)];
				incr[1] += incr[0];
				ptraddr[0] += data->win_width;
			}
			data->coldone[i] = 1;
		}
		wall.top += wall.deltatop;
		wall.bot += wall.deltabot;
	}
	return (EXIT_SUCCESS);
}
