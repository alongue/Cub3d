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

bool		raycastx(t_wall *wall, t_polygon polygon, t_data data)
{
	wall->left.a.x = data.win_width / 2 - polygon.newsegment.a.y * data.win_width / 2 / polygon.newsegment.a.x;
	wall->right.a.x = data.win_width / 2 - polygon.newsegment.b.y * data.win_width / 2 / polygon.newsegment.b.x;
	printf("(dans raycastx) wall->left.a.x = %f\tet\twall->right.a.x = %f\n", wall->left.a.x, wall->right.a.x);
	if (wall->left.a.x == wall->right.a.x ||
		wall->right.a.x < 0 || wall->left.a.x > data.win_width)
		return (false);
	return (true);
}

int			raycastfps(t_wall *wall, t_player player, t_polygon polygon, t_data data)
{
	double	dfoc;
	int		ret;
	double	res;

	ret = 1;
	wall->leftcl = dup_segment(wall->left);
	wall->rightcl = dup_segment(wall->right);
	dfoc = data.win_width / 2 / tan(player.fieldvis / 2);
	(void)res;
	printf("dfoc = %f\n", dfoc);
	wall->leftcl.b.y = dfoc * (data.cubside / 2) / polygon.newsegment.a.x;
	wall->leftcl.a.y = -wall->leftcl.b.y;
	ret = translate_segment(&wall->leftcl, 0, data.win_height / 2);
	wall->rightcl.b.y = dfoc * (data.cubside / 2) / polygon.newsegment.b.x;
	wall->rightcl.a.y = -wall->rightcl.b.y;
	ret = translate_segment(&wall->rightcl, 0, data.win_height / 2);
	printf("ret = %d\n", ret);
	printf("(dans raycastfps) polygon.newsegment.a.x = %f\n", polygon.newsegment.a.x);
	printf("(dans raycastfps) wall->rightcl.a.y = %f\tet\twall->rightcl.b.y = %f\n", wall->rightcl.a.y, wall->rightcl.b.y);
	return (ret);
}
