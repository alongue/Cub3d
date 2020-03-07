/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:03 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/07 16:57:54 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

# define HEIGHTPL 32

t_player		get_player(int x, int z, int c, double fieldvis)
{
	t_player	player;
	double		angle;

	player.exist = false;
	if (c == 'S')
		angle = 270.;
	else if (c == 'N')
		angle = 90.;
	else if (c == 'E')
		angle = 0.;
	else if (c == 'W')
		angle = 180.;
	else
		return (player);
	player.x = x;
	player.y = HEIGHTPL;
	player.z = z;
	player.pos = get_point(x, z);
	player.angle = angle;
	player.fieldvis = fieldvis;
	player.exist = true;
	return (player);
}

void			set_player(t_player *player, int x, int z, int y)
{
	player->x = x;
	player->y = y;
	player->z = z;
	player->pos = get_point(x, z);
}

void			set_player_angle(t_player *player, double angle)
{
	player->angle = angle;
}
