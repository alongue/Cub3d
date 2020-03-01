/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/01 19:01:10 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

# define MINSCALE 2 //2 car on parle ici du scale minimum donc le minimum pour n - 1 c 2 donc lorsqu'il y a n = 3 polygons (le pire cas combine au cas minimum)

void		set_ratio(int *nb, int *relation, int side)
{
	if (side == FRONT)
		nb[0] += 1;
	else if (side == BACK)
		nb[1] += 1;
	else if (side == SPANNING)
		nb[2] += 1;
	if (nb[0] < nb[1])
		*relation = nb[0] / nb[1];
	else
		*relation = nb[1] / nb[0];
}

void		set_best_poly(t_polygon *bestpoly, t_polygon currentpoly,
						  t_polygon *set, float minrelation)
{
	int		nb[3];
	int		leastsplits;
	int		bestrelation;
	int		relation;

	ft_memseti(nb, 0, 3);
	leastsplits = INT_MAX;
	bestrelation = 0;
	relation = 0;
	while (set->exist && !is_same_segment(set->segment, currentpoly.segment))
	{
		set_ratio(nb, &relation, get_side(currentpoly, *set));
		if (relation >= minrelation &&
			((nb[2] < leastsplits) || (relation > bestrelation)))
		{
			set->isused = true;
			bestpoly->exist = true;
			bestpoly->segment = dup_segment(currentpoly.segment);
			leastsplits = nb[2];
			bestrelation = relation;
		}
		set++;
	}
}

t_polygon	choose_div_polygon(t_polygon *set)
{
	t_polygon	bestpoly;
	int			i;
	float		minrelation;
	int			len;

	bestpoly.exist = true;
	len = polysetlen(set);
	minrelation = (is_pair(len)) ? (len / 2 - 1) / (len / 2 + 1) : 1;
	if (is_convex_set(set))
		return (set[0]);
	i = -1;
	while (!bestpoly.exist && !set[i].exist)
	{
		while (set[++i].exist)
			if (!set[i].isused)
				set_best_poly(&bestpoly, set[i], set, minrelation);
		minrelation = minrelation / MINSCALE;
	}
	return (bestpoly);
}

void		create_tree_node(t_map *map)
{
	parse_poly(map);
	map->tree.rootnode->splitter = choose_div_polygon(node->set);
}

void		build_tree(t_node *node, t_polygon *set) //je laisse ces fonctions en suspens
{
	int			side;
	int			counter[3];
	t_polygon	*frontpolyset;
	t_polygon	*backpolyset;

	ft_memseti(counter, 0, 3);
	node->splitter = choose_div_polygon(node->set);
	while (node->set[counter[0]])
	{
		side = get_side(splitter, node->set[counter[0]]);
		if (side == FRONT)
			frontpolyset[counter[1]++] = set[counter[0]];
		else if (side == BACK)
			backpolyset[counter[2]++] = set[counter[0]];
		else if (side == SPANNING)
			split_polygon(set[counter[0]], node, frontpolyset, backpolyset); //je laisse ces fonctions en suspens
		counter[0]++;
	}
	build_tree(node->frontchild);
	build_tree(node->backchild);
}
