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
	set_player_pos(player, cos(player->angle), sin(player->angle));
}

void			move_backward(t_player *player)
{
	set_player_pos(player, -cos(player->angle), -sin(player->angle));
}

void			move_right(t_player *player)
{
	set_player_pos(player, cos(player->angle + to_rad(90.)), sin(player->angle + to_rad(90.)));
}

void			move_left(t_player *player)
{
	set_player_pos(player, cos(player->angle - to_rad(90.)), sin(player->angle - to_rad(90.)));
}

void			set_player_pos(t_player *player, double x, double z)
{
	player->x += x / FPS * player->speed;
	player->z += z / FPS * player->speed;
}
