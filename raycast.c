/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:27:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 18:50:20 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool		raycastx(t_wall *wall, t_polygon polygon)
{
	int		mini;

	wall->left.a.x = 160 - polygon.newsegment.a.y * DEFX / 2 / polygon.newsegment.a.x;
	wall->right.a.x = 160 - polygon.newsegment.b.y * DEFX / 2 / polygon.newsegment.b.x;
	if (wall->left.a.x > wall->right.a.x) // je suis pas cense mettre de code comme ca
	{
		mini = wall->left.a.x;
		wall->left.a.x = wall->right.a.x;
		wall->right.a.x = mini;
	}
	printf("(dans raycastx) wall->right.a.x = %d\tet\twall->left.a.x = %d\n", wall->right.a.x, wall->left.a.x);
	if (wall->left.a.x == wall->right.a.x ||
		wall->right.a.x < 0 || wall->left.a.x > 319)
		return (false);
	return (true);
}

int			raycastfps(t_wall *wall, t_player player, t_polygon polygon, int cubside)
{
	double	dfoc;
	int		ret;
	double	res;

	ret = 1;
	wall->leftcl = dup_segment(wall->left);
	wall->rightcl = dup_segment(wall->right);
	dfoc = DEFX / 2 / tan(player.fieldvis / 2);
	(void)res;
	printf("dfoc = %f\n", dfoc);
	wall->leftcl.b.y = (int)sqrt(pow((dfoc * sqrt(pow(polygon.newsegment.a.x, 2) + pow(cubside / 2, 2)) / cubside), 2) - pow(dfoc, 2));
	wall->leftcl.a.y = -wall->leftcl.b.y;
	ret = translate_segment(&wall->leftcl, 0, 100);
	wall->rightcl.b.y = (int)sqrt(pow((dfoc * sqrt(pow(polygon.newsegment.b.x, 2) + pow(cubside / 2, 2)) / cubside), 2) - pow(dfoc, 2));
	wall->rightcl.a.y = -wall->rightcl.b.y;
	ret = translate_segment(&wall->rightcl, 0, 100);
	printf("ret = %d\n", ret);
	printf("(dans raycastfps) polygon.newsegment.a.x = %d\n", polygon.newsegment.a.x);
	printf("(dans raycastfps) wall->rightcl.a.y = %d\tet\twall->leftcl.a.y = %d\n", wall->rightcl.a.y, wall->leftcl.a.y);
	return (ret);
}
