/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 16:19:03 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#include <stdio.h>
#include <stdlib.h>

# define ZMIN 1 // derriere zmin, c'est derriere le joueur (on prend 1 pour ne laisser aucun point egale a 0 sinon div by 0)

void			replace_obj(t_object *object, t_player player)
{
	object->newpos = dup_point(object->pos);
	printf("object->newpos.x = %f\tet\tobject->newpos.y = %f\n", object->newpos.x, object->newpos.y);
	//sleep(3);
	translate_point(&object->newpos, -player.x, -player.z);// on prend ce segment qu'on va ensuite clipper
	object->newpos = get_point(object->newpos.x * cos(-player.angle)
									- object->newpos.y * sin(-player.angle),
									object->newpos.y * cos(-player.angle)
							 		+ object->newpos.x * sin(-player.angle));
	/*printf("(dans replace_poly) polygon->segment.a.y = %f\tet\tb.y = %f\na.x = %f\tet\tb.x = %f\n", polygon->segment.a.y, polygon->segment.b.y, polygon->segment.a.x, polygon->segment.b.x);
	printf("(dans replace_poly) polygon->newsegment.a.y = %f\tet\tb.y = %f\na.x = %f\tet\tb.x = %f\n", polygon->newsegment.a.y, polygon->newsegment.b.y, polygon->newsegment.a.x, polygon->newsegment.b.x);
	if (((player.angle > 3 * M_PI / 2 && player.angle <= 2 * M_PI) || (player.angle >= 0 && player.angle < M_PI / 2)) && ((polygon->newsegment.a.y > polygon->newsegment.b.y && polygon->newsegment.a.x == polygon->newsegment.b.x) ||
		(polygon->newsegment.a.y == polygon->newsegment.b.y && (
																!(polygon->newsegment.a.x < polygon->newsegment.b.x && polygon->newsegment.a.y < 0) &&
																!(polygon->newsegment.a.x > polygon->newsegment.b.x && polygon->newsegment.a.y > 0))))) ||
		(((player.angle >= M_PI / 2 && player.angle < 3 * M_PI / 2) && ((polygon->newsegment.a.y < polygon->newsegment.b.y && polygon->newsegment.a.x == polygon->newsegment.b.x)||
		(polygon->newsegment.a.y == polygon->newsegment.b.y && (
																!(polygon->newsegment.a.x > polygon->newsegment.b.x && polygon->newsegment.a.y > 0) &&
																!(polygon->newsegment.a.x < polygon->newsegment.b.x && polygon->newsegment.a.y < 0)))))))
	{
		tmp = dup_point(polygon->newsegment.b);
		polygon->newsegment.b = dup_point(polygon->newsegment.a);
		polygon->newsegment.a = dup_point(tmp);
	}
	printf("(dans replace_poly) polygon->newsegment.a.y = %f\tet\tb.y = %f\na.x = %f\tet\tb.x = %f\n", polygon->newsegment.a.y, polygon->newsegment.b.y, polygon->newsegment.a.x, polygon->newsegment.b.x);*/
}

bool			do_display_obj(t_object *object, t_data data, t_player player)
{
	if (object->newpos.x < ZMIN)
		return ((object->dodisplay = false));
	object->newpos.x = min(9999, object->newpos.x);
	if (!(object->dodisplay = raycastxobj(object, data)))
		return (false);
	if (!(object->dodisplay = raycastfpsobj(object, player, data)))
		return (false);
	object->newpos = get_point(object->xstartcl, object->topcl);
	return (object->dodisplay);
}

/*
t_wall			create_(t_polygon poly, t_player player, t_data data)
{
	t_wall	wall;

	printf("poly.wall.left.a.x = %f (dans create_wall)\n", poly.wall.left.a.x);
	wall.left = get_segmenti(poly.wall.left.a.x, 0,
							 poly.wall.left.a.x, data.cubside); //on met left.b.x = left.a.x
	wall.right = get_segmenti(poly.wall.right.a.x, 0,
								poly.wall.right.a.x, data.cubside);
	if (player.exist)
	{
		translate_segment(&wall.left, 0, -player.y);
		translate_segment(&wall.right, 0, -player.y);
	}
	printf("wall.left.a.y (apres la translation) = %f\t\tet\t\tb.y = %f\n", wall.left.b.y, wall.left.a.y);
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
*/

int				display_object(t_data *data, t_object object, t_player player)
{
	int		i;
	int		ptraddr[2];
//	double	cumul;
//	double	anglewallpl;
	float	hindex;
	float	vindex;

	(void)player;
	object.xiter = object.width / (object.xendcl - object.xstartcl);
	object.yiter = (object.height - 1) / (object.botcl - object.topcl);
	//sleep(3);
	if (object.xendcl > data->win_width - 1)
		object.xendcl = data->win_width - 1;
	if (object.xstartcl < 0)
		object.xstartcl = 0;
	object.topcl = max(object.topcl, 0);
	object.botcl = min(object.botcl, data->win_height);
	i = object.xstartcl - 1;
	hindex = (object.xstartcl - object.newpos.x) * object.xiter;
	while (++i < object.xendcl)
	{
		vindex = (object.topcl - object.newpos.y) * object.yiter;
		ptraddr[0] = (int)object.topcl * data->win_width + i;
		ptraddr[1] = (int)object.botcl * data->win_width + i;
		while (ptraddr[0] < ptraddr[1])
		{
			object.img_data[ptraddr[0]] = object.data_file[(int)(round(vindex) * object.width + round(hindex))];
			//if ()
			ptraddr[0] += data->win_width;
			vindex += object.yiter;
		}
		hindex += object.xiter;
		printf("object.xiter = %f\tet\tobject.yiter = %f\n", object.xiter, object.yiter);
		printf("hindex = %f\n", hindex);
	}
	return (EXIT_SUCCESS);
}


/*
**		*(img.data + (x * 4 + 2) + (img.size * y)) = (unsigned)color.r;
**		*(img.data + (x * 4 + 1) + (img.size * y)) = (unsigned)color.g;
**		*(img.data + (x * 4 + 0) + (img.size * y)) = (unsigned)color.b;
*/