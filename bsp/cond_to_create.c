/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_to_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:06:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/02 17:55:52 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool		cond_top(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if ((cub[y][x].exist && !cub[y][x - 1].exist
		&& !cub[y - 1][x - 1].exist && !cub[y - 1][x].exist)
		|| (cub[y][x].exist && cub[y][x - 1].exist
		&& cub[y - 1][x - 1].exist && !cub[y - 1][x].exist))
		return (true);
	return (false);
}

bool		cond_bot(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	printf("x = %d\t\tet\t\ty = %d\ncub[x][y].exist = %d\n", x, y, cub[x][y].exist);
	if ((cub[y][x].exist && !cub[y][x - 1].exist
		&& !cub[y + 1][x + 1].exist && !cub[y + 1][x].exist)
		|| (cub[y][x].exist && cub[y][x - 1].exist
		&& cub[y - 1][x + 1].exist && !cub[y + 1][x].exist))
		return (true);
	return (false);
}

bool		cond_right(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if ((cub[y][x].exist && !cub[y][x + 1].exist
		&& !cub[y - 1][x].exist && !cub[y + 1][x - 1].exist)
		|| (cub[y][x].exist && cub[y - 1][x].exist
		&& cub[y + 1][x - 1].exist && !cub[y][x + 1].exist))
		return (true);
	return (false);
}

bool		cond_left(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if ((cub[y][x].exist && !cub[y][x - 1].exist
		&& !cub[y - 1][x - 1].exist && !cub[y - 1][x].exist)
		|| (cub[y][x].exist && cub[y - 1][x].exist
		&& cub[y - 1][x - 1].exist && !cub[y][x - 1].exist))
		return (true);
	return (false);
}
