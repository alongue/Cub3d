/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 10:38:56 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/14 14:45:46 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

bool	do_intersect(t_segment s1, t_segment s2)
{
	int		o1;
	int		o2;
	int		o3;
	int		o4;

	o1 = orientation(s1.p, s1.q, s2.p);
	o2 = orientation(s1.p, s1.q, s2.q);
	o3 = orientation(s2.p, s2.q, s1.p);
	o4 = orientation(s2.p, s2.q, s1.q);
	if (o1 != o2 && o3 != o4)
		return (true);
	if (o1 == COLINEAR && onsegment(s1.p, s2.p, s1.q))
		return (true);
	if (o2 == COLINEAR && onsegment(s1.p, s2.q, s1.q))
		return (true);
	if (o3 == COLINEAR && onsegment(s2.p, s1.p, s2.q))
		return (true);
	if (o4 == COLINEAR && onsegment(s2.p, s1.q, s2.q))
		return (true);
	return (false);
}
