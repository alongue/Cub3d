/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_tree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 22:06:15 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 03:37:12 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

# define MINSCALE qqch

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
	float		minscale;
	int			len;

	len = polysetlen(set);
	minrelation = (ispair(len)) ? (len / 2 - 1) / (len / 2 + 1) : 1;
	//minscale = (n - 1 > 2.) ? n - 1 : 2.;
	minscale = 2.; //je comprends tjrs pas pk faut que je fasse la masse de tests pour comprendre ce qui se passe
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

void		buil_tree(t_node node)
{
	t_tree	tree;

	if (is_convex_set(node.set))
}
