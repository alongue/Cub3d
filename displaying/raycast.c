/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:27:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/06 13:08:27 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		raycast(t_polygon *polygon)
{
	polygon->newsegment.a.x = 160 - polygon->newsegment.a.y * 160 / polygon->newsegment.a.x;
	polygon->newsegment.b.x = 160 - polygon->newsegment.b.y * 160 / polygon->newsegment.b.x;
	if (polygon->newsegment.a.x == polygon->newsegment.b.x ||
		polygon->newsegment.b.x < 0 || polygon->newsegment.a.x > data->win_width - 1)
		return (0);
	return (1);
}

void		raycastfps(t_wall *wall, t_player player)
{
	double	dfoc;

	dfoc = DEFX / 2 / tan(player.fieldvis);
	wall->newleft.a.y = data->win_height / 2 + ((wall->left.a.x - player.x) * DEFY / dfoc);
	wall->newleft.b.y = data->win_height / 2 + ((wall->left.b.x - player.x) * DEFY / dfoc);
	wall->newright.a.y = data->win_height / 2 + ((wall->right.a.x - player.x) * DEFY / dfoc);
	wall->newright.b.y = data->win_height / 2 + ((wall->right.b.x - player.x) * DEFY / dfoc);
}
