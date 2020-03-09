/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   orientation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alongcha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 13:28:54 by alongcha          #+#    #+#             */
/*   Updated: 2020/02/16 11:42:23 by alongcha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"

int		orientation(t_point p, t_point q, t_point r)
{
	int	val;

	val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
	if (val == 0)
		return (COLINEAR);
	return ((val > 0) ? CLOCKWISE : COUNTERCLOCKWISE);
}
