/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 07:59:27 by alongcha         ###   ########.fr       */
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
		nb[3] += 1;
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
	while (*s && *s != currentpoly)
	{
		set_ratio(nb, &relation, get_side(currentpoly, *s));
		if (relation >= minrelation &&
			((nb[3] < leastsplits) || (relation > bestrelation)))
		{
			s->isused = true;
			bestpoly = s;
			leastsplits = nb[3];
			bestrelation = relation;
		}
		s++;
	}
}

t_polygon	choose_div_polygon(t_polygon *set)
{
	t_polygon	*bestpoly;
	int			i;
	float		minrelation;
	int			len;

	len = polysetlen(set);
	minrelation = (ispair(len)) ? (len / 2 - 1) / (len / 2 + 1) : 1;
	if (is_convex_set(set))
		return (set[0]);
	i = -1;
	while (!bestpoly && !set[i])
	{
		while (set[++i])
			if (!set[i].isused)
				set_best_poly(bestpoly, set[i], minrelation);
		minrelation = minrelation / minscale;
	}
}

void		build_tree(t_node *node, t_polygon *set) //je laisse ces fonctions en suspens
{
	int			side;
	int			counter[3];
	t_polygon	*frontpolyset
	t_polygon	*backpolyset

	if (is_convex_set(node->set))
		/*qqch*/;
	ft_memseti(counter, 0, 3);
	node->splitter = choose_div_polygon(node->set);
	i = -1;
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
