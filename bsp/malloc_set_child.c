/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_set_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:08:12 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/06 12:12:41 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_polygon	*malloc_frontset_child(t_polygon *nodeset, t_polygon splitter)
{
	int			i;
	int			counter;
	int			side;
	t_polygon	*frontset;

	i = -1;
	counter = 0;
	while (nodeset[++i].exist)
	{
		side = get_side(splitter, nodeset[i]);
		if (side == FRONT)
			counter++;
		else if (side == SPANNING)
			counter++;
	}
	frontset = malloc(sizeof(t_polygon) * counter);
	return (frontset);
}

t_polygon	*malloc_backset_child(t_polygon *nodeset, t_polygon splitter)
{
	int			i;
	int			counter;
	int			side;
	t_polygon	*backset;

	i = -1;
	counter = 0;
	while (nodeset[++i].exist)
	{
		side = get_side(splitter, nodeset[i]);
		if (side == BACK)
			counter++;
		else if (side == SPANNING)
			counter++;
	}
	backset = malloc(sizeof(t_polygon) * counter);
	return (backset);
}
