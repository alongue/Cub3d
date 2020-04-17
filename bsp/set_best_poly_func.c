/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_best_poly_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:59:10 by alongcha          #+#    #+#             */
/*   Updated: 2020/03/10 15:08:03 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//tout se joue ici je crois

void	set_used_poly(t_polygon *set, t_polygon *current)
{
	int		i;

	i = 0;
	while (set[i].exist)
	{
		//if (set[i].isused)
			set[i].isused = false;
		printf("set[%d].segment.exist = %d\t\tet\t\tcurrent->segent.exist = %d\n", i, set[i].segment.exist, current->segment.exist);
		printf("set[%d].segment.a.x = %f\t\tset[%d].segment.a.y = %f\tset[%d].segment.b.x = %f\t\tset[%d].segment.b.y = %f\n", i, set[i].segment.a.x, i, set[i].segment.a.y, i, set[i].segment.b.x, i, set[i].segment.b.y);
		printf("current->segment.a.x = %f\tcurrent->segment.a.y = %f\tcurrent->segment.b.x = %f\tcurrent->segment.b.y = %f\n", current->segment.a.x, current->segment.a.y, current->segment.b.x, current->segment.b.y);
		if (is_same_segment(set[i].segment, current->segment))
		{
			set[i].isused = true;
			current->isused = true;
		}
		i++;
	}
}
