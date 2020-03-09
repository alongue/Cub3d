/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/09 16:12:49 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

# define MINSCALE 2 //2 car on parle ici du scale minimum donc le minimum pour n - 1 c 2 donc lorsqu'il y a n = 3 polygons (le pire cas combine au cas minimum)

void		set_ratio(int *nb, float *relation, t_polygon currentpoly, t_polygon *set)
{
	int	i;
	int	side;

	i = -1;
	while (set[++i].exist)
		if (!is_same_segment(set[i].segment, currentpoly.segment))
		{
			side = get_side(currentpoly, set[i]);
			if (side == FRONT) // jsp ou mettre COINCIDING du coup
				nb[0] += 1;
			else if (side == BACK)
				nb[1] += 1;
			else if (side == SPANNING)
				nb[2] += 1;
			//printf("nb[0] (front) = %d\tet\tnb[1] (back) = %d\tet\tnb[2] (spanning) = %d\n", nb[0], nb[1], nb[2]);
			if (nb[0] <= nb[1] && nb[1] != 0)
				*relation = (float)nb[0] / nb[1];
			else if (nb[0] >= nb[1] && nb[0] != 0)
				*relation = (float)nb[1] / nb[0];
		}
}

void	set_best_poly(t_polygon *poly, t_polygon *set,
						float minrelation, int *leastsplits)
{
	int		nb[3];
	float	bestrelation;
	float	relation;
	int		i;

	i = -1;
	bestrelation = 0.;
	relation = 0.;
	ft_memseti(nb, 0, 3);
	set_ratio(nb, &relation, poly[0], set);
	//printf("relation = %f\tet\tminrelation = %f\n*leastsplits = %d\nnb[0] = %d\tet\tnb[1] = %d\tet\tnb[2] = %d\n", relation, minrelation, *leastsplits, nb[0], nb[1], nb[2]);
	printf("*leastsplits = %d\n", *leastsplits);
	if (relation >= minrelation &&
		((nb[2] < *leastsplits) || (relation > bestrelation)))
	{
		*leastsplits = nb[2];
		bestrelation = relation;
		set_used_poly(set, &poly[0]);
		poly[1] = dup_polygon(poly[0]);
		printf("relation = %f\tet\tpoly[0].isused = %d\n", relation, poly[0].isused);
		if (relation == 0)
			sleep(4);
		//printf("poly[0].isused = %d\n", poly[0].isused);
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
	float		minrelation;
	int			leastsplits;
	int			counter;


	counter = 0;
	poly[1].isused = false;
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
				poly[0] = dup_polygon(set[i]);
				set_best_poly(poly, set, minrelation, &leastsplits);
				printf("bestpoly is used ? %d, cuz set[%d].isused = %d\tet\tset de len = %d\n", poly[1].isused, i, set[i].isused, polysetlen(set));
				if (minrelation == 0)
					sleep(5);
			}
		}
		printf("TOUR SUIVANT\n");
		minrelation = (minrelation < 0.00000001) ? 0. : minrelation / MINSCALE;
	}
	counter = -1;
	i = -1;
	while (set[++i].exist)
		if (set[i].isused)
			counter = i;
	printf("best polygon is set[%d]\n", counter);
	return (poly[1]);
}

void		create_tree_node(t_map *map, t_player player)
{
	map->tree.rootnode = malloc(sizeof(t_node) * 1);
	map->tree.rootnode->set = parse_poly(*map, player);
	printf("polysetlen(set de tree) = %d\n", polysetlen(map->tree.rootnode->set));
}

void		build_tree(t_node *node, t_polygon *set, t_player player) //je laisse ces fonctions en suspens
{
	int			side;
	int			counter[3];
	t_polygon	*frontpolyset; // ne pas oublier de malloc ces 2 zigotos
	t_polygon	*backpolyset;
	static int	i = 0;

	node->exist = false;
	node->frontchild = malloc(sizeof(t_node) * 1);
	node->backchild = malloc(sizeof(t_node) * 1);
	int	a;
	a = -1;
	while (set[++a].exist) //afficher tous les segments 1 par 1 avec un sleep 
	{
		printf("set[%d].segment.a.x = %f\tset[%d].segment.a.y = %f\tset[%d].segment.b.x = %f\tset[%d].segment.b.y = %f\n", a, round((float)set[a].segment.a.x / 64), a, round((float)set[a].segment.a.y / 64), a, round((float)set[a].segment.b.x / 64), a, round((float)set[a].segment.b.y / 64));
		if (i == 1923)
			sleep(100);
	}
	if (is_convex_set(set, node))
	{
		printf("The set is convex\n");
		return ;
	}
	ft_memseti(counter, 0, 3);
	printf("set len = %d\n", polysetlen(set));
	node->splitter = choose_div_polygon(set);
	frontpolyset = malloc_frontset_child(set, node->splitter);
	backpolyset = malloc_backset_child(set, node->splitter);
	while (set[counter[0]].exist/* && set[counter[0]].segment.exist*/)
	{
		side = get_side(node->splitter, set[counter[0]]);	/*																										*/
		if (side == FRONT)									/*																										*/
		{
			frontpolyset[counter[1]] = dup_polygon(set[counter[0]]);	/*										Peut-etre mettre												*/
			
			//frontpolyset[counter[1]].isused = false;
			counter[1]++;
			//printf("set[%d] se trouve devant\n", counter[0]);
		}
		else if (side == BACK)								/*										tout ca dans une												*/
		{
			backpolyset[counter[2]] = dup_polygon(set[counter[0]]);	/*											fonction													*/
			//backpolyset[counter[2]].isused = false;
			counter[2]++;
			//printf("set[%d] se trouve derriere\n", counter[0]);
		}
		else if (side == SPANNING)							/*																										*/
		{
			//printf("set[%d].segment.a.x = %d\tet\tset[%d].a.x = %d\tet\tset[%d].b.y = %d\tet\tset[%d].b.y = %d\n", counter[0], set[counter[0]].segment.a.x, counter[0], set[counter[0]].segment.a.y, counter[0], set[counter[0]].segment.b.x, counter[0], set[counter[0]].segment.b.y);
			split_polygon(set[counter[0]], node->splitter, &frontpolyset[counter[1]], &backpolyset[counter[2]]);/*													*/
			//printf("set[%d] se trouve devant et derriere\n", counter[0]);
			counter[1]++;
			counter[2]++;
		}
		//printf("frontsetlen = %d\tet\tbacksetlen = %d\n", polysetlen(frontpolyset), polysetlen(backpolyset));
		counter[0]++;
	}
	node->exist = true;
	i++;
	printf("ca fait la %de boucle\n", i);
	//sleep(1);
	//free(set);
	build_tree(node->frontchild, frontpolyset, player);
	//free(frontpolyset);
	i++;
	printf("ca fait la %deme boucle\n", i);
	//sleep(1);
	build_tree(node->backchild, backpolyset, player);
	//free(backpolyset);
}
