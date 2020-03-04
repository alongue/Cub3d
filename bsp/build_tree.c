/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 11:54:32 by alongcha         ###   ########.fr       */
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
	//printf("nb[0] = %d\tet\tnb[1] = %d\n", nb[0], nb[1]);
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
	double		minrelation;
	int			len;

	bestpoly.exist = false;
	len = polysetlen(set);
	minrelation = (is_pair(len)) ? (double)(len / 2 - 1) / (len / 2 + 1) : 1.;
	if (is_convex_set(set))
		return (set[0]);
	i = 0;
	while (!bestpoly.exist && set[i].exist)
	{
		while (set[i].exist)
		{
			if (!set[i].isused)
				set_best_poly(&bestpoly, set[i], set, minrelation);
			i++;
		}
		minrelation = minrelation / MINSCALE;
	}
	printf("best polygon is : set[%d]\n", i);
	return (bestpoly);
}

void		create_tree_node(t_map *map)
{
	map->tree.rootnode = malloc(sizeof(t_node) * 1);
	map->tree.rootnode->set = parse_poly(*map);
	map->tree.rootnode->splitter = choose_div_polygon(map->tree.rootnode->set);
}

void		build_tree(t_node *node, t_polygon *set) //je laisse ces fonctions en suspens
{
	int			side;
	int			counter[3];
	t_polygon	*frontpolyset; // ne pas oublier de malloc ces 2 zigotos
	t_polygon	*backpolyset;

	if (is_convex_set(set))
		return ;
	ft_memseti(counter, 0, 3);
	node->splitter = choose_div_polygon(set);
	frontpolyset = malloc_frontset_child(set, node->splitter);
	backpolyset = malloc_backset_child(set, node->splitter);
	while (set[counter[0]].exist)
	{
		side = get_side(node->splitter, set[counter[0]]);	/*																										*/
		if (side == FRONT)									/*																										*/
			frontpolyset[counter[1]++] = set[counter[0]];	/*										Peut-etre mettre												*/
		else if (side == BACK)								/*										tout ca dans une												*/
			backpolyset[counter[2]++] = set[counter[0]];	/*											fonction													*/
		else if (side == SPANNING)							/*																										*/
			split_polygon(set[counter[0]], node->splitter, &frontpolyset[counter[1]], &backpolyset[counter[2]]);/*													*/
		counter[0]++;
	}
	build_tree(node->frontchild, frontpolyset);
	free(frontpolyset);
	build_tree(node->backchild, backpolyset);
	free(backpolyset);
}
