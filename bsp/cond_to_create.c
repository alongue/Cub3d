/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_to_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:06:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 15:45:26 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		cond_top(t_map *map, int x, int y)
{
	printf("EXC_BAD_ACCESS test\n");
	printf("x = %d\tet\ty = %d\tet\tcond_top\n", x, y);
	printf("map->cub[y][x].exist -> %d\t", map->cub[y][x].exist);
	printf("map->cub[y][x - 1].exist -> %d\t", map->cub[y][x - 1].exist);
	printf("map->cub[y - 1][x].exist -> %d\t", map->cub[y - 1][x].exist);
	printf("map->cub[y - 1][x - 1].exist -> %d\t", map->cub[y - 1][x - 1].exist);
	if ((map->cub[y][x].exist && !map->cub[y][x - 1].exist
		&& !map->cub[y - 1][x - 1].exist && !map->cub[y - 1][x].exist)
		|| (map->cub[y][x].exist
		&& map->cub[y - 1][x - 1].exist && !map->cub[y - 1][x].exist))
		return (1);
	return (0);
}

int		cond_bot(t_map *map, int x, int y)
{
	printf("x = %d\tet\ty = %d\tet\tcond_bot\n", x, y);
	printf("map->cub[y][x].exist -> %d", map->cub[y][x].exist);
	printf("map->cub[y][x - 1].exist -> %d", map->cub[y][x - 1].exist);
	printf("map->cub[y + 1][x - 1].exist -> %d", map->cub[y + 1][x - 1].exist);
	printf("map->cub[y + 1][x].exist -> %d", map->cub[y + 1][x].exist);
	if ((map->cub[y][x].exist && !map->cub[y][x - 1].exist
		&& !map->cub[y + 1][x - 1].exist && !map->cub[y + 1][x].exist)
		|| (map->cub[y][x].exist
		&& map->cub[y + 1][x - 1].exist && !map->cub[y + 1][x].exist))
		return (1);
	return (0);
}

int		cond_right(t_map *map, int x, int y)
{
	printf("x = %d\tet\ty = %d\tet\tcond_right\n", x, y);
	printf("map->cub[y][x].exist -> %d", map->cub[y][x].exist);
	printf("map->cub[y][x + 1].exist -> %d", map->cub[y][x + 1].exist);
	printf("map->cub[y - 1][x].exist -> %d", map->cub[y - 1][x].exist);
	printf("map->cub[y - 1][x + 1].exist -> %d", map->cub[y - 1][x + 1].exist);
	if ((map->cub[y][x].exist && !map->cub[y][x + 1].exist
		&& !map->cub[y - 1][x].exist && !map->cub[y - 1][x + 1].exist)
		|| (map->cub[y][x].exist
		&& map->cub[y - 1][x + 1].exist && !map->cub[y][x + 1].exist))
		return (1);
	return (0);
}

int		cond_left(t_map *map, int x, int y)
{
	printf("x = %d\tet\ty = %d\tet\tcond_left\n", x, y);
	printf("map->cub[y][x].exist -> %d", map->cub[y][x].exist);
	printf("map->cub[y][x - 1].exist -> %d", map->cub[y][x - 1].exist);
	printf("map->cub[y - 1][x - 1].exist -> %d", map->cub[y - 1][x - 1].exist);
	printf("map->cub[y - 1][x].exist -> %d", map->cub[y - 1][x].exist);
	if ((map->cub[y][x].exist && !map->cub[y][x - 1].exist
		&& !map->cub[y - 1][x - 1].exist && !map->cub[y - 1][x].exist)
		|| (map->cub[y][x].exist
		&& map->cub[y - 1][x - 1].exist && !map->cub[y][x - 1].exist))
		return (1);
	return (0);
}
