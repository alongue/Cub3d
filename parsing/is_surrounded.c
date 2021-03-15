/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_surrounded.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:37:00 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		check_around(t_map map)
{
	int		y;

	y = 0;
	while (y < map.nbymax)
	{
		if (is_outside_xboundaries(y, map))
			return (0);
		y++;
	}
	return (1);
}

int		is_surrounded(t_map map)
{
	int		coor[3];
	char	*strcop;

	coor[0] = -1;
	coor[1] = 0;
	while (++coor[0] < map.nbymax)
	{
		if (!(strcop = ft_strtrim(map.number[coor[0]], " ")))
			return (ft_putstrreti_fd(MALLOC, 0, STDOUT_FILENO));
		coor[1] += ft_strlen(map.number[coor[0]]);
		if (strcop[0] != '1' || strcop[ft_strlen(strcop) - 1] != '1')
			return (ft_putstrreti_fd(WALL, 0,
			ft_free_ret(STDOUT_FILENO, (void **)&strcop, NULL, NULL)));
		free(strcop);
	}
	ft_memseti(coor, 0, 3);
	coor[1] = get_line_nbmin(map.number, 0);
	if (searching_around(&map, coor, BLOCKED) == ISFINISH)
	{
		if (!check_around(map))
			return (0);
		return (1);
	}
	else
		return (0);
}
