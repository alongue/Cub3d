/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:27:18 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:01:10 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		raycastx(t_wall *wall, t_polygon *polygon,
t_data data, t_segment *segment)
{
	t_point		tmp;
	t_segment	tmpsegment;

	wall->left.a.x = data.win_width / 2 + polygon->newsegment.a.y
	* data.win_width / 2 / polygon->newsegment.a.x;
	wall->right.a.x = data.win_width / 2 + polygon->newsegment.b.y
	* data.win_width / 2 / polygon->newsegment.b.x;
	if (wall->left.a.x > wall->right.a.x)
	{
		tmpsegment = dup_segment(wall->left);
		wall->left = dup_segment(wall->right);
		wall->right = dup_segment(tmpsegment);
		tmp = dup_point(polygon->newsegment.b);
		polygon->newsegment.b = dup_point(polygon->newsegment.a);
		polygon->newsegment.a = dup_point(tmp);
		tmp = dup_point(segment->b);
		segment->b = dup_point(segment->a);
		segment->a = dup_point(tmp);
	}
	if (wall->left.a.x >= wall->right.a.x ||
		wall->right.a.x < 0 || wall->left.a.x > data.win_width)
		return (0);
	return (1);
}

int		raycastx_img(t_player player, t_polygon *polygon,
t_segment segment, t_data data)
{
	double	s;
	double	len;

	len = polygon->len * ((double)data.cubside /
	(double)polygon->wall.imgwidth);
	polygon->newangle = polygon->angle + player.angle;
	polygon->r = (-segment.a.x * (segment.b.x - segment.a.x)
		+ (-segment.a.y * (segment.b.y - segment.a.y)))
		/ (len * len);
	polygon->btobp = polygon->r * len;
	s = (segment.a.y * (segment.b.x - segment.a.x)
		- (segment.a.x * (segment.b.y - segment.a.y)))
		/ (len * len);
	polygon->pdist = s * len;
	return (1);
}

int		raycastfps(t_wall *wall, t_player player,
t_polygon polygon, t_data data)
{
	int		ret;
	double	res;

	ret = 1;
	wall->leftcl = dup_segment(wall->left);
	wall->rightcl = dup_segment(wall->right);
	(void)res;
	wall->leftcl.b.y = player.dfoc * (data.cubside / 2)
	/ polygon.newsegment.a.x;
	wall->leftcl.a.y = -wall->leftcl.b.y;
	ret = translate_segment(&wall->leftcl, 0, data.win_height / 2);
	wall->rightcl.b.y = player.dfoc * (data.cubside / 2)
	/ polygon.newsegment.b.x;
	wall->rightcl.a.y = -wall->rightcl.b.y;
	ret = translate_segment(&wall->rightcl, 0, data.win_height / 2);
	return (ret);
}

int		raycastxobj(t_object *object, t_data data, t_player player)
{
	object->xstartcl = data.win_width / 2 +
	((object->newpos.y - object->width / 2) * player.dfoc) / object->newpos.x;
	object->xmiddlecl = data.win_width / 2 +
	(object->newpos.y * player.dfoc) / object->newpos.x;
	object->xendcl = data.win_width / 2 +
	((object->newpos.y + object->width / 2) * player.dfoc) / object->newpos.x;
	object->xstart = object->xstartcl;
	if (object->xstartcl == object->xendcl ||
		object->xendcl < 0 || object->xstartcl > data.win_width)
		return (0);
	return (1);
}

int		raycastfpsobj(t_object *object, t_player player, t_data data)
{
	object->fakebot = data.win_height / 2 +
	(player.dfoc * (data.cubside / 2) / object->newpos.x);
	object->bot = data.win_height / 2 +
	(player.dfoc * (object->height / 2) / object->newpos.x);
	object->bot += object->fakebot - object->bot;
	object->faketop = data.win_height / 2 +
	(player.dfoc * (-data.cubside / 2) / object->newpos.x);
	object->top = data.win_height / 2 +
	(player.dfoc * (-object->height / 2) / object->newpos.x);
	object->top += object->top - object->faketop;
	if (object->top == object->bot)
		return (-1);
	object->topcl = object->top;
	object->botcl = object->bot;
	return (1);
}
