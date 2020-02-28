/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:03 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/05 14:11:58 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

# define HEIGHTPL 32

t_player		get_player(int x, int z, double angle, double fieldvis)
{
	t_player player;

	player.x = x;
	player.y = HEIGHTPL;
	player.z = z;
	player.angle = angle;
	player.fieldvis = fieldvis;
	return (player);
}

void			set_player(t_player *player, int x, int z, int y)
{
	player->x = x;
	player->y = y;
	player->z = z;
}

void			set_player_angle(t_player *player, double angle)
{
	player->angle = angle;
}