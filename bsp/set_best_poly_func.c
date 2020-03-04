/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_best_poly_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:59:10 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/04 17:56:08 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	set_used_poly(t_polygon *set, t_polygon current, int counterused)
{
	int		len;
	int		i;

	(void)counterused;
	len = polysetlen(set);
	i = -1;
	while (set[++i].exist)
	{
		if (set[i].isused)
			set[i].isused = false;
		if (is_same_segment(set[i].segment, current.segment))
			set[i].isused = true;
	}
}
