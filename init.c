/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:41:07 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/07 19:41:19 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initcub(t_map *map, int side)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < map->nbcuby)
	{
		j = -1;
		while (++j < map->nbcubx)
			map->cub[i][j].side = side;
	}
}

//void	initobj()
