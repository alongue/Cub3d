/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 15:25:22 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:00:16 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#include <stdio.h>
#include <stdlib.h>

#define ZMIN 1

void			replace_obj(t_object *object, t_player player)
{
	object->newpos = dup_point(object->pos);
	translate_point(&object->newpos, -player.x, -player.z);
	object->newpos = set_point(object->newpos.x * cos(-player.angle)
									- object->newpos.y * sin(-player.angle),
									object->newpos.y * cos(-player.angle)
							 		+ object->newpos.x * sin(-player.angle));
}

int			do_display_obj(t_object *object, t_data data, t_player player)
{
	if (object->newpos.x < ZMIN)
		return ((object->dodisplay = 0));
	object->newpos.x = min(9999, object->newpos.x);
	if (!(object->dodisplay = raycastxobj(object, data, player)))
		return (0);
	if (!(object->dodisplay = raycastfpsobj(object, player, data)))
		return (0);
	object->newpos = set_point(object->xstartcl, object->topcl);
	return (object->dodisplay);
}

int	can_draw_obj(t_object *object, t_data *data, int index)
{
	if ((!data->coldone[index] ||
		object->fakebot - object->faketop > data->heightcol[index]))
	{
		data->heightcol[index] = object->fakebot - object->faketop;
		object->xstartcl = index;
		if (data->coldone[index] == 0)
			data->nbcoldone++;
		return (1);
	}
	else
		return (0);
}

int				display_object(t_data *data, t_object object, t_player player)
{
	int		i;
	int		ptraddr[2];
	float	hindex;
	float	vindex;

	(void)player;
	object.xiter = (object.width - 1) / (object.xendcl - object.xstart);
	object.yiter = (object.height - 1) / (object.bot - object.top);
	if (object.xendcl > data->win_width - 1)
		object.xendcl = data->win_width - 1;
	if (object.xstartcl < 0)
		object.xstartcl = 0;
	object.topcl = max(object.top, 0);
	object.botcl = min(object.bot, data->win_height);
	i = object.xstartcl - 1;
	while (++i < object.xendcl)
	{
		if (can_draw_obj(&object, data, i))
		{
			hindex = (object.xstartcl - (int)object.xstart) * object.xiter;
			vindex = (object.topcl - (int)object.top) * object.yiter;
			ptraddr[0] = (int)object.topcl * data->win_width + i;
			ptraddr[1] = (int)object.botcl * data->win_width + i;
			while (ptraddr[0] < ptraddr[1])
			{
				object.img_data[ptraddr[0]] = object.data_file[(int)(round(vindex) * object.width + round(hindex))];
				ptraddr[0] += data->win_width;
				vindex += object.yiter;
			}
			hindex += object.xiter;
		}
	}
	return (EXIT_SUCCESS);
}
