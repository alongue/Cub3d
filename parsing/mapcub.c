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
			return (0);
		else if (ft_get_nbchar("SNEW", map->number[i][counter]) == 1)
		{
			if (player->exist)
			{
				return (ft_putstrreti_fd(
				"Error\nUn seul joueur est accepte sur la map.\n", 0, 0));
			}
			*player = get_player(counter * data.cubside, i *
			data.cubside, map->number[i][counter], data);
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
		while (map->number[y[0]][x] == ' ' && y[0] < nblin)
			y[0]++;
		y[1] = nblin - 1;
		while (map->number[y[1]][x] == ' ' && y[1] > 0)
			y[1]--;
		map->nbcuby[x] = (y[1] - y[0] + 1 < 0) ? 0 : y[1] - y[0] + 1;
	}
	map->nbcuby[xmax] = -1;
	map->nbxmax = get_nbxmax(map->nbcuby);
	map->nbymax = get_nbymax(map->nbcuby);
	return (1);
}
