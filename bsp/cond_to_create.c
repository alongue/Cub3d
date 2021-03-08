/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_to_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:06:18 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:58:31 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		cond_top(t_map *map, int x, int y)
{
	if ((map->cub[y][x].exist && !map->cub[y][x - 1].exist
		&& !map->cub[y - 1][x - 1].exist && !map->cub[y - 1][x].exist)
		|| (map->cub[y][x].exist
		&& map->cub[y - 1][x - 1].exist && !map->cub[y - 1][x].exist))
		return (1);
	return (0);
}

int		cond_bot(t_map *map, int x, int y)
{
	if ((map->cub[y][x].exist && !map->cub[y][x - 1].exist
		&& !map->cub[y + 1][x - 1].exist && !map->cub[y + 1][x].exist)
		|| (map->cub[y][x].exist
		&& map->cub[y + 1][x - 1].exist && !map->cub[y + 1][x].exist))
		return (1);
	return (0);
}

int		cond_right(t_map *map, int x, int y)
{
	if ((map->cub[y][x].exist && !map->cub[y][x + 1].exist
		&& !map->cub[y - 1][x].exist && !map->cub[y - 1][x + 1].exist)
		|| (map->cub[y][x].exist
		&& map->cub[y - 1][x + 1].exist && !map->cub[y][x + 1].exist))
		return (1);
	return (0);
}

int		cond_left(t_map *map, int x, int y)
{
	if ((map->cub[y][x].exist && !map->cub[y][x - 1].exist
		&& !map->cub[y - 1][x - 1].exist && !map->cub[y - 1][x].exist)
		|| (map->cub[y][x].exist
		&& map->cub[y - 1][x - 1].exist && !map->cub[y][x - 1].exist))
		return (1);
	return (0);
}
