/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_ceilfloor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 11:02:24 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/12 13:13:33 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int display_ceilfloor(t_data data)
{
    int x;
    int y;

    y = -1;
    printf("Width = %d\tet\tHeight = %d\n", data.win_width, data.win_height);
	while (++y < data.win_height)
	{
        x = -1;
        if (y < data.win_height / 2)
            while (++x < data.win_width)
                data.img_data[y * data.win_width + x] = data.colceil; //Le segfault vient tres surement de data.win_width
        else
            while (++x < data.win_width)
                data.img_data[y * data.win_width + x] = data.colfloor;
	}
    return (1);
}