/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ceilfloor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:02:24 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:58:43 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		display_ceilfloor(t_data *data)
{
	int x;
	int y;

	y = -1;
	while (++y < data->win_height)
	{
		x = -1;
		if (y < data->win_height / 2)
			while (++x < data->win_width)
				data->img_data[y * data->win_width + x] = data->colceil;
		else
			while (++x < data->win_width)
				data->img_data[y * data->win_width + x] = data->colfloor;
	}
	return (1);
}
