/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 20:55:39 by erlajoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define MINSCALE 2

void		set_ratio(int *nb, float *relation, t_polygon currentpoly, t_polygon *set)
{
	int	i;
	int	side;

	i = -1;
	while (set[++i].exist)
		if (!is_same_segment(set[i].segment, currentpoly.segment))
		{
			side = get_side(currentpoly, set[i]);
			if (side == FRONT)
				nb[0] += 1;
			else if (side == BACK)
				nb[1] += 1;
			else if (side == SPANNING)
				nb[2] += 1;
			if (nb[0] <= nb[1] && nb[1] != 0)
				*relation = (float)nb[0] / nb[1];
			else if (nb[0] >= nb[1] && nb[0] != 0)
				*relation = (float)nb[1] / nb[0];
		}
}

void		set_best_poly(t_polygon *poly, t_polygon *set,
						float minrelation, int *leastsplits)
{
	int		nb[3];
	float	bestrelation;
	float	relation;

	bestrelation = 0.;
	relation = 0.;
	ft_memseti(nb, 0, 3);
	set_ratio(nb, &relation, poly[0], set);
	if (relation >= minrelation &&
		((nb[2] < *leastsplits) || (relation > bestrelation)))
	{
		*leastsplits = nb[2];
		bestrelation = relation;
		set_used_poly(set, &poly[0]);
		poly[1] = get_polygon(poly[0]);
	}
}

t_polygon	choose_div_polygon(t_polygon *set)
{
	t_polygon	poly[2];
	int			i;
	float		minrelation;
	int			leastsplits;

	poly[1].isused = 0;
	minrelation = (is_pair(polysetlen(set))) ? (float)(polysetlen(set) / 2 - 1) / (polysetlen(set) / 2 + 1) : 1.;
	leastsplits = INT_MAX;
	if (is_convex_set(set, NULL))
		return (set[0]);
	i = -1;
	while (!poly[1].isused)
	{
		i = -1;
		while (set[++i].exist)
		{
			if (!set[i].isused)
			{
				poly[0] = get_polygon(set[i]);
				set_best_poly(poly, set, minrelation, &leastsplits);
			}
		}
		minrelation = (minrelation < 0.0000000000001) ? 0. : (float)minrelation / MINSCALE;
	}
	return (poly[1]);
}

int			create_tree_node(t_map *map, t_data data)
{
	if (!(map->tree.rootnode = malloc(sizeof(t_node) * 1)))
		return (ft_putstrreti_fd("Error\nCa veut pas malloc (map->tree.rootnode (build_tree.c))\n", 0, 0));
	return (parse_poly(map, data));
}

void		build_tree(t_node *node, t_polygon *set, t_player player, t_data data)
{
	int			side;
	int			counter[3];
	static int	i = 0;

	node->exist = 0;
	node->frontchild = malloc(sizeof(t_node) * 1);
	node->backchild = malloc(sizeof(t_node) * 1);
	if (is_convex_set(set, node))
		return ;
	ft_memseti(counter, 0, 3);
	node->splitter = choose_div_polygon(set);
	node->frontchild->set = malloc_frontset_child(set, node->splitter);
	node->backchild->set = malloc_backset_child(set, node->splitter);
	while (set[counter[0]].exist)
	{
		side = get_side(node->splitter, set[counter[0]]);
		if (side == FRONT || side == COINCIDING)
		{
			node->frontchild->set[counter[1]] = get_polygon(set[counter[0]]);
			counter[1]++;
		}
		else if (side == BACK)
		{
			node->backchild->set[counter[2]] = get_polygon(set[counter[0]]);
			counter[2]++;
		}
		else if (side == SPANNING)
		{
			split_polygon(set[counter[0]], node->splitter, &node->frontchild->set[counter[1]], &node->backchild->set[counter[2]]);
			counter[1]++;
			counter[2]++;
		}
		counter[0]++;
	}
	node->exist = 1;
	i++;
	build_tree(node->frontchild, node->frontchild->set, player, data);
	i++;
	build_tree(node->backchild, node->backchild->set, player, data);
}
