/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:35:03 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/11 17:39:25 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void			turn_left(t_player *player)
{
	player->angle += (float)(player->sensi * M_PI / 180);
}

void			turn_right(t_player *player)
{
	printf("player->angle = %f\n", player->angle);
	player->angle -= (float)(player->sensi * M_PI / 180);
	printf("player->angle = %f\n", player->angle);
}
