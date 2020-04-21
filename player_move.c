/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:03 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 17:39:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			move_forward(t_player *player)
{
	player->speed = fabsf(player->speed);
	player->x += (float)(cos(player->angle)) * player->speed;
	player->z += (float)(sin(player->angle)) * player->speed;
}

void			move_backward(t_player *player)
{
	player->speed = -fabsf(player->speed);
	player->x += (float)(cos(player->angle)) * player->speed;
	player->z += (float)(sin(player->angle)) * player->speed;
}

void			move_right(t_player *player)
{
	player->speed = fabsf(player->speed);
	player->x += (float)(cos(player->angle + 90 * M_PI / 180)) * player->speed;
	player->z += (float)(sin(player->angle)) * player->speed;
}

void			move_left(t_player *player)
{
	player->speed = fabsf(player->speed);
	player->x += (float)(cos(player->angle - 90 * M_PI / 180)) * player->speed;
	player->z += (float)(sin(player->angle)) * player->speed;
}
