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

bool		cond_top(t_map map, int x, int y)
{
	printf("map.cub[y][x].exist -> %d", map.cub[y][x].exist);
	printf("map.cub[y][x - 1].exist -> %d", map.cub[y][x - 1].exist);
	printf("map.cub[y - 1][x].exist -> %d", map.cub[y - 1][x].exist);
	printf("map.cub[y - 1][x - 1].exist -> %d", map.cub[y - 1][x - 1].exist);
	if ((map.cub[y][x].exist && !map.cub[y][x - 1].exist
		&& !map.cub[y - 1][x - 1].exist && !map.cub[y - 1][x].exist)
		|| (map.cub[y][x].exist
		&& map.cub[y - 1][x - 1].exist && !map.cub[y - 1][x].exist))
		return (true);
	return (false);
}

bool		cond_bot(t_map map, int x, int y)
{
	printf("map.cub[y][x].exist -> %d", map.cub[y][x].exist);
	printf("map.cub[y][x - 1].exist -> %d", map.cub[y][x - 1].exist);
	printf("map.cub[y + 1][x - 1].exist -> %d", map.cub[y + 1][x - 1].exist);
	printf("map.cub[y + 1][x].exist -> %d", map.cub[y + 1][x].exist);
	if ((map.cub[y][x].exist && !map.cub[y][x - 1].exist
		&& !map.cub[y + 1][x - 1].exist && !map.cub[y + 1][x].exist)
		|| (map.cub[y][x].exist
		&& map.cub[y + 1][x - 1].exist && !map.cub[y + 1][x].exist))
		return (true);
	return (false);
}

bool		cond_right(t_map map, int x, int y)
{
	printf("map.cub[y][x].exist -> %d", map.cub[y][x].exist);
	printf("map.cub[y][x + 1].exist -> %d", map.cub[y][x + 1].exist);
	printf("map.cub[y - 1][x].exist -> %d", map.cub[y - 1][x].exist);
	printf("map.cub[y - 1][x + 1].exist -> %d", map.cub[y - 1][x + 1].exist);
	if ((map.cub[y][x].exist && !map.cub[y][x + 1].exist
		&& !map.cub[y - 1][x].exist && !map.cub[y - 1][x + 1].exist)
		|| (map.cub[y][x].exist
		&& map.cub[y - 1][x + 1].exist && !map.cub[y][x + 1].exist))
		return (true);
	return (false);
}

bool		cond_left(t_map map, int x, int y)
{
	printf("map.cub[y][x].exist -> %d", map.cub[y][x].exist);
	printf("map.cub[y][x - 1].exist -> %d", map.cub[y][x - 1].exist);
	printf("map.cub[y - 1][x - 1].exist -> %d", map.cub[y - 1][x - 1].exist);
	printf("map.cub[y - 1][x].exist -> %d", map.cub[y - 1][x].exist);
	if ((map.cub[y][x].exist && !map.cub[y][x - 1].exist
		&& !map.cub[y - 1][x - 1].exist && !map.cub[y - 1][x].exist)
		|| (map.cub[y][x].exist
		&& map.cub[y - 1][x - 1].exist && !map.cub[y][x - 1].exist))
		return (true);
	return (false);
}
