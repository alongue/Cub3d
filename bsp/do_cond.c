/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cond.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:40:28 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/13 19:40:40 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int		do_cond_top(t_map *map, int i, t_data *data)
{
	map->tree.rootnode->set[i++] = create_polytop(map,
	data->currentCubIndex, *data);
	map->tree.rootnode->set[i - 1].isused = 0;
	if (iserror(map->tree.rootnode->set, i))
		return (-1);
	return (i);
}

int		do_cond_bot(t_map *map, int i, t_data *data)
{
	map->tree.rootnode->set[i++] = create_polybot(map,
	data->currentCubIndex, *data);
	map->tree.rootnode->set[i - 1].isused = 0;
	if (iserror(map->tree.rootnode->set, i))
		return (-1);
	return (i);
}

int		do_cond_right(t_map *map, int i, t_data *data)
{
	map->tree.rootnode->set[i++] = create_polyright(map,
	data->currentCubIndex, *data);
	map->tree.rootnode->set[i - 1].isused = 0;
	if (iserror(map->tree.rootnode->set, i))
		return (-1);
	return (i);
}

int		do_cond_left(t_map *map, int i, t_data *data)
{
	map->tree.rootnode->set[i++] = create_polyleft(map,
	data->currentCubIndex, *data);
	map->tree.rootnode->set[i - 1].isused = 0;
	if (iserror(map->tree.rootnode->set, i))
		return (-1);
	return (i);
}
