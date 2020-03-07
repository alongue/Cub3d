/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:27:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/07 15:28:27 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool		raycast(t_polygon *polygon)
{
	polygon->newsegment.a.x = 160 - polygon->newsegment.a.y * 160 / polygon->newsegment.a.x;
	polygon->newsegment.b.x = 160 - polygon->newsegment.b.y * 160 / polygon->newsegment.b.x;
	if (polygon->newsegment.a.x == polygon->newsegment.b.x ||
		polygon->newsegment.b.x < 0 || polygon->newsegment.a.x > 319)
		return (false);
	return (true);
}

void		raycastfps(t_wall *wall, t_player player)
{
	double	dfoc;

	dfoc = DEFX / 2 / tan(player.fieldvis);
	wall->left.a.y = 100 + ((wall->left.a.x - player.x) * DEFY / dfoc);
	wall->left.b.y = 100 + ((wall->left.b.x - player.x) * DEFY / dfoc);
	wall->right.a.y = 100 + ((wall->right.a.x - player.x) * DEFY / dfoc);
	wall->right.b.y = 100 + ((wall->right.b.x - player.x) * DEFY / dfoc);
}
