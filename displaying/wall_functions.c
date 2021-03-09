/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:16:53 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:00:49 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	clip(t_wall *wall)
{
	wall->rightcl.a.x = min(wall->rightcl.a.x, data->win_width - 1);
	if (wall->leftcl.a.x < 0)
	{
		wall->leftcl.a.x = 0;
		wall->top -= (double)wall->leftcl.a.x * wall->deltatop;
		wall->bot -= (double)wall->leftcl.a.y * wall->deltabot;
	}
}

void	initbe4display(t_wall *wall, int *countcol, t_data *data)
{
	wall->img = mlx_new_image(data->ptr, wall->realside, wall->realside);
	wall->img_data = (int *)mlx_get_data_addr(wall->img, &wall->bpp,
	&wall->size_line, &wall->endian);
	clip(wall);
	*countcol = wall->rightcl.a.x - 1;
	wall->nbcoldone = 0;
}

void	set_delta(t_wall *wall)
{
	wall->deltatop = (wall->newright.a.y - wall->newleft.a.y) /
	(wall->newright.a.x - wall->newleft.a.x);
	wall->deltatop = (wall->newright.b.y - wall->newleft.b.y) /
	(wall->newright.a.x - wall->newleft.a.x);
}
