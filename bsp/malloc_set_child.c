/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_set_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:08:12 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:59:30 by erlajoua         ###   ########.fr       */
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
		if (side == FRONT || side == COINCIDING)
		{
			counter++;
		}
		else if (side == SPANNING)

		{
			counter++;
		}
	}
	if (!(frontset = malloc(sizeof(t_polygon) * counter + 1)))
	{
		ft_putstr_fd("Error\nfrontset malloc n'a pas fonctione\n", 0);
		return (frontset);
	}
	frontset[counter].exist = 0;
	while (--counter >= 0)
	{
		frontset[counter].exist = 1;
	}
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
		{
			counter++;
		}
		else if (side == SPANNING)
		{
			counter++;
		}
	}
	if (!(backset = malloc(sizeof(t_polygon) * counter + 1)))
	{
		ft_putstr_fd("Error\nbackset malloc n'a pas fonctione\n", 0);
		return (backset);
	}
	backset[counter].exist = 0;
	while (--counter >= 0)
	{
		backset[counter].exist = 1;
	}
	return (backset);
}
