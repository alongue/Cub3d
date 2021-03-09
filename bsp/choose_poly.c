/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choose_poly.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 23:00:32 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/09 23:00:34 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

#define MINSCALE 2
#define FMIN 0.0000000000001

void		set_ratio(int *nb, float *relation,
t_polygon currentpoly, t_polygon *set)
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
	minrelation = (is_pair(polysetlen(set))) ?
	(float)(polysetlen(set) / 2 - 1) / (polysetlen(set) / 2 + 1) : 1.;
	leastsplits = INT_MAX;
	if (is_convex_set(set, NULL))
		return (set[0]);
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
		minrelation = (minrelation < FMIN) ? 0. : (float)minrelation / MINSCALE;
	}
	return (poly[1]);
}
