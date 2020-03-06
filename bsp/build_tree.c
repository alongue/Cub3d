/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/06 12:57:05 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

# define MINSCALE 2 //2 car on parle ici du scale minimum donc le minimum pour n - 1 c 2 donc lorsqu'il y a n = 3 polygons (le pire cas combine au cas minimum)

void		set_ratio(int *nb, double *relation, t_polygon currentpoly, t_polygon *set)
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
			//printf("nb[0] (front) = %d\tet\tnb[1] (back) = %d\tet\tnb[2] (spanning) = %d\n", nb[0], nb[1], nb[2]);
			if (nb[0] <= nb[1] && nb[1] != 0)
				*relation = (double)nb[0] / nb[1];
			else if (nb[0] >= nb[1] && nb[0] != 0)
				*relation = (double)nb[1] / nb[0];
		}
}

void	set_best_poly(t_polygon *poly, t_polygon *set,
						double minrelation, int *leastsplits)
{
	int		nb[3];
	double	bestrelation;
	double	relation;
	int		i;

	i = -1;
	bestrelation = 0;
	relation = 0;
	ft_memseti(nb, 0, 3);
	set_ratio(nb, &relation, poly[0], set);
	printf("relation = %f\tet\tminrelation = %f\n*leastsplits = %d\nnb[0] = %d\tet\tnb[1] = %d\tet\tnb[2] = %d\n", relation, minrelation, *leastsplits, nb[0], nb[1], nb[2]);
	if (relation >= minrelation &&
		((nb[2] < *leastsplits) || (relation > bestrelation)))
	{
		*leastsplits = nb[2];
		bestrelation = relation;
		set_used_poly(set, &poly[0]);
		poly[1] = poly[0];
		//sleep(1);
		/*while (++i[1] != i[0])
			set[i[1]].isused = false;
		set[i[0]].isused = true;*/
	}
}

t_polygon	choose_div_polygon(t_polygon *set)
{
	t_polygon	poly[2]; //poly[0] --> currentpoly et poly[1] --> bestpoly
	int			i;
	double		minrelation;
	int			leastsplits;
	int			counter;


	counter = 0;
	poly[1].isused = false;
	minrelation = (is_pair(polysetlen(set))) ? (double)(polysetlen(set) / 2 - 1) / (polysetlen(set) / 2 + 1) : 1.;
	leastsplits = INT_MAX;
	if (is_convex_set(set))
		return (set[0]);
	i = 0;
	while (!poly[1].isused && set[i].exist)
	{
		while (set[i].exist)
		{
			if (!set[i].isused)
			{
				poly[0] = set[i];
				set_best_poly(poly, set, minrelation, &leastsplits);
			}
			i++;
		}
		printf("bestpoly is used ? %d\n", poly[1].isused);
		minrelation = minrelation / MINSCALE;
		i = 0;
	}
	counter = -1;
	i = -1;
	while (set[++i].exist)
		if (set[i].isused)
			counter = i;
	printf("best polygon is set[%d]\n", counter);
	return (poly[1]);
}

void		create_tree_node(t_map *map)
{
	map->tree.rootnode = malloc(sizeof(t_node) * 1);
	map->tree.rootnode->set = parse_poly(*map);
}

void		build_tree(t_node *node, t_polygon *set) //je laisse ces fonctions en suspens
{
	int			side;
	int			counter[3];
	t_polygon	*frontpolyset; // ne pas oublier de malloc ces 2 zigotos
	t_polygon	*backpolyset;
	static int	i = 0;

	if (is_convex_set(set))
	{
		printf("The set is convex\n");
		return ;
	}
	ft_memseti(counter, 0, 3);
	node->splitter = choose_div_polygon(set);
	node->frontchild = malloc(sizeof(t_node) * 1);
	frontpolyset = malloc_frontset_child(set, node->splitter);
	node->backchild = malloc(sizeof(t_node) * 1);
	backpolyset = malloc_backset_child(set, node->splitter);
	while (set[counter[0]].exist)
	{
		side = get_side(node->splitter, set[counter[0]]);	/*																										*/
		if (side == FRONT)									/*																										*/
		{
			frontpolyset[counter[1]++] = set[counter[0]];	/*										Peut-etre mettre												*/
			//printf("set[%d] se trouve devant\n", counter[0]);
		}
		else if (side == BACK)								/*										tout ca dans une												*/
		{
			backpolyset[counter[2]++] = set[counter[0]];	/*											fonction													*/
			//printf("set[%d] se trouve derriere\n", counter[0]);
		}
		else if (side == SPANNING)							/*																										*/
		{
			//printf("set[%d].segment.a.x = %d\tet\tset[%d].a.x = %d\tet\tset[%d].b.y = %d\tet\tset[%d].b.y = %d\n", counter[0], set[counter[0]].segment.a.x, counter[0], set[counter[0]].segment.a.y, counter[0], set[counter[0]].segment.b.x, counter[0], set[counter[0]].segment.b.y);
			split_polygon(set[counter[0]], node->splitter, &frontpolyset[counter[1]], &backpolyset[counter[2]]);/*													*/
			//printf("set[%d] se trouve devant et derriere\n", counter[0]);
		}
		//printf("frontsetlen = %d\tet\tbacksetlen = %d\n", polysetlen(frontpolyset), polysetlen(backpolyset));
		counter[0]++;
	}
	i++;
	printf("ca fait la %de boucle\n", i);
	sleep(1);
	build_tree(node->frontchild, frontpolyset);
	free(frontpolyset);
	i++;
	printf("ca fait la %deme boucle\n", i);
	sleep(1);
	build_tree(node->backchild, backpolyset);
	free(backpolyset);
}
