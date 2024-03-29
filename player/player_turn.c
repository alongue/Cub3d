/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:03 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 19:50:50 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define HALF_LIMIT_ANGLE M_PI

void			turn_left(t_player *player)
{
	set_player_angle(player, to_rad(-player->sensi));
}

void			turn_right(t_player *player)
{
	set_player_angle(player, to_rad(player->sensi));
}

void			set_player_angle(t_player *player, double angle)
{
	player->angle += angle / 60;
	while (player->angle < 0 || player->angle > 2 * HALF_LIMIT_ANGLE)
	{
		if (player->angle < 0)
			player->angle = 2 * HALF_LIMIT_ANGLE + player->angle;
		if (player->angle > 2 * HALF_LIMIT_ANGLE)
			player->angle = player->angle - 2 * HALF_LIMIT_ANGLE;
	}
}
