/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_colinear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:24:12 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/29 16:23:59 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

bool	is_colinear(t_segment s1, t_segment s2)
{
	int		o1;
	int		o2;

	o1 = orientation(s1.a, s1.b, s2.a);
	o2 = orientation(s1.a, s1.b, s2.b);
	if (o1 == 0 && o2 == 0)
		return (true);
	return (false);
}
