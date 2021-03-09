/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_best_poly_func.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:59:10 by alongcha          #+#    #+#             */
/*   Updated: 2021/03/08 21:02:12 by alongcha         ###   ########.fr       */
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
			set[i].isused = 0;
		if (is_same_segment(set[i].segment, current->segment))
		{
			set[i].isused = 1;
			current->isused = 1;
		}
		i++;
	}
}
