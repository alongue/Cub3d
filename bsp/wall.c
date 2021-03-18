/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:03:43 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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

int				do_display_poly(t_polygon *polygon,
t_data data, t_player player)
{
	double		tanpoly;
	t_segment	segmentcop;

	if (polygon->newsegment.a.x < ZMIN && polygon->newsegment.b.x < ZMIN)
		return ((polygon->dodisplay = 0));
	segmentcop = dup_segment(polygon->newsegment);
	if (polygon->newsegment.a.x < ZMIN)
		cannot_see_first_part(&tanpoly, polygon);
	if (polygon->newsegment.b.x < ZMIN)
		cannot_see_last_part(&tanpoly, polygon);
	polygon->newsegment.a.x = min(9999, polygon->newsegment.a.x);
	polygon->newsegment.b.x = min(9999, polygon->newsegment.b.x);
	polygon->dodisplay = raycastx(&polygon->wall, polygon, data, &segmentcop);
	if (!raycastx_img(player, polygon, segmentcop, data))
		return (0);
	return (polygon->dodisplay);
}

t_wall			create_wall(t_polygon poly, t_player player, t_data data)
{
	t_wall	wall;

	wall.left = get_segmenti(poly.wall.left.a.x, 0,
							poly.wall.left.a.x, data.cubside);
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

int				display_wall(t_data *data,
t_polygon polygon, t_player player)
{
	int		i;
	int		index;

	initbe4display(&polygon.wall, &i, data);
	ft_memseti(polygon.wall.ptraddr, 0, 2);
	ft_memseti(polygon.wall.incr, 0, 2);
	while (++i <= (int)round(polygon.wall.rightcl.a.x))
	{
		if (can_draw(polygon.wall, data, i))
		{
			index = init4drawing(data, player, &polygon, i);
			while ((polygon.wall.ptraddr[0] += data->win_width)
			< polygon.wall.ptraddr[1])
			{
				polygon.wall.img_data[polygon.wall.ptraddr[0]] =
				polygon.wall.data_file[(int)(round(polygon.wall.incr[1])
				* polygon.wall.imgwidth + index)];
				polygon.wall.incr[1] += polygon.wall.incr[0];
			}
			data->coldone[i] = 1;
		}
		polygon.wall.top += polygon.wall.deltatop;
		polygon.wall.bot += polygon.wall.deltabot;
	}
	return (EXIT_SUCCESS);
}
