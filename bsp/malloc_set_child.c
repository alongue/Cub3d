/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_set_child.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:08:12 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 15:07:48 by alongcha         ###   ########.fr       */
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
	while (nodeset[++i].exist)// && nodeset[i].segment.exist)
	{
		side = get_side(splitter, nodeset[i]);
		if (side == FRONT || side == COINCIDING)
		{
			printf("i = %d (dans frontset)\n", i);
			counter++;
		}
		else if (side == SPANNING)

		{
			printf("i = %d (dans frontset)\n", i);
			counter++;
		}
	}
	printf("counter = %d (dans frontset malloc)\n", counter);
	//sleep(4);
	if (!(frontset = malloc(sizeof(t_polygon) * counter + 1)))
	{
		ft_putstr_fd("Error\nfrontset malloc n'a pas fonctione\n", 0);
		return (frontset);
	}
	frontset[counter].exist = 0;
	//frontset[counter].segment.exist = 0;
	while (--counter >= 0)
		frontset[counter].exist = 1;
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
	while (nodeset[++i].exist)// && nodeset[i].segment.exist)
	{
		side = get_side(splitter, nodeset[i]);
		if (side == BACK)
		{
			printf("i = %d (dans backset)\n", i);
			counter++;
		}
		else if (side == SPANNING)
		{
			printf("i = %d (dans backset)\n", i);
			counter++;
		}
	}
	printf("counter = %d (dans backset malloc)\n", counter);
	//sleep(4);
	if (!(backset = malloc(sizeof(t_polygon) * counter + 1)))
	{
		ft_putstr_fd("Error\nbackset malloc n'a pas fonctione\n", 0);
		return (backset);
	}
	backset[counter].exist = 0;
	//backset[counter].segment.exist = 0;
	while (--counter >= 0)
		backset[counter].exist = 1;
	return (backset);
}
