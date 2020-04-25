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

bool		raycastx(t_wall *wall, t_polygon *polygon, t_data data)
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
	}
	printf("(dans raycastx) wall->left.a.x = %f\tet\twall->right.a.x = %f\n", wall->left.a.x, wall->right.a.x);
	if (wall->left.a.x >= wall->right.a.x ||
		wall->right.a.x < 0 || wall->left.a.x > data.win_width)
		return (false);
	return (true);
}

bool		raycastx_img(t_player player, t_polygon *polygon)
{
	if (polygon->newsegment.a.x < ZMIN && polygon->newsegment.b.x < ZMIN)
		return ((polygon->dodisplay = false));
	polygon->newangle = polygon->angle + to_rad(-player.angle);
	polygon->btobp = (-polygon->newsegment.b.y * (polygon->newsegment.b.x - polygon->newsegment.a.x)
		 + (-polygon->newsegment.a.y * (polygon->newsegment.b.y - polygon->newsegment.a.y)))
		/ pow(polygon->len, 2) * polygon->len;
	polygon->pdist = (polygon->newsegment.a.y * (polygon->newsegment.b.x - polygon->newsegment.a.x)
		 - (polygon->newsegment.a.x * (polygon->newsegment.b.y - polygon->newsegment.a.y)))
		/ pow(polygon->len, 2) * polygon->len;
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
	printf("player.dfoc = %f\n", player.dfoc);
	wall->leftcl.b.y = player.dfoc * (data.cubside / 2) / polygon.newsegment.a.x;
	wall->leftcl.a.y = -wall->leftcl.b.y;
	ret = translate_segment(&wall->leftcl, 0, data.win_height / 2);
	wall->rightcl.b.y = player.dfoc * (data.cubside / 2) / polygon.newsegment.b.x;
	wall->rightcl.a.y = -wall->rightcl.b.y;
	ret = translate_segment(&wall->rightcl, 0, data.win_height / 2);
	printf("ret = %d\n", ret);
	printf("(dans raycastfps) polygon.newsegment.a.x = %f\n", polygon.newsegment.a.x);
	printf("(dans raycastfps) wall->rightcl.a.y = %f\tet\twall->rightcl.b.y = %f\n", wall->rightcl.a.y, wall->rightcl.b.y);
	return (ret);
}
