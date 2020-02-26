/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:27:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/05 11:01:39 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool		raycast(t_wall *wall)
{
	wall->newleft.a.x = 160 - wall->newleft.a.y * 160 / wall->newleft.a.x;
	wall->newright.a.x = 160 - wall->newright.a.y * 160 / wall->newright.a.x;
	if (wall->newleft.a.x == wall->newright.a.x ||
		wall->newright.a.x < 0 || wall->newleft.a.x > 319)
		return (false);
	return (true);
}
