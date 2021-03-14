/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:16:53 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:04:08 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	clip(t_wall *wall, t_data data)
{
	wall->rightcl.a.x = min(wall->rightcl.a.x, data.win_width - 1);
	wall->rightcl.b.x = min(wall->rightcl.b.x, data.win_width - 1);
	wall->top = (double)wall->leftcl.a.y;
	wall->bot = (double)wall->leftcl.b.y;
	if (wall->leftcl.a.x < 0 || wall->leftcl.b.x < 0)
	{
		wall->top -= (double)(wall->leftcl.a.x * wall->deltatop);
		wall->bot -= (double)(wall->leftcl.a.x * wall->deltabot);
		wall->leftcl.a.x = 0;
		wall->leftcl.b.x = 0;
	}
}

void	set_delta(t_wall *wall)
{
	wall->deltatop = (wall->rightcl.a.y - wall->leftcl.a.y)
	/ (wall->rightcl.a.x - wall->leftcl.a.x);
	wall->deltabot = (wall->rightcl.b.y - wall->leftcl.b.y)
	/ (wall->rightcl.a.x - wall->leftcl.a.x);
}

void	initbe4display(t_wall *wall, int *countcol, t_data *data)
{
	clip(wall, *data);
	wall->img_data = (int *)mlx_get_data_addr(data->img,
	&wall->bpp, &wall->size_line, &wall->endian);
	wall->data_file = (int *)mlx_get_data_addr(wall->img,
	&wall->bppimg, &wall->size_lineimg, &wall->endianimg);
	*countcol = (int)round(wall->leftcl.a.x) - 1;
}

int		can_draw(t_wall wall, t_data *data, int index)
{
	if ((!data->coldone[index] ||
		wall.bot - wall.top > data->heightcol[index]))
	{
		data->heightcol[index] = wall.bot - wall.top;
		if (data->coldone[index] == 0)
			data->nbcoldone++;
		return (1);
	}
	else
		return (0);
}
