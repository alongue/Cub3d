/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 14:29:51 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/09 14:31:04 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int			get_cub(t_map *map, t_player *player, t_data data, int i)
{
	int			counter;

	counter = -1;
	while (map->number[i][++counter])
	{
		if (map->number[i][counter] == '1')
			set_cub(data, &map->cub[i][counter], i, counter);
		else if (map->number[i][counter] == '2' &&
		!set_obj(data, map, i, counter))
			return (free_player(0, player, NULL));
		else if (ft_get_nbchar("SNEW", map->number[i][counter]) == 1)
		{
			if (player->exist)
				return (free_player(0, player, PLAYERS));
			*player = get_player(counter * data.cubside, i *
			data.cubside, map->number[i][counter], data);
			if (!player->exist)
				return (free_player(0, player, NULL));
			map->cub[i][counter].exist = 0;
		}
		else
			map->cub[i][counter].exist = 0;
	}
	return (1);
}

int			get_nbcuby(t_map *map, int xmax, int nblin)
{
	int		x;
	int		y[2];

	x = -1;
	if (!(map->nbcuby = malloc(sizeof(int) * (xmax + 1))))
		return (ft_putstrreti_fd(MALLOC, 0, STDOUT_FILENO));
	while (++x < xmax)
	{
		y[0] = 0;
		while (y[0] < nblin && map->number[y[0]][x] == ' ')
			y[0]++;
		y[1] = nblin - 1;
		while (y[1] > 0 && map->number[y[1]][x] == ' ')
			y[1]--;
		map->nbcuby[x] = (y[1] - y[0] + 1 < 0) ? 0 : y[1] - y[0] + 1;
	}
	map->nbcuby[xmax] = -1;
	map->nbxcharmax = get_nbxcharmax(map->nbcuby);
	map->nbxmax = get_nbxmax(map->number);
	map->nbymax = get_nbymax(map->nbcuby);
	if (map->nbxmax < 3)
		return (ft_putstrreti_fd(MAP, 0, STDOUT_FILENO));
	return (1);
}
