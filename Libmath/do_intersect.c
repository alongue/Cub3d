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

int	do_intersect(t_segment s1, t_segment s2)
{
	int		o1;
	int		o2;
	int		o3;
	int		o4;

	o1 = orientation(s1.a, s1.b, s2.a);
	o2 = orientation(s1.a, s1.b, s2.b);
	o3 = orientation(s2.a, s2.b, s1.a);
	o4 = orientation(s2.a, s2.b, s1.b);
	if (o1 != o2 && o3 != o4)
		return (1);
	if (o1 == COLINEAR && onsegment(s1.a, s2.a, s1.b))
		return (1);
	if (o2 == COLINEAR && onsegment(s1.a, s2.b, s1.b))
		return (1);
	if (o3 == COLINEAR && onsegment(s2.a, s1.a, s2.b))
		return (1);
	if (o4 == COLINEAR && onsegment(s2.a, s1.b, s2.b))
		return (1);
	return (0);
}
