/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colinear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:24:12 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/17 17:22:52 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

bool			is_colinear(t_segment s1, t_segment s2)
{
	int		o1;
	int		o2;
	
	o1 = orientation(s1.p, s1.q, s2.p);
	o2 = orientation(s1.p, s1.q, s2.q);
	if (o1 == 0 && o2 == 0)
		return (true);
	return (false);
}
