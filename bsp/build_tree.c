/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 17:55:09 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

# define MINSCALE 2 //2 car on parle ici du scale minimum donc le minimum pour n - 1 c 2 donc lorsqu'il y a n = 3 polygons (le pire cas combine au cas minimum)

void		set_ratio(int *nb, double *relation, int side)
{
	if (side == FRONT)
		nb[0] += 1;
	else if (side == BACK)
		nb[1] += 1;
	else if (side == SPANNING)
		nb[2] += 1;
	printf("nb[0] (front) = %d\tet\tnb[1] (back) = %d\tet\tnb[2] (spanning) = %d\n", nb[0], nb[1], nb[2]);
	if (nb[0] <= nb[1] && nb[1] != 0)
		*relation = (double)nb[0] / nb[1];
	else if (nb[0] >= nb[1] && nb[0] != 0)
		*relation = (double)nb[1] / nb[0];
}

t_polygon	get_best_poly(t_polygon currentpoly, t_polygon *set,
						double minrelation, int counterused)
{
	int		nb[3];
	int		leastsplits;
	double	bestrelation;
	double	relation;
	int		i;

	i = -1;
	ft_memseti(nb, 0, 3);
	leastsplits = INT_MAX;
	bestrelation = 0;
	relation = 0;
	while (set[++i].exist && !is_same_segment(set[i].segment, currentpoly.segment))
	{
		set_ratio(nb, &relation, get_side(currentpoly, set[i]));
		printf("relation = %f\tet\tleastsplits = %d\n", relation, leastsplits);
		if (relation >= minrelation &&
			((nb[2] < leastsplits) || (relation > bestrelation)))
		{
			leastsplits = nb[2];
			bestrelation = relation;
			set_used_poly(set, currentpoly, counterused);
			/*while (++i[1] != i[0])
				set[i[1]].isused = false;
			set[i[0]].isused = true;*/
		}
	}
	return (currentpoly);
}

t_polygon	choose_div_polygon(t_polygon *set, int counterused)
{
	t_polygon	bestpoly;
	int			i;
	double		minrelation;
	int			len;
	int			counter;

	counter = 0;
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
			{
				bestpoly = get_best_poly(set[i], set, minrelation, counterused);
				counter = i;
			}
			printf("set[%d].isused = %d\n", i, set[i].isused);
			i++;
		}
		minrelation = minrelation / MINSCALE;
	}
	printf("best polygon is : set[%d]\n", counter);
	return (bestpoly);
}

void		create_tree_node(t_map *map)
{
	map->tree.rootnode = malloc(sizeof(t_node) * 1);
	map->tree.rootnode->set = parse_poly(*map);
	map->tree.rootnode->splitter = choose_div_polygon(map->tree.rootnode->set, 1);
}

void		build_tree(t_node *node, t_polygon *set) //je laisse ces fonctions en suspens
{
	int			side;
	static int	i = 2;
	int			counter[3];
	t_polygon	*frontpolyset; // ne pas oublier de malloc ces 2 zigotos
	t_polygon	*backpolyset;

	if (is_convex_set(set))
		return ;
	ft_memseti(counter, 0, 3);
	node->splitter = choose_div_polygon(set, i);
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
		printf("frontsetlen = %d\tet\tbacksetlen = %d\n", polysetlen(frontpolyset), polysetlen(backpolyset));
		counter[0]++;
	}
	i++;
	build_tree(node->frontchild, frontpolyset);
	free(frontpolyset);
	i++; // je crois qu'il faut pas le mettre lui
	build_tree(node->backchild, backpolyset);
	free(backpolyset);
}
