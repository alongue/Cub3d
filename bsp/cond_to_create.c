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
	t_cub	**cub;

	cub = map.cub;
	if (x == get_nbxmax(map.nbcuby) - 1 || x == 0 || y == 0)
		return (false);
	if ((y == get_nbymax(map.nbcuby) - 1 && cub[y][x].exist)
		|| (cub[y][x].exist && !cub[y][x - 1].exist
		&& !cub[y - 1][x - 1].exist && !cub[y - 1][x].exist)
		|| (cub[y][x].exist
		&& cub[y - 1][x - 1].exist && !cub[y - 1][x].exist))
		return (true);
	return (false);
}

bool		cond_bot(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if (x == get_nbxmax(map.nbcuby) - 1 || x == 0 || y == get_nbymax(map.nbcuby) - 1)
		return (false);
	if ((y == 0 && cub[y][x].exist)
		|| (cub[y][x].exist && !cub[y][x - 1].exist
		&& !cub[y + 1][x - 1].exist && !cub[y + 1][x].exist)
		|| (cub[y][x].exist
		&& cub[y + 1][x - 1].exist && !cub[y + 1][x].exist))
		return (true);
	return (false);
}

bool		cond_right(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if (x == get_nbxmax(map.nbcuby) - 1 || y == 0 || y == get_nbymax(map.nbcuby) - 1)
		return (false);
	if ((x == 0 && cub[y][x].exist)
		|| (cub[y][x].exist && !cub[y][x - 1].exist
		&& !cub[y - 1][x].exist && !cub[y - 1][x + 1].exist)
		|| (cub[y][x].exist
		&& cub[y - 1][x + 1].exist && !cub[y][x + 1].exist))
		return (true);
	return (false);
}

bool		cond_left(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if (x == 0 || y == 0 || y == get_nbymax(map.nbcuby) - 1)
		return (false);
	if ((x == get_nbxmax(map.nbcuby) - 1 && cub[y][x].exist)
		|| (cub[y][x].exist && !cub[y][x - 1].exist
		&& !cub[y - 1][x - 1].exist && !cub[y - 1][x].exist)
		|| (cub[y][x].exist
		&& cub[y - 1][x - 1].exist && !cub[y][x - 1].exist))
		return (true);
	return (false);
}
