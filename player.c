/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:03 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 17:39:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

# define HEIGHTPL 32

t_player		get_player(int x, int z, int c, double fieldvis)
{
	t_player	player;
	double		angle;

	player.exist = false;
	if (c == 'N')
		angle = 270. * M_PI / 180;
	else if (c == 'S')
		angle = 90. * M_PI / 180;
	else if (c == 'E')
		angle = 0. * M_PI / 180;
	else if (c == 'W')
		angle = 180. * M_PI / 180;
	else
		return (player);
	player.x = x + HEIGHTPL;
	player.y = HEIGHTPL;
	player.z = z + HEIGHTPL;
	player.pos = get_point(x, z);
	player.angle = angle;
	player.speed = 2;
	player.sensi = 2;
	player.fieldvis = fieldvis * M_PI / 180;
	player.exist = true;
	return (player);
}
