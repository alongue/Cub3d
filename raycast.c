/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:27:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 13:06:01 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

#define ZMIN 1

int		raycastx(t_wall *wall, t_polygon *polygon, t_data data, t_segment *segment)
{
	t_point		tmp;
	t_segment	tmpsegment;

	wall->left.a.x = data.win_width / 2 + polygon->newsegment.a.y * data.win_width / 2 / polygon->newsegment.a.x;
	wall->right.a.x = data.win_width / 2 + polygon->newsegment.b.y * data.win_width / 2 / polygon->newsegment.b.x;
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
	//printf("(dans raycastx) wall->left.a.x = %f\tet\twall->right.a.x = %f\n", wall->left.a.x, wall->right.a.x);
	if (wall->left.a.x >= wall->right.a.x ||
		wall->right.a.x < 0 || wall->left.a.x > data.win_width)
		return (0);
	return (1);
}

int		raycastx_img(t_player player, t_polygon *polygon, t_segment segment)
{
	double	s;
//	double	r;

	polygon->newangle = polygon->angle + player.angle;
	polygon->r = (-segment.a.x * (segment.b.x - segment.a.x)
		 + (-segment.a.y * (segment.b.y - segment.a.y)))
		/ (polygon->len * polygon->len);
	polygon->btobp = polygon->r * polygon->len;
	//printf("polygon->btobp = %f\n", polygon->btobp);
	s = (segment.a.y * (segment.b.x - segment.a.x)
		 - (segment.a.x * (segment.b.y - segment.a.y)))
		/ (polygon->len * polygon->len);
	polygon->pdist = s * polygon->len;
	//printf("polygon->pdist = %f\n", polygon->pdist);
	//printf("s = %f\n", s);
	return (1);
}

int			raycastfps(t_wall *wall, t_player player, t_polygon polygon, t_data data)
{
	int		ret;
	double	res;

	ret = 1;
	wall->leftcl = dup_segment(wall->left);
	wall->rightcl = dup_segment(wall->right);
	(void)res;
	//printf("player.dfoc = %f\n", player.dfoc);
	wall->leftcl.b.y = player.dfoc * (data.cubside / 2) / polygon.newsegment.a.x;
	wall->leftcl.a.y = -wall->leftcl.b.y;
	ret = translate_segment(&wall->leftcl, 0, data.win_height / 2);
	wall->rightcl.b.y = player.dfoc * (data.cubside / 2) / polygon.newsegment.b.x;
	wall->rightcl.a.y = -wall->rightcl.b.y;
	ret = translate_segment(&wall->rightcl, 0, data.win_height / 2);
	//printf("ret = %d\n", ret);
	//printf("(dans raycastfps) polygon.newsegment.a.x = %f\n", polygon.newsegment.a.x);
	//printf("(dans raycastfps) wall->rightcl.a.y = %f\tet\twall->rightcl.b.y = %f\n", wall->rightcl.a.y, wall->rightcl.b.y);
	return (ret);
}

// !! IMportant !! : gerer si l'objet est devant ou derriere mur
int				raycastxobj(t_object *object, t_data data)//, t_segment *segment)
{
	int		ret;

	ret = 1;
	//if (object->xstartcl > object->xendcl)
	//	inverser
	//data.win_width / 2 + polygon->newsegment.a.y * data.win_width / 2 / polygon->newsegment.a.x;
	object->xstartcl = data.win_width / 2 + (object->newpos.y - object->width / 2) * data.win_width / 2 / object->newpos.x;
	object->xmiddlecl = data.win_width / 2 + (object->newpos.y) * data.win_width / 2 / object->newpos.x;
	object->xendcl = data.win_width / 2 + (object->newpos.y + object->width / 2) * data.win_width / 2 / object->newpos.x;
	object->xstart = object->xstartcl;
	printf("object->xstartcl = %f\tet\tobject->xendcl = %f\n", object->xstartcl, object->xendcl);
	printf("object->newpos.y = %f\n", object->newpos.y);
	//sleep(3);
	if (object->xstartcl == object->xendcl ||
		object->xendcl < 0 || object->xstartcl > data.win_width)
		return (0);
	return (1);
}

int					raycastfpsobj(t_object *object, t_player player, t_data data)
{
	object->fakebot = data.win_height / 2 + (player.dfoc * (data.cubside / 2) / object->newpos.x);
	object->bot = data.win_height / 2 + (player.dfoc * (object->height / 2) / object->newpos.x);
	object->bot += object->fakebot - object->bot;
	object->faketop = data.win_height / 2 + (player.dfoc * (-data.cubside / 2) / object->newpos.x);
	object->top = data.win_height / 2 + (player.dfoc * (-object->height / 2) / object->newpos.x);
	object->top += object->top - object->faketop;
	if (object->top == object->bot)
		return (-1);
	object->topcl = object->top;
	object->botcl = object->bot;
	return (1);
}
