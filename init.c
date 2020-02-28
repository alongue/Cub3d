/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/28 19:23:03 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init(t_player *player, t_wall *wall, t_data *data, char **av)
{
	// utiliser get_player(, set_wall) et tout
	player->fieldvis = 60;
	wall->realside = 64;   //enlever plus tard
	player->fieldvis = wall->realside / 2;
	data->file = av[1];
	(void)data;
}

void	initcub(t_map *map, int side)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < map->nbcubx)
	{
		j = -1;
		while (++j < map->nbcuby)
			map->cub[i][j].side = side;
	}
}
