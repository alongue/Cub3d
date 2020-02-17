/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cond_to_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 14:06:18 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 22:07:20 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

bool		cond_top(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if ((cub[x][y].exist && !cub[x - 1][y].exist
		&& !cub[x - 1][y - 1].exist && !cub[x][y - 1].exist)
		|| (cub[x][y].exist && cub[x - 1][y].exist
		&& cub[x - 1][y - 1].exist && !cub[x][y - 1].exist
		return (true);
	return (false);
}

bool		cond_bot(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if ((cub[x][y].exist && !cub[x - 1][y].exist
		&& !cub[x + 1][y + 1].exist && !cub[x][y + 1].exist)
		|| (cub[x][y].exist && cub[x - 1][y].exist
		&& cub[x - 1][y + 1].exist && !cub[x][y + 1].exist
		return (true);
	return (false);
}

bool		cond_right(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if ((cub[x][y].exist && !cub[x + 1][y].exist
		&& !cub[x][y - 1].exist && !cub[x + 1][y - 1].exist)
		|| (cub[x][y].exist && cub[x][y - 1].exist
		&& cub[x + 1][y - 1].exist && !cub[x + 1][y].exist
		return (true);
	return (false);
}

bool		cond_left(t_map map, int x, int y)
{
	t_cub	**cub;

	cub = map.cub;
	if ((cub[x][y].exist && !cub[x - 1][y].exist
		&& !cub[x - 1][y - 1].exist && !cub[x][y - 1].exist)
		|| (cub[x][y].exist && cub[x][y - 1].exist
		&& cub[x - 1][y - 1].exist && !cub[x - 1][y].exist
		return (true);
	return (false);
}
